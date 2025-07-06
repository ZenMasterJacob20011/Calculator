#include <iostream>
#include <SFML/Graphics.hpp>
#include "Button.hpp"
#include "Sprites.hpp"

void handleMouseEvent(const sf::Event::MouseButtonPressed &mouse_button_pressed,
                      const std::vector<std::vector<Button> > &buttons) {
    //Loop through the buttons and check if the mouse button pressed coordinates fall inbetween button area
    if (mouse_button_pressed.button == sf::Mouse::Button::Left) {
        for (const std::vector<Button> &button_rows: buttons) {
            for (Button button: button_rows) {
                if (button.isPointInside(mouse_button_pressed.position.x, mouse_button_pressed.position.y)) {
                    button.action();
                }
            }
        }
    }
}

int main() {
    constexpr float window_width = 500;
    constexpr float window_height = 900;
    constexpr float button_width = window_width / 4;
    constexpr float button_height = window_height / 9;
    sf::RenderWindow window(sf::VideoMode({static_cast<int>(window_width), static_cast<int>(window_height)}),
                            "SFML window");
    constexpr int rows = 6;
    constexpr int cols = 4;
    float topOffset = window_height - button_height * 6;
    std::vector<std::vector<Button> > buttons;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            buttons.emplace_back();
            Button button(textures_name[i][j], textures[i][j], j * (window_width / 4),
                          topOffset + i * (window_height / 9), window_width / 4,
                          window_height / 9);
            buttons[i].emplace_back(button);
        }
    }
    while (window.isOpen()) {
        window.clear();
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            } else if (const auto *mouse_button_pressed = event->getIf<sf::Event::MouseButtonPressed>()) {
                handleMouseEvent(*mouse_button_pressed, buttons);
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                window.draw(buttons[i][j]);
            }
        }
        // window.draw(b);
        window.display();
    }
    return 0;
}

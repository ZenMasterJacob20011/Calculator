#include <SFML/Graphics.hpp>
#include "Button.cpp"
#include "Sprites.cpp"

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
    std::vector<std::vector<Button>> buttons;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            buttons.emplace_back();
            Button button(textures[i][j], j * (window_width / 4), topOffset + i * (window_height / 9), window_width / 4,
                          window_height / 9);
            buttons[i].emplace_back(button);
        }
    }
    // const sf::Font font("arial.ttf");
    // sf::Text text(font, "1");
    // text.setCharacterSize(30);
    // text.setStyle(sf::Text::Bold);
    // text.setFillColor(sf::Color::Red);
    // button.text = text;
    while (window.isOpen()) {
        window.clear();
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
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

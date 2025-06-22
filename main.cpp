#include <iostream>
#include <SFML/Graphics.hpp>
constexpr float window_width = 500;
constexpr float window_height = 900;
constexpr float button_width = window_width / 4;
constexpr float button_height = window_height / 9;
sf::RectangleShape create_rectangle(float posX, float posY) {
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(window_width / 4, window_height / 9));
    rectangle.setOutlineColor(sf::Color::Red);
    rectangle.setOutlineThickness(1);
    rectangle.setPosition({posX, posY});
    return rectangle;
}

int main() {
    sf::RenderWindow window(sf::VideoMode({static_cast<int>(window_width), static_cast<int>(window_height)}), "SFML window");
    constexpr int rows = 6;
    constexpr int cols = 4;
    sf::RectangleShape rectangles[6][4];
    float topOffset = window_height - button_height * 6;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            rectangles[i][j] = create_rectangle(button_width * (j),
                                                topOffset + button_height * (i));
        }
    }
    while (window.isOpen()) {
        window.clear();
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
                return 0;
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                window.draw(rectangles[i][j]);
            }
        }
        window.display();
    }
}

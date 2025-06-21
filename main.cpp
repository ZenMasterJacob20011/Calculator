#include <iostream>
#include <SFML/Graphics.hpp>

sf::RectangleShape create_rectangle(float posX, float posY) {
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(20, 20));
    rectangle.setOutlineColor(sf::Color::Red);
    rectangle.setOutlineThickness(1);
    rectangle.setPosition({posX, posY});
    return rectangle;
}

int main() {
    sf::RenderWindow window(sf::VideoMode({500, 900}), "SFML window");
    int rows = 6;
    int cols = 4;
    sf::RectangleShape rectangles[6][4];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            rectangles[i][j] = create_rectangle( 20 * (j + 1), 20 * (i + 1));
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

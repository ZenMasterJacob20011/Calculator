#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
    std::cout << "Hello, World!" << std::endl;
    sf::Vertex vertices[]
    {
        {{  0.0f,   100.0f}, sf::Color::Red, { 0.0f,  100.0f}},
        {{  0.0f, 100.0f}, sf::Color::Red, { 0.0f, 100.0f}},
        {{100.0f, 100.0f}, sf::Color::Red, {10.0f, 10.0f}},
        {{  0.0f,   100.0f}, sf::Color::Red, { 0.0f,  0.0f}},
    };
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML window");
    window.draw(vertices, 4, sf::PrimitiveType::Lines);
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
                return 0;
            }
        }

        window.display();
    }
}

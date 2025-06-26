#include <iostream>
#include <SFML/Graphics.hpp>

class Button : public sf::Drawable {
public:
    Button(sf::Font &font, std::string symbol, float pos_x, float pos_y, float width, float height): text(font, symbol) {
        text.setFillColor(sf::Color::Red);
        rectangle.setSize(sf::Vector2f(width, height));
        rectangle.setOutlineColor(sf::Color::Red);
        rectangle.setOutlineThickness(1);
        rectangle.setPosition({pos_x, pos_y});
        int textWidth = text.getLocalBounds().size.x;
        int textHeight = text.getLocalBounds().size.y;
        text.setPosition({pos_x + width / 2 - textWidth, pos_y + height / 2 - textHeight});
    }

private:
    sf::RectangleShape rectangle;
    sf::Text text;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override {
        target.draw(rectangle, states);
        target.draw(text, states);
    }
};

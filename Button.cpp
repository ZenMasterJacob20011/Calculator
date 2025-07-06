#include <SFML/Graphics.hpp>
#include "Button.hpp"


Button::Button(const Symbol &name, const sf::Texture &t_symbol, float pos_x, float pos_y, float width,
       float height): symbol(t_symbol) {
    this->name = name;
    rectangle.setSize(sf::Vector2f(width, height));
    rectangle.setOutlineColor(sf::Color::Red);
    rectangle.setOutlineThickness(1);
    rectangle.setPosition({pos_x, pos_y});
    float symbol_x_offset = width / 2 - symbol.getGlobalBounds().size.x / 2;
    float symbol_y_offset = height / 2 - symbol.getGlobalBounds().size.y / 2;
    symbol.setPosition({pos_x + symbol_x_offset, pos_y + symbol_y_offset});
}

Button::Button(sf::Texture tmp_texture): symbol(tmp_texture) {
}

bool Button::isPointInside(float x, float y) const {
    const sf::RectangleShape rectangle = getRectangle();
    const float rectangle_width = rectangle.getSize().x;
    const float rectangle_height = rectangle.getSize().y;
    const float rectangle_start_x = rectangle.getPosition().x;
    const float rectangle_end_x = rectangle_start_x + rectangle_width;
    const float rectangle_start_y = rectangle.getPosition().y;
    const float rectangle_end_y = rectangle_start_y + rectangle_height;
    return x >= rectangle_start_x && x <= rectangle_end_x && y >= rectangle_start_y && y <= rectangle_end_y;
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(rectangle, states);
    target.draw(symbol);
}

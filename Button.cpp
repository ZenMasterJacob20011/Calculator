#include <SFML/Graphics.hpp>
#include "Button.hpp"


Button::Button(const sf::Texture &t_symbol, float pos_x, float pos_y, float width,
       float height): symbol(t_symbol) {
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

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(rectangle, states);
    target.draw(symbol);
}

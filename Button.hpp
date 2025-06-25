#pragma once
#include <iostream>

#include "SFML/Graphics/Drawable.hpp"
#include <SFML/Graphics/RectangleShape.hpp>

class Button : public sf::Drawable {
public:
    sf::RectangleShape rectangle;
    // sf::Text text;
    // sf::Font font;
    // std::string symbol;
    // Button(): text(font, symbol){}
private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override {
        std::cout << "hi from hpp";
    };
};

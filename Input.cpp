#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <vector>
#include "Input.hpp"


Input::Input(float value, sf::Sprite &drawable_input, float window_width, float window_height) {
    this->value = value;
    drawable_input.setPosition({
        window_width - drawable_input.getGlobalBounds().size.x,
        ((window_height - 600) / 2) - drawable_input.getGlobalBounds().size.y / 2
    });
    this->drawable_input.emplace_back(drawable_input);
}

void Input::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for (int i = 0; i < this->drawable_input.size(); i++) {
        target.draw(this->drawable_input[i], states);
    }
}

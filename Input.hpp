#pragma once

class Input : public sf::Drawable {
public:
    Input(float value, sf::Sprite &drawable_input);

    float get_value() const {
        return value;
    }

private:
    float value;
    std::vector<sf::Sprite> drawable_input;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

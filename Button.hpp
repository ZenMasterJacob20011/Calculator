#ifndef BUTTON_H
#define BUTTON_H
class Button : public sf::Drawable {
public:

    Button(const sf::Texture &t_symbol, float pos_x, float pos_y, float width, float height);

    Button(sf::Texture tmp_texture);

private:
    sf::RectangleShape rectangle;
    sf::Sprite symbol;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
#endif

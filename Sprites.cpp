#include "SFML/Graphics/Texture.hpp"
#include "Sprites.hpp"
sf::Texture percent("icons/percentage.png");
sf::Texture ce("icons/ce.png");
sf::Texture c("icons/c.png");
sf::Texture backspace("icons/backspace.png");
sf::Texture one_over_x("icons/oneoverx.png");
sf::Texture x_squared("icons/x2.png");
sf::Texture square_root_x("icons/square-root-of-x-mathematical-signs.png");
sf::Texture divide("icons/divide.png");
sf::Texture multiply("icons/x.png");
sf::Texture plus_over_minus("icons/plus-minus.png");
sf::Texture dot("icons/dot.png");
sf::Texture equal("icons/equal.png");
sf::Texture minus("icons/minus.png");
sf::Texture plus("icons/plus.png");
sf::Texture zero("icons/zero.png");
sf::Texture one("icons/one.png");
sf::Texture two("icons/two.png");
sf::Texture three("icons/three.png");
sf::Texture four("icons/four.png");
sf::Texture five("icons/five.png");
sf::Texture six("icons/6.png");
sf::Texture seven("icons/seven.png");
sf::Texture eight("icons/eight.png");
sf::Texture nine("icons/9.png");

enum class Symbol {
    Percent,
    CE,
    C,
    Backspace,
    OneOverX,
    XSquared,
    SquareRootX,
    Divide,
    Multiply,
    PlusOverMinus,
    Dot,
    Equal,
    Minus,
    Plus,
    Zero,
    One,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine
};

sf::Texture textures[6][4] = {
    {percent, ce, c, backspace},
    {one_over_x, x_squared, square_root_x, divide},
    {seven, eight, nine, multiply},
    {four, five, six, minus},
    {one, two, three, plus},
    {plus_over_minus, zero, dot, equal}
};

Symbol textures_name[6][4] = {
    {Symbol::Percent, Symbol::CE, Symbol::C, Symbol::Backspace},
    {Symbol::OneOverX, Symbol::XSquared, Symbol::SquareRootX, Symbol::Divide},
    {Symbol::Seven, Symbol:: Eight, Symbol::Nine, Symbol::Multiply},
    {Symbol::Four, Symbol::Five, Symbol::Six, Symbol::Minus},
    {Symbol::One, Symbol::Two, Symbol::Three, Symbol::Plus},
    {Symbol::PlusOverMinus, Symbol::Zero, Symbol::Dot, Symbol::Equal}
};
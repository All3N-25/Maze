#include "../Headers/Wall.hpp"


Wall::Wall(int row, int col, int size, bool top, bool left, bool bot, bool right)
    : row(row), col(col), size(size), top(top), left(left), bot(bot), right(right)
{

}

void Wall::Draw_Wall_Step(sf::RenderWindow& window)
{
    // recompute geometry every frame (cheap)
    top_wall.setSize(sf::Vector2f((float)size, 2.f));
    top_wall.setPosition((float)(col * size), (float)(row * size));
    top_wall.setFillColor(sf::Color::White);

    left_wall.setSize(sf::Vector2f(2.f, (float)size));
    left_wall.setPosition((float)(col * size), (float)(row * size));
    left_wall.setFillColor(sf::Color::White);

    bot_wall.setSize(sf::Vector2f((float)size, 2.f));
    bot_wall.setPosition((float)(col * size), (float)((row + 1) * size));
    bot_wall.setFillColor(sf::Color::White);

    right_wall.setSize(sf::Vector2f(2.f, (float)size));
    right_wall.setPosition((float)((col + 1) * size), (float)(row * size));
    right_wall.setFillColor(sf::Color::White);

    if (top)  window.draw(top_wall);
    if (left) window.draw(left_wall);
    if (bot)  window.draw(bot_wall);
    if (right)window.draw(right_wall);
}

void Wall::Set_Top(bool value)
{
    top = value;
}

void Wall::Set_Left(bool value)
{
    left = value;
}

void Wall::Set_Bot(bool value)
{
    bot = value;
}

void Wall::Set_Right(bool value)
{
    right = value;
}

bool Wall::Get_Top()
{
    return top;
}
bool Wall::Get_Left()
{
    return left;
}
bool Wall::Get_Bot()
{
    return bot;
}
bool Wall::Get_Right()
{
    return right;
}
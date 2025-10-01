#include "../Headers/Wall.hpp"

Wall::Wall(int row, int col, int size, bool top, bool left, bool bot, bool right)
{
    this->row = row;
    this->col = col;
    this->size = size;

    this->top = top;
    this->left = left;
    this->bot = bot;
    this->right = right;
    

    Initialize_Wall(row, col, size, top, left, bot, right);
}

void Wall::Initialize_Wall(int row, int col, int size, bool top, bool left, bool bot, bool right)
{
    if (top)
    {
        top_wall.setSize(sf::Vector2f(size, 2.f));
        top_wall.setPosition(col * size, row * size);
        top_wall.setFillColor(sf::Color::White);
    }
    if (left)
    {
        left_wall.setSize(sf::Vector2f(2.f, size));
        left_wall.setPosition(col * size, row * size);
        left_wall.setFillColor(sf::Color::White);
    }
    if (bot)
    {
        bot_wall.setSize(sf::Vector2f(size, 2.f));
        bot_wall.setPosition(col * size, (row + 1) * size);
        bot_wall.setFillColor(sf::Color::White);
    }
    if (right)
    {
        right_wall.setSize(sf::Vector2f(2.f, size));
        right_wall.setPosition((col + 1) * size, row * size);
        right_wall.setFillColor(sf::Color::White);
    }
}


void Wall::Draw_Wall(sf::RenderWindow& window)
{
    if (top) window.draw(top_wall);
    if (left) window.draw(left_wall);
    if (bot) window.draw(bot_wall);
    if (right) window.draw(right_wall);
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
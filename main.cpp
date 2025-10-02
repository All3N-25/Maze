#include <SFML/Graphics.hpp>
#include "Headers/Grid.hpp"
#include "Headers/Generator.hpp"

int main()
{
    const int WINDOW_W = 602;
    const int WINDOW_H = 602;

    const int rows = 30;
    const int cols = 30;
    const int cellSize = 20;

    sf::RenderWindow window(sf::VideoMode(WINDOW_W, WINDOW_H), "Maze (step-by-step)");
    window.setFramerateLimit(60);

    Grid grid(rows, cols, cellSize);
    Generator gen(grid, 14, 14);

    const int STEPS_PER_FRAME = 5;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed
                || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
            {
                window.close();
            }
        }

        // Step by step
        if (!gen.Is_Done())
        {
            for (int i = 0; i < STEPS_PER_FRAME && !gen.Is_Done(); ++i)
                gen.Step();
        }

        window.clear(sf::Color::Black);
        grid.Draw(window);

        // highlight current cell
        auto cur = gen.GetCurrent();
        if (cur.first >= 0)
        {
            sf::RectangleShape highlight(sf::Vector2f((float)cellSize - 2.f, (float)cellSize - 2.f));
            highlight.setPosition((float)(cur.second * cellSize + 1), (float)(cur.first * cellSize + 1));
            highlight.setFillColor(sf::Color(100, 200, 100, 120));
            window.draw(highlight);
        }

        window.display();
    }

    return 0;
}

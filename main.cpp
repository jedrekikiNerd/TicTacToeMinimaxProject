#include "Game.hpp"
#include <SFML/Graphics.hpp>

int main2()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}

int main()
{
    char a;
    Game TicTacToe_game_instance;
    TicTacToe_game_instance.start_game_loop_graphic();
    std::cout << "\nKONIEC GRY! Kliknij enter, aby wyjść! ";
    std::cin >> a;
    return 0;
}

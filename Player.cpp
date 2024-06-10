#include "Player.hpp"


bool Player::make_move()
{
    bool result = false;
    while(!result)
    {
        unsigned int row, col;
        std::cout << "Player " << get_symbol() << ", enter your move (row and column): ";
        std::cin >> row >> col;
        result = game_board->make_move(row, col, is_first);
        if (!result)
            std::cout << "INVALID MOVE! TRY AGAIN!\n";
    }
    
    return result;
}

bool Player::make_move_graphical(sf::RenderWindow* game_window, unsigned int cell_size)
{
    sf::Event event;
    while (game_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            game_window->close();
        else if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                unsigned int x = event.mouseButton.x;
                unsigned int y = event.mouseButton.y;

                unsigned int row = y / cell_size;
                unsigned int col = x / cell_size;

                return game_board->make_move(row+1, col+1, is_first);
            }
        }
    }
    return false;
}

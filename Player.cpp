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

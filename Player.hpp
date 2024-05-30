#ifndef PLAYER
#define PLAYER

#include <iostream>
#include "Board.hpp"


class Player
{
protected:
    bool is_first;
    Board* game_board;
    char symbol;

public:
    Player(bool first, Board* board) : is_first(first), game_board(board), symbol(first ? 'O' : 'X') {}

    virtual bool make_move();

    char get_symbol()
    {
        return symbol;
    }

    bool get_is_first()
    {
        return is_first;
    }
};

#endif

#ifndef PLAYER
#define PLAYER

#include <iostream>
#include "Board.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


class Player
{
protected:
    bool is_first;
    unsigned int cell_size;
    Board* game_board;
    char symbol;

public:
    Player(bool first, Board* board) : is_first(first), game_board(board), symbol(first ? 'O' : 'X') {}

    virtual bool make_move();

    virtual bool make_move_graphical(sf::RenderWindow* game_window, unsigned int cell_size);

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

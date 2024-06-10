#ifndef PLAYER_AI
#define PLAYER_AI

#include <iostream>
#include "Board.hpp"
#include "Player.hpp"


struct Move
{
    int row, col;
};

class PlayerAI : public Player
{
protected:
    unsigned int max_depth;
public:
    PlayerAI(bool first, Board* board) : max_depth(5), Player(first, board) {}
    PlayerAI(bool first, Board* board, unsigned int d) : max_depth(d), Player(first, board) {}

    bool make_move() override;

    bool make_move_graphical(sf::RenderWindow* game_window, unsigned int cell_size) override;

    int evaluate();

    int minimax(int depth, bool is_maximizing);

    Move find_best_move();
};

#endif

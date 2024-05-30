#include "AIPlayer.hpp"


bool PlayerAI::make_move()
{
    Move best_move = find_best_move();
    return game_board->make_move(best_move.row, best_move.col, is_first);
}

int PlayerAI::evaluate()
{
    if (game_board->check_win(is_first))
        return 100;
    else if (game_board->check_win(!is_first))
        return -100;
    return 0;
}

int PlayerAI::minimax(int depth, bool is_maximizing)
{
    int score = evaluate();

    // If Maximizer has won the game return his/her evaluated score
    if (score == 100) 
        return score - depth;

    // If Minimizer has won the game return his/her evaluated score
    if (score == -100) 
        return score + depth;

    // If there are no more moves and no winner then it is a tie
    if (game_board->no_more_fields()) 
        return 0;

    // If max depth then return score
    if (depth >= max_depth)
        return score;

    // We search for the best moves
    if (is_maximizing)
    {
        int best = -1000;

        for (unsigned int i = 1; i <= game_board->get_size(); i++)
        {
            for (unsigned int j = 1; j <= game_board->get_size(); j++)
            {
                if (game_board->make_move(i, j, is_first))
                {
                    best = std::max(best, minimax(depth + 1, false));
                    game_board->undo_move(i, j);
                }
            }
        }

        return best;
    }
    // Here we minimize opponent chance to win - we play moves as opponent and search for the worst move
    else
    {
        int best = 1000;

        for (unsigned int i = 1; i <= game_board->get_size(); i++)
        {
            for (unsigned int j = 1; j <= game_board->get_size(); j++)
            {
                if (game_board->make_move(i, j, !is_first))
                {
                    best = std::min(best, minimax(depth + 1, true));
                    game_board->undo_move(i, j);
                }
            }
        }
        return best;
    }
}

Move PlayerAI::find_best_move()
{
    int best_val = -1000;
    Move best_move;
    best_move.row = -1;
    best_move.col = -1;

    for (unsigned int i = 1; i <= game_board->get_size(); i++)
    {
        for (unsigned int j = 1; j <= game_board->get_size(); j++)
        {
            if (game_board->make_move(i, j, is_first))
            {
                int move_val = minimax(0, false);
                game_board->undo_move(i, j);

                if (move_val > best_val)
                {
                    best_move.row = i;
                    best_move.col = j;
                    best_val = move_val;
                }
            }
        }
    }
    return best_move;
}

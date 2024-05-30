#include "Game.hpp"


void Game::start_game_loop()
{
    bool current_player_first = true;
    while (true)
    {
        if (current_player_first == player1->get_is_first())
            current_player = player1;
        else
            current_player = player2;
        game_board->print_board();

        current_player->make_move();

        if (game_board->check_win(current_player->get_is_first()))
        {
            game_board->print_board();
            std::cout << "Player " << current_player->get_symbol() << " wins!" << std::endl;
            break;
        }

        if (game_board->no_more_fields())
        {
            game_board->print_board();
            std::cout << "It's a draw!" << std::endl;
            break;
        }

        current_player_first = !current_player_first;
    }
}

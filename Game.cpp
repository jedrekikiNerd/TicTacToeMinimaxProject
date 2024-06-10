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

void Game::start_game_loop_graphic()
{
    sf::RenderWindow window(sf::VideoMode(game_board->get_size()*cell_size, game_board->get_size()*cell_size), "Tic Tac Toe");
    bool current_player_first = true;
    while (window.isOpen())
    {
        window.clear(sf::Color::White);
        game_board->draw_board_graphical(&window, cell_size);
        window.display();
        if (current_player_first == player1->get_is_first())
            current_player = player1;
        else
            current_player = player2;
        if (current_player->make_move_graphical(&window, cell_size))
        {
            if (game_board->check_win(current_player->get_is_first()))
            {
                window.clear();
                game_board->draw_board_graphical(&window, cell_size);
                window.display();
                std::cout << "Player " << current_player->get_symbol() << " wins!" << std::endl;
                window.close();
            }

            if (game_board->no_more_fields())
            {
                window.clear();
                game_board->draw_board_graphical(&window, cell_size);
                window.display();
                std::cout << "It's a draw!" << std::endl;
                window.close();
            }

            current_player_first = !current_player_first;
        }
    }
}

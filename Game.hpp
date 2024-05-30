#ifndef GAME
#define GAME

#include <iostream>
#include "Board.hpp"
#include "Player.hpp"
#include "AIPlayer.hpp"


class Game
{
private:
    Board* game_board;
    Player* current_player;
    Player* player1;
    Player* player2;

public:
    Game()
    {
        unsigned int size = 0;
        while (1)
        {
            std::cout << "Podaj wielkość planszy (conajmniej 3): ";
            std::cin >> size;
            if (size < 3)
                std::cout << "Zły rozmiar! Spróbuj ponownie...\n";
            else
                break;
        }

        game_board = new Board(size);

        unsigned int p_number;
        while(1)
        {
            std::cout << "Podaj ilość graczy (1-2): ";
            std::cin >> p_number;
            if(p_number == 2)
            {
                player1 = new Player(true, game_board);
                player2 = new Player(false, game_board);
                break;
            }
            else if (p_number == 1)
            {
                bool who_first;
                unsigned int d = 3;
                std::cout << "Czy chcesz być kółkiem? (wybierz 1 - tak lub 0 - nie): ";
                std::cin >> who_first;
                std::cout << "Podaj głębokość AI minimax: ";
                std::cin >> d;
                player1 = new Player(who_first, game_board);
                player2 = new PlayerAI(!who_first, game_board, d);
                break;
            }
            else if (p_number == 0)
            {
                unsigned int d = 3;
                unsigned int d2 = 3;
                std::cout << "Podaj głębokość pierwszego AI minimax: ";
                std::cin >> d;
                std::cout << "Podaj głębokość drugiego AI minimax: ";
                std::cin >> d2;
                player1 = new PlayerAI(true, game_board, d);
                player2 = new PlayerAI(false, game_board, d2);
                break;
            }
            else
                std::cout << "Podano błędną liczbę graczy! Spróbuj ponownie...\n";
        }
    }

    ~Game()
    {
        delete player1;
        delete player2;
        delete game_board;
    }

    void start_game_loop();
};

#endif

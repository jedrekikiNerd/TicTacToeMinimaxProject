#include "Game.hpp"


int main()
{
    int a;
    Game TicTacToe_game_instance;
    TicTacToe_game_instance.start_game_loop();
    std::cout << "\nKONIEC GRY! Kliknij enter, aby wyjść! ";
    std::cin >> a;
    return 0;
}

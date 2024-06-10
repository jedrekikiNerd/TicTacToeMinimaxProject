#ifndef BOARD
#define BOARD

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


class Board
{
private:
    unsigned int size;
    unsigned int taken_fields = 0;
    unsigned int winning_condition;
    char first_player_symbol;
    char second_player_symbol;
    char** board_table;

    void allocate_board_table();

    void deallocate_board_table();

    char& get_field(unsigned int row, unsigned int column);

public:
    Board() : size(3), first_player_symbol('O'), second_player_symbol('X') {allocate_board_table();}
    Board(unsigned int s, unsigned int win_cond) : size(s), winning_condition(win_cond), first_player_symbol('O'), second_player_symbol('X') {allocate_board_table();}
    Board(unsigned int s, unsigned int win_cond, char p1, char p2) : size(s), winning_condition(win_cond), first_player_symbol(p1), second_player_symbol(p2) {allocate_board_table();}

    ~Board() {deallocate_board_table();}

    bool make_move(unsigned int row, unsigned int col, bool first_player = true);

    bool undo_move(unsigned int row, unsigned int col);

    bool check_win(bool first_player);

    void print_board();

    void draw_board_graphical(sf::RenderWindow *window, unsigned int cell_size);

    bool no_more_fields() const
    {
        return (size*size <= taken_fields);
    }

    unsigned int get_size() const
    {
        return size;
    }
};

#endif
#ifndef BOARD
#define BOARD

#include <iostream>


class Board
{
private:
    unsigned int size;
    unsigned int taken_fields = 0;
    char first_player_symbol;
    char second_player_symbol;
    char** board_table;

    void allocate_board_table();

    void deallocate_board_table();

    char& get_field(unsigned int row, unsigned int column);

public:
    Board() : size(3), first_player_symbol('O'), second_player_symbol('X') {allocate_board_table();}
    Board(unsigned int s) : size(s), first_player_symbol('O'), second_player_symbol('X') {allocate_board_table();}
    Board(unsigned int s, char p1, char p2) : size(s), first_player_symbol(p1), second_player_symbol(p2) {allocate_board_table();}

    ~Board() {deallocate_board_table();}

    bool make_move(unsigned int row, unsigned int col, bool first_player = true);

    bool undo_move(unsigned int row, unsigned int col);

    bool check_win(bool first_player);

    void print_board();

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
#include "Board.hpp"


void Board::allocate_board_table()
{
    // Allocate the array of pointers (rows)
    board_table = new char*[size];

    // Allocate each row (columns)
    for(int i = 0; i < size; i++)
    {
        board_table[i] = new char[size];
    }

    // Initialize and use the array
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            board_table[i][j] = ' ';  // Fill with empty
        }
    }
}

void Board::deallocate_board_table()
{
    // Deallocate each row
    for(int i = 0; i < size; i++)
    {
        delete[] board_table[i];
    }

    // Deallocate the array of pointers
    delete[] board_table;
}

char& Board::get_field(unsigned int row, unsigned int column)
{
    return board_table[row][column];
}

bool Board::make_move(unsigned int row, unsigned int col, bool first_player)
{
    if(row > size or col > size)
        return false;
    
    char& field = get_field(row-1, col-1);
    if(field == ' ')
    {
        if(first_player)
            field = first_player_symbol;
        else
            field = second_player_symbol;

        taken_fields++;
        return true;
    }
    return false;
}

bool Board::undo_move(unsigned int row, unsigned int col)
{
    if(row > size or col > size)
        return false;
    
    char& field = get_field(row-1, col-1);
    if(field != ' ')
    {
        field = ' ';
        taken_fields--;
        return true;
    }
    return false;
}

bool Board::check_win(bool first_player)
{
    char player_char = second_player_symbol;
    if (first_player)
        player_char = first_player_symbol;

    // Check rows and columns
    for (unsigned int i = 0; i < size; i++)
    {
        bool row_win = true;
        bool col_win = true;

        for (unsigned int j = 0; j < size; j++)
        {
            if (get_field(i, j) != player_char)
            {
                row_win = false;
            }
            if (get_field(j, i) != player_char)
            {
                col_win = false;
            }
        }

        if (row_win or col_win)
        {
            return true;
        }
    }

    // Check diagonals
    bool diag1_win = true;
    bool diag2_win = true;
    for (unsigned int i = 0; i < size; i++)
    {
        if (get_field(i, i) != player_char)
        {
            diag1_win = false;
        }
        if (get_field(i, size - i - 1) != player_char)
        {
            diag2_win = false;
        }
    }
    if (diag1_win or diag2_win)
    {
        return true;
    }

    return false;
}

void Board::print_board()
{
    for (unsigned int j = 0; j < size; j++)
    {
        std::cout << "+---";
    }
    std::cout << "+" << std::endl;

    for (unsigned int i = 0; i < size; i++)
    {
        for (unsigned int j = 0; j < size; j++)
        {
            std::cout << "| " << get_field(i, j) << " ";
        }
        std::cout << "|" << std::endl;

        for (unsigned int j = 0; j < size; j++)
        {
            std::cout << "+---";
        }
        std::cout << "+" << std::endl;
    }
}

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

    // Check rows
    for (unsigned int i = 0; i < size; i++)
    {
        for (unsigned int j = 0; j <= size - winning_condition; j++)
        {
            bool row_win = true;
            for (unsigned int k = 0; k < winning_condition; k++)
            {
                if (get_field(i, j + k) != player_char)
                {
                    row_win = false;
                    break;
                }
            }
            if (row_win)
            {
                return true;
            }
        }
    }

    // Check columns
    for (unsigned int j = 0; j < size; j++)
    {
        for (unsigned int i = 0; i <= size - winning_condition; i++)
        {
            bool col_win = true;
            for (unsigned int k = 0; k < winning_condition; k++)
            {
                if (get_field(i + k, j) != player_char)
                {
                    col_win = false;
                    break;
                }
            }
            if (col_win)
            {
                return true;
            }
        }
    }

    // Check diagonals (top-left to bottom-right)
    for (unsigned int i = 0; i <= size - winning_condition; i++)
    {
        for (unsigned int j = 0; j <= size - winning_condition; j++)
        {
            bool diag1_win = true;
            for (unsigned int k = 0; k < winning_condition; k++)
            {
                if (get_field(i + k, j + k) != player_char)
                {
                    diag1_win = false;
                    break;
                }
            }
            if (diag1_win)
            {
                return true;
            }
        }
    }

    // Check diagonals (bottom-left to top-right)
    for (unsigned int i = 0; i <= size - winning_condition; i++)
    {
        for (unsigned int j = 0; j <= size - winning_condition; j++)
        {
            bool diag2_win = true;
            for (unsigned int k = 0; k < winning_condition; k++)
            {
                if (get_field(i + k, j + (winning_condition - 1) - k) != player_char)
                {
                    diag2_win = false;
                    break;
                }
            }
            if (diag2_win)
            {
                return true;
            }
        }
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

void Board::draw_board_graphical(sf::RenderWindow *window, unsigned int cell_size)
{
    // Select boarder line style
    sf::RectangleShape line(sf::Vector2f(cell_size * size, 2));
    line.setFillColor(sf::Color::Black);

    // Draw lines of board
    for (unsigned int i = 1; i < size; i++)
    {
        line.setPosition(0, i * cell_size);
        window->draw(line);
        line.setPosition(i * cell_size, 0);
        line.setRotation(90);
        window->draw(line);
        line.setRotation(0);
    }

    // Draw symbols of board
    for (unsigned int i = 0; i < size; ++i)
    {
        for (unsigned int j = 0; j < size; ++j)
        {
            char symbol = get_field(i, j);
            if (symbol != ' ')
            {
                if (symbol == 'O')
                {
                    sf::CircleShape circle(cell_size / 2 - 10);
                    circle.setFillColor(sf::Color::Transparent);
                    circle.setOutlineThickness(5);
                    circle.setOutlineColor(sf::Color::Blue);
                    circle.setPosition(j * cell_size + 10, i * cell_size + 10);
                    window->draw(circle);
                }
                else if (symbol == 'X')
                {
                    sf::RectangleShape line1(sf::Vector2f(cell_size - 20, 5));
                    line1.setFillColor(sf::Color::Red);
                    line1.setOrigin((cell_size - 20) / 2, 2.5);
                    line1.setPosition(j * cell_size + cell_size / 2, i * cell_size + cell_size / 2);
                    line1.setRotation(45);
                    
                    sf::RectangleShape line2(sf::Vector2f(cell_size - 20, 5));
                    line2.setFillColor(sf::Color::Red);
                    line2.setOrigin((cell_size - 20) / 2, 2.5);
                    line2.setPosition(j * cell_size + cell_size / 2, i * cell_size + cell_size / 2);
                    line2.setRotation(-45);

                    window->draw(line1);
                    window->draw(line2);
                }
            }
        }
    }
}


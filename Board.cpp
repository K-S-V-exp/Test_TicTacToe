#include "Board.h"
#include "misc.h"

#include <algorithm>
#include <cassert>
#include <istream>


std::istream& operator>>(std::istream& is, Board::Cell& cell);

Board::Board() : _board({ Cell::empty })
{
}

Board::~Board()
{
}

bool Board::checkRows() const
{
    return Rows(_board).anyWinningRow();
}

bool Board::checkColumn() const
{
    return Columns(_board).anyWinningColumn();
}

bool Board::checkDiagonal() const
{
    if ((_board[1][1] != Cell::empty) &&
        ((_board[0][0] == _board[1][1] &&
            _board[1][1] == _board[2][2])
            ||
            (_board[0][2] == _board[1][1]
                && _board[1][1] == _board[2][0])))
        return true;
    return false;
}

bool Board::complete() const
{
    if (std::none_of(begin(), end(), [](Cell cell) { return cell == Cell::empty; }))
        return true;
    else if (checkRows())
        return true;
    else if (checkColumn())
        return true;
    else if (checkDiagonal())
        return true;

    return false;
}

void Board::setValueAt(const int row, const int column, const Cell value)
{
    _board[row][column] = value;
}

Board::Cell Board::getValueAt(const int row, const int column) const
{
    return _board[row][column];
}

Board::const_iterator Board::begin() const
{
    return BoardIterator(_board);
}

Board::const_iterator Board::end() const
{
    BoardIterator it(_board);
    it.end();
    return it;
}

std::istream& operator>>(std::istream& is, Board::Cell& cell)
{
    char input = '\0';
    is >> input;
    if (input == ' ')
    {
        cell = Board::Cell::empty;
    }
    else if (input == 'x')
    {
        cell = Board::Cell::cross;
    }
    else if (input == 'o')
    {
        cell = Board::Cell::circle;
    }
    else
    {
        assert(!"Character cannot be converted to Cell.");
    }
    return is;
}
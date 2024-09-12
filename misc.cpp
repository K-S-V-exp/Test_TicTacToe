#include "misc.h"

#include <array>




Columns::const_iterator Columns::begin() const
{
    return ColumnIterator(_board);
}

Columns::const_iterator Columns::end() const
{
    ColumnIterator columnIterator(_board);
    columnIterator.end();
    return columnIterator;
}

bool Columns::anyWinningColumn() const
{
    return std::any_of(begin(), end(), isWinningColumn());
}

struct isWinningRow
{
    bool operator()(std::array<Board::Cell, 3> row)
    {
        return
            std::all_of(row.begin(), row.end(), [](Board::Cell cell) { return cell == Board::Cell::cross; })
            ||
            std::all_of(row.begin(), row.end(), [](Board::Cell cell) { return cell == Board::Cell::circle; });
    }
};

bool Rows::anyWinningRow() const
{
    return std::any_of(_board.begin(), _board.end(), isWinningRow());
}
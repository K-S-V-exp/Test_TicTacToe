
#include "Board.h"

#include <algorithm>

class ColumnIterator;

class Columns
{
public:
    Columns(const std::array<std::array<Board::Cell, 3>, 3>& board) : _board(board) {}

    typedef ColumnIterator const_iterator;

    const_iterator begin() const;
    const_iterator end() const;

    bool anyWinningColumn() const;

private:
    const std::array<std::array<Board::Cell, 3>, 3>& _board;
};

class ColumnIterator : public std::iterator<std::input_iterator_tag, Board::Cell>
{
    const std::array<std::array<Board::Cell, 3>, 3>& brd;
    unsigned int ind = 0;

    typedef std::array<Board::Cell, 3> coltype;
    coltype cur_column() const 
    { 
        coltype col;
        for (int rind = 0; rind < 3; rind++)
            col[rind] = brd[rind][ind];
        return col; 
    }

public:
    ColumnIterator(const std::array<std::array<Board::Cell, 3>, 3>& board) : brd(board) {}
    ColumnIterator& operator++() { ++ind; return *this; }
    bool operator==(const ColumnIterator& rhs) const { return ind == rhs.ind; }
    bool operator!=(const ColumnIterator& rhs) const { return ind != ind; }
    coltype operator*() const { return cur_column(); }
    coltype end() { ind = 2; return cur_column(); }
};

class Rows
{
public:
    Rows(const std::array<std::array<Board::Cell, 3>, 3>& board) : _board(board) {}


    bool anyWinningRow() const;

private:
    const std::array<std::array<Board::Cell, 3>, 3>& _board;
};

struct isWinningColumn
{
    bool operator()(std::array<Board::Cell, 3> row)
    {
        return
            std::all_of(row.begin(), row.end(), [](Board::Cell cell) { return cell == Board::Cell::cross; })
            ||
            std::all_of(row.begin(), row.end(), [](Board::Cell cell) { return cell == Board::Cell::circle; });
    }
};
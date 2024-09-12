
#pragma once

#include <array>
#include <iterator>

class BoardIterator;


/*!
 *  The board of the Tic Tac Toe game (a table 3*3).
 */



class Board
{
public:
    enum class Cell
    {
        empty,
        cross,
        circle
    };
    typedef BoardIterator const_iterator;


    Board();
    virtual ~Board();

    /*!
     *	Verify if there is any condition up there true or if the table is full.
     *	return True if it is, false elsewhere.
     */
    bool complete() const;

    Cell getValueAt(const int row, const int column) const;
    void setValueAt(const int row, const int column, const Cell value);

    /*!
    *	Verify if there is a row with only the same char.
    */
    bool checkRows() const;

    /*!
     *	Verify if there is a column with only the same char.
     */
    bool checkColumn() const;

    /*!
     *	Verify if there is a diagonal with only the same char.
     */
    bool checkDiagonal() const;


    const_iterator begin() const;
    const_iterator end() const;

private:
    std::array<std::array<Cell, 3>, 3> _board;    /*!< The board for Tic Tac Toe game, a 3*3 table. */
    
    
};

class BoardIterator : public std::iterator<std::input_iterator_tag, Board::Cell>
{
    const std::array<std::array<Board::Cell, 3>, 3>& brd;
    unsigned int ind = 0;
    
    Board::Cell get_cval() const { return brd[ind / 3][ind % 3]; }
    public:
        BoardIterator(const std::array<std::array<Board::Cell, 3>, 3>& board) : brd(board) {}
        BoardIterator& operator++() { ++ind; return *this; }
        bool operator==(const BoardIterator& rhs) const { return ind == rhs.ind; }
        bool operator!=(const BoardIterator& rhs) const { return ind != rhs.ind; }
        Board::Cell operator*() const { return get_cval(); }
        Board::Cell end() { ind = 8; return get_cval(); }
};
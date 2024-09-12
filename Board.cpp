class BoardIterator;


/*!
 *  The board of the Tic Tac Toe game (a table 3*3).
 */
class Board
{
public:
    typedef BoardIterator const_iterator;
    enum class Cell
    {
        empty,
        cross,
        circle
    };

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
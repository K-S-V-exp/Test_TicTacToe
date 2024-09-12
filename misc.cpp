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

class Rows
{
public:
    Rows(const std::array<std::array<Board::Cell, 3>, 3>& board) : _board(board) {}

    typedef std::array<std::array<Board::Cell, 3>, 3>::const_iterator const_iterator;

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
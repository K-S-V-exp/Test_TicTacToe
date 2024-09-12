/* !
*  The game contains the players, the rules and the display.
*/
class Game {
public:

    /*!
     *	Game's Constructor, it will allocate the vector of players' size.
     *	\param size The number of players.
     */
    explicit Game(std::size_t size);

    virtual ~Game();

    virtual void start();

    int getCurrentPlayer();

    void askValue();

private:
    std::vector<Player> _players;  /*!< vector of players, the losers will be kicked out the vector. */
    Board _board;
    int _currentPlayer;             /*!< ID of the current player. */

};


Game::Game(std::size_t size) : _players(size, Player(1)), _currentPlayer(0)
{
    _players[1] = Player(2);
}

Game::~Game()
{
}

void Game::start()
{
    while (!_board.complete())
    {
        std::cout << "Player " << _players[_currentPlayer].getId() << " is playing." << std::endl;
        askValue();
        _currentPlayer = _currentPlayer == 0 ? 1 : 0;
    }
    _currentPlayer = _currentPlayer == 0 ? 1 : 0; // TODO: Because of the loop it will be changed to the loser, so here we set it back.
    std::cout << "Player " << _players[_currentPlayer].getId() << " win !" << std::endl;
}

int Game::getCurrentPlayer()
{
    return _players[_currentPlayer].getId();
}

void Game::askValue()
{
    int row, column;
    Board::Cell value;
    bool pass = false;

    std::cout << "Give a Row, a Column and a Value: " << std::endl;
    while (!pass)
    {
        std::cin >> row;
        std::cin >> column;
        std::cin >> value;

        if (_board.getValueAt(row, column) == Board::Cell::empty)
        {
            _board.setValueAt(row, column, value);
            pass = true;
        }
        else
        {
            std::cout << "There is already something there, try another cell: " << std::endl;
        }
    }
}

int main()
{
  Game game(2);
  game.start();

  return 1;
}
/*!
 *  The player is there to knows who's playing.
 */
class Player {
public:

    Player(int id);
    virtual ~Player();

    void displayPlayer();

    int getId();

private:
    int _id; /*!< The ID of the player. */
};

Player::Player(int id) : _id(id)
{
}

Player::~Player()
{
}

int Player::getId()
{
    return _id;
}

void Player::displayPlayer()
{
    std::cout << "Player n°" << _id << std::endl;
}
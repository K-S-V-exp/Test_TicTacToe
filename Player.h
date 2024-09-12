

class Player {
public:

    Player(int id);
    virtual ~Player();

    void displayPlayer();

    int getId();

private:
    int _id; /*!< The ID of the player. */
};
/*!
 *  The player is there to knows who's playing.
 */

#include "Player.h"

#include <iostream>

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
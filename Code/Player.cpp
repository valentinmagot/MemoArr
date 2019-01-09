/**
 * Projet CSI 2772[A] Robert Laganiere
 * Player.cpp
 * @author Maxime Cote-Gagne(8851539) & Valentin Magot(8843488)
 *
 */
#include "Player.h"

#include <string>
#include <iostream>

/*Constructor*/
Player::Player(std::string name, Side side):
 _name(name), _boardSide(side), _rubies(0), _active(false), _endOfGame(false)
 {}
/*Copy constructor*/
Player::Player(const Player& p) :
	_name(p._name), _boardSide(p._boardSide),
	_rubies(p._rubies), _active(p._active), _endOfGame(p._endOfGame) {}

/*destructor*/
Player::~Player()
{}

/*return the name of the player*/
std::string Player::getName() const{
	return _name;
}

/*set the status of the player as active or inactive*/
void Player::setActive(bool active){
	_active = active;
}

/*returns true if the player is active*/
bool Player::isActive() const{
	return _active;
}

/*return the number of rubies won by this player*/
int Player::getNRubies() const{
	return _rubies;
}

/*add a reward with a given number of rubies*/
void Player::addReward(const Reward& reward){
	_rubies += reward;//besoins de faire un operator int() dans reward.h
}

/*change how the player is show
*false:Joe Remember Doe:  left (active) 
*true:Joe Remember Doe:  3 rubies 
*/
void Player::setDisplayMode(bool endOfGame){
	_endOfGame = endOfGame;
}

Side Player::getSide() const{
	return _boardSide;
}

//joueur imprimable a l'ecran avec ca
/*A player must be printable with the insertion operator cout << player*/
std::ostream & operator<<(std::ostream & os, const Player & m){
	if (!m._endOfGame) {//si faux
		os << m.getName() << " : " << sideArray[m.getSide()] << " " << (m.isActive() ? "active" : "inactive") << std::endl;;
	}
	else {//sinon
		os << m.getName() << " : " << m.getNRubies() << " rubies \n";
	}

	return os;
}



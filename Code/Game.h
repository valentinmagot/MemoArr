/**
 * Projet CSI 2772[A] Robert Laganiere
 * Game.h
 * Encapsulates the current state of the game
 * Print the current state of the game
 * @author Maxime Cote-Gagne(8851539) & Valentin Magot(8843488)
 *
 */
#ifndef GAME_H
#define GAME_H
#include "Test.h"
#include "player.h"
#include "card.h"
#include "board.h"
#include "rewarddeck.h"
#include <exception>
#include <vector>

/*
 *exception
 */
struct InvalidPlayer : public std::exception {
	const char * what() const throw () {
		return "InvalidPlayer exception: no player on this side!";
	}
};

class Game
{
private:
	Board& board;

	const Card *previousCard;
	const Card *currentCard;

	int round;

	std::vector<Player*> players;

	RewardDeck& rd;

	friend std::ostream& operator<< (std::ostream& os, const Game& g);
public:
	Game(Board&);
	~Game();
	inline int getRound() const { return round; }
	void addPlayer(const Player&);
	Player& getPlayer(Side) const;
	inline const Card* getPreviousCard() const { return previousCard; }
	inline const Card* getCurrentCard() const { return currentCard; }
	void setCurrentCard(const Card*);

	//Addition to the Game object
	Card* getCard(const Letter&, const Number&) const;
	void setCard(const Letter&, const Number&, Card*);
	
	void next();//new function
};
#endif

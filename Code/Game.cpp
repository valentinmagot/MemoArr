/**
 * Projet CSI 2772[A] Robert Laganiere
 * Game.cpp
 * @author Maxime Cote-Gagne(8851539) & Valentin Magot(8843488)
 *
 */
#include "game.h"

/*make a RewardDeck and shuffle it*/
Game::Game(Board& b) : rd(RewardDeck::make_RewardDeck()), board(b) {
	rd.shuffle();
}

/*Destroy all players in the game*/
Game::~Game(){
	for (auto i : players) {
		delete i;
	}
}

/*adds a Player to this game*/
void Game::addPlayer(const Player& p) {
	bool playerPresent = false;
	for (auto &ep : players) {
		if (p.getSide() == ep->getSide()) {
			playerPresent = true;
			ep->setActive(p.isActive());
			break;
		}
	}
	if (!playerPresent) {
		players.push_back(new Player(p));
	}
}

/*get the player from the requested side*/
Player& Game::getPlayer(Side s) const {
	if (s < players.size() && players[s] != nullptr) {//check if the player side is not nullptr of a player
		return *(players[s]);
	}
	else {
		throw InvalidPlayer();
	}
}



/*set the previous card to the current one and the current to the one call*/
void Game::setCurrentCard(const Card* c) {
	previousCard = currentCard;
	currentCard = c;
}

/*Get a card from the board*/
Card* Game::getCard(const Letter& l, const Number& n) const {
	return board.getCard(l, n);
}

/*set a card in the board*/
void Game::setCard(const Letter& l, const Number& n, Card* c) {
	board.setCard(l, n, c);
}



//OSTREAM
std::ostream& operator<< (std::ostream& os, const Game& g) {
	os << g.board << std::endl;
	for (int i = 0; i < g.players.size(); ++i) {
		if (g.players[i] != nullptr) {
			os << *g.players[i];
		}
	}
	return os;
}


/* Use to reset everything in game, increasing the round counter andgive reward to the last active player, also reputting every player active after one round*/
void Game::next() {//add reward
	previousCard = 0;
	currentCard = 0;
	++round;
	for (auto p : players) {
		
		if (p->isActive()) {
			int tmp1 = p->getNRubies();
			p->addReward(*rd.getNext());
			int tmp2 = p->getNRubies();
			int tmp3 = tmp2 - tmp1;

			//std::cout << p->getName() << " receive " << tmp3 << " rubies from winning this round" << std::endl;

		}
	}
	//make all player actve for next round
	for (auto p : players) {
		p->setActive(true);
	}
}
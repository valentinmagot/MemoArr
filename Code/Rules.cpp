/**
 * Projet CSI 2772[A] Robert Laganiere
 * Rules.cpp
 * Check if a selection of a player is valid
 * @author Maxime Cote-Gagne(8851539) & Valentin Magot(8843488)
 *
 */
#include "Rules.h"

//players est un vector!!!
/*
 *Constructor Rules
 * Set all Players there side
 */
Rules::Rules()
{
	//Ordre des joueurs : Top, Right, Bottom, Left : Sens d'horloge
	for (auto side : { top, right, bot, left }) {//AUTO IS NICE TO USE HERE! should be use everywhere when we can instead!!
		players.push_back(side);
	}
	firstplayer = 0;
	currentplayer = firstplayer - 1;//Put Top players first because of nextPlayers function
}

/*
 *Function roundOver
 *Return true is previous and current card match, by there colors or there animals, or both; false otherwise.
 */
bool Rules::isValid(const Game& g) {//Same structure should be use in ExpertRules
	++cardsturned;
	const Card* cc = g.getCurrentCard();//Current Card
	const Card* pc = g.getPreviousCard();//Previous Card

	//Use for the first turn in the round
	if (pc == nullptr) {
		return true;
	}

	//Check is the current card match the precious one, if true return true
	if (((FaceAnimal)*cc == (FaceAnimal)*pc) || ((FaceBackground)*cc == (FaceBackground)*pc)) {
		return true;
	}
	else {
		return false;
	}
}


/*
 *Function gameOver
 *Return true if the number of rounds has reached 7
 */
bool Rules::gameOver(const Game& g) {
	if (g.getRound() >= 7) {//if getRound() in game reached 7, game is over
		return true;
	}
	else {//game not over
		return false;
	}
}

/*
 *Function roundOver
 *Return true if there is only one active Player left
 */
bool Rules::roundOver(const Game& g) {
	Player* player = nullptr;
	std::vector<Player*> active;

	for (auto &p : players) {//put all active players in a vector of active players«
		try {
			player = &g.getPlayer(p);
			if (player->isActive()) {
				active.push_back(player);
			}
		}
		catch (InvalidPlayer e) {
			//throw "No valid players from Game object in Rules object!";
		}
	}

	//return true if there is only one active Players left, should be size() == 1
	if (active.size() == 1) {
		cardsturned = 0;//reset the number of cards turned for the next round
		return true;//return true== round is over
	}
	else if (active.size() == 0) {//if there is no players active at all
		throw "No more Players active in Game!";
	}
	else if (cardsturned == 24) {//if all the card are turn over the game should be over too
		active.pop_back();
		for (auto &p : active) {
			p->setActive(false);//put all players to inactive
		}
		cardsturned = 0;//reset number of card draw in the round
		return true;//return true because round is over
	}
	else {
		return false;
	}
}

/*
 *Function getNextPlayer
 *Try to get the next player
 */
const Player& Rules::getNextPlayer(const Game& g) {
	Player* player = nullptr;//set ptr player to nullptr
	int size = players.size();

	while (player == nullptr) {
		try {
			player = &g.getPlayer(nextPlayer()); //find the player
			if (!player->isActive()) {
				player == nullptr;
			}
		}
		catch (InvalidPlayer e) { //exception
			size--;
			if (size == 0) {
				throw "No valid players from Game object in Rules object!";
			}
		}
	}

	return *player;
}


/*
 *Function nextPlayer
 *Change the currentPlayer to the next one
 */
Side Rules::nextPlayer() {
	if (currentplayer < players.size() - 1) {
		++currentplayer;
	}
	else {
		currentplayer = firstplayer;
	}

	return players[currentplayer];
}


/*
 *Function nextPlayer
 *Change the currentPlayer to the previous one, normaly it will stay on the same player(use for ExpertRules)
 */
Side Rules::previousPlayer() {
	if (currentplayer > 0) {
		--currentplayer;
	}
	else {
		currentplayer = players.size() - 1;
	}

	return players[currentplayer];
}

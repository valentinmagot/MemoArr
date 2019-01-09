/**
 * Projet CSI 2772[A] Robert Laganiere
 * ExpertRules.cpp
 * @author Maxime Cote-Gagne(8851539) & Valentin Magot(8843488)
 *
 */
#include "ExpertRules.h"
Letter letter() {
	Letter tmpL;
	char tL;
	while (true) {
		std::cin >> tL;
		if (!std::cin.fail() && (tL == 'A' || tL == 'B' || tL == 'C' || tL == 'D' || tL == 'E' || tL == 'a' || tL == 'b' || tL == 'c' || tL == 'd' || tL == 'e')) {
			if (tL == 'A' || tL == 'B' || tL == 'C' || tL == 'D' || tL == 'E') {
				tmpL = Letter(tL - 'A');

			}

			if (tL == 'a' || tL == 'b' || tL == 'c' || tL == 'd' || tL == 'e') {
				tmpL = Letter(tL - 'a');
			}

			std::cin.clear();
			std::cin.ignore(100, '\n');
			break;
		}
		else {
			std::cout << "Letter A, B, C, D, E:" << std::endl;
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
	}
	return tmpL;
}

Number number() {
	Number tmpN;
	int tN;
	while (true) {
		std::cin >> tN;
		if (!std::cin.fail() && (tN == 1 || tN == 2 || tN == 3 || tN == 4 || tN == 5)) {
			tmpN = Number(tN - 1);
			std::cin.clear();
			std::cin.ignore(100, '\n');
			break;
		}
		else {
			std::cout << "Number 1, 2, 3, 4, 5:" << std::endl;
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
	}
	return tmpN;
}

/* returns true is previous and current card match; and ADD POWER TO EACH CARD false otherwise. */
bool ExpertRules::isValid(const Game& g) {
	++cardsturned;
	const Card* cc = g.getCurrentCard();
	const Card* pc = g.getPreviousCard();

	if ((pc == nullptr) || ((FaceAnimal)*cc == (FaceAnimal)*pc) || ((FaceBackground)*cc == (FaceBackground)*pc)) {
		//check if the curent card is blocked
		if (cc == block) {
			std::cout << "Your card is block!!!" << std::endl;
			return false;
		}

		//CRAB
		if ((FaceAnimal)*cc == Crab) {
			std::cout << "Crab:\nCurrent player can play again!\n" << std::endl;

			if (cardsturned == 24) {//check if card are all turned before
				return true;
			}	
			previousPlayer();

		}//CRAB

		//PENGUIN
		else if (((FaceAnimal)*cc == Penguin) && (pc != nullptr)) {
			std::cout << "Penguin:\ncurrent player can face down a face up card!\n" << std::endl;
			
			//Current Board
			std::cout << *board << std::endl;

			//current card
			Letter L; Number N;
			for (auto l : { A,B,C,D,E }) {
				for (auto n : { ONE,TWO,THREE,FOUR,FIVE }) {
					if ((FaceAnimal)*cc == (FaceAnimal)*g.getCard(l, n) && (FaceBackground)*cc == (FaceBackground)*g.getCard(l, n)) {
						L = l;
						N = n;
						break;
					}
				}
			}
			
			//choosen card
			std::cout << "Card to face down:" << std::endl;
			std::cout << "Letter A, B, C, D, E:" << std::endl;
			Letter tmpL = letter();
			std::cout << "Number 1, 2, 3, 4, 5:" << std::endl;
			Number tmpN = number();


			//Check if the card is up
			while ((tmpL == L && tmpN == N) || (tmpL == C && tmpN == THREE) || (!board->isFaceUp(L, N))) {
				std::cout << "Incorrect card choice. Face up Card ONLY!:" << std::endl;
				std::cout << "Letter A, B, C, D, E:" << std::endl;
				Letter tmpL = letter();//SWITCH TO FUNCTION will be more READABLE!!!! TODO
				std::cout << "Number 1, 2, 3, 4, 5:" << std::endl;
				Number tmpN = number();

			}

			//face down the card choosen
			board->turnFaceDown(tmpL, tmpN);
			cardsturned--;//minus 1 the number of card face up
			
		}//PENGUIN


		//OCTOPUS
		else if ((FaceAnimal)*cc == Octopus) {//same as penfuin, for the structure
			std::cout << "Octopus:\nCurrent player can swap a card with one of the adjacent one!\n" << std::endl;

			if (cardsturned == 24) {
				return true;
			}

			//Current Board
			std::cout << *board << std::endl;

			//current card
			Letter L; Number N;
			for (auto l : { A,B,C,D,E }) {
				for (auto n : { ONE,TWO,THREE,FOUR,FIVE }) {
					if ((FaceAnimal)*cc == (FaceAnimal)*g.getCard(l, n) && (FaceBackground)*cc == (FaceBackground)*g.getCard(l, n)) {
						L = l;
						N = n;
						break;
					}
				}
			}

			//Chooseen Card
			std::cout << "Adjacent card ONLY:" << std::endl;
			std::cout << "Letter A, B, C, D, E:" << std::endl;
			Letter tmpL = letter();//SWITCH TO FUNCTION will be more READABLE!!!! TODO
			std::cout << "Number 1, 2, 3, 4, 5:" << std::endl;
			Number tmpN = number();



			//Check if the two card are adjacent
			while (((abs(static_cast<int>(tmpL) - static_cast<int>(L)) + abs(static_cast<int>(tmpN) - static_cast<int>(N))) != 1) || (tmpL == C && tmpN == THREE)) {
				std::cout << "Incorrect card choice. ADJACENT:" <<std::endl;
				std::cout << "Letter A, B, C, D, E:" << std::endl;
				tmpL = letter();
				std::cout << "Number 1, 2, 3, 4, 5:" << std::endl;
				tmpN = number();
			}

			//Get the card
			Card* tmpCard = g.getCard(tmpL, tmpN);
			CardSide tmpSide = DOWN;
			if (board->isFaceUp(tmpL, tmpN)) {
				tmpSide = UP;
			}


			//Swap the two cards
			board->setCard(tmpL, tmpN, const_cast<Card*>(cc));
			board->setCard(L, N, tmpCard);
			board->turnFaceUp(tmpL, tmpN);
			if (tmpSide == UP) {
				board->turnFaceUp(L, N);
			}
			else {
				board->turnFaceDown(L, N);
			}
		}//OCTOPUS



		//WALRUS
		else if ((FaceAnimal)*cc == Walrus) {
			std::cout << "Walrus:\nCurrent player can choose a card to block for the next turn!\n" << std::endl;

			if (cardsturned == 24) {
				return true;
			}

			//current board
			std::cout << *board << std::endl;

			//Choosen Card
			std::cout << "Block a face down card: " << std::endl;
			std::cout << "Letter A, B, C, D, E:" << std::endl;
			Letter tmpL = letter();
			std::cout << "Number 1, 2, 3, 4, 5::" << std::endl;
			Number tmpN = number();

			//check if the card is face down
			while (board->isFaceUp(tmpL, tmpN)) {
				std::cout << "Incorrect card choice. FACE DOWN:" << std::endl;
				std::cout << "Letter A, B, C, D, E:" << std::endl;
				tmpL = letter();
				std::cout << "Number 1, 2, 3, 4, 5:" << std::endl;
				tmpN = number();
			}
			//set the block card in the card pointer block
			block = board->getCard(tmpL, tmpN);
			return true;
		}//WALRUS


		//TURTLE
		else if ((FaceAnimal)*cc == Turtle) {
			std::cout << "Turtle:\nNext player get his turn skip!\n" << std::endl;

			if (cardsturned == 24) {
				return true;
			}
			getNextPlayer(g);
			
		}//TURTLE



		block = nullptr;//reset the card to nullptr;
		return true;
	}
	else {
		block = nullptr;//reset the card to nullptr
		return false;
	}
}


bool ExpertRules::roundOver(const Game &g) {//same as rules but with block reset to nullptr
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
		block = nullptr;//ADD
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
		block = nullptr;//ADD
		cardsturned = 0;//reset number of card draw in the round
		return true;//return true because round is over
	}
	else {
		return false;
	}
}
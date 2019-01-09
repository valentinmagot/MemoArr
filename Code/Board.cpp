/**
 * Projet CSI 2772[A] Robert Laganiere
 * Board.cpp
 * 
 * @author Maxime Cote-Gagne(8851539) & Valentin Magot(8843488)
 *
 */
#include "Board.h"
#include "CardDeck.h"
/*Board constructor, reset the current board and make a card deck and shuffle it*/
Board::Board() {
	reset();
	CardDeck& cd = CardDeck::make_CardDeck();

	if (cd.isEmpty()){
		throw NoMoreCards();
	}
	cd.shuffle();

	int i = 0;
	while (!cd.isEmpty()) {
		cardmatrix[i / 5][i % 5] = cd.getNext();
		++i;
	}
}

/* returns true if the card at a given position is face up. 
 *Letter and Number are enumerations. 
 *Throws an exception of type OutOfRange if an invalid Letter and Number combination was given.
 */
bool Board::isFaceUp(const Letter& l, const Number& n) const {
	if (outOfRange(l, n)) {
		throw OutOfRange();
	}
	if (cardSide[l][n]) {
		return true;
	}
	else {
		return false;
	}
}

/* changes the state of the specified card return false if card was up already. 
 * Throws an exception of type OutOfRange if an invalid Letter and Number combination was given.
 */
bool Board::turnFaceUp(const Letter& l, const Number& n) {
	if (outOfRange(l, n)) {
		throw OutOfRange();
	}
	
	//turn up the card
	for (int r = l * 4; r < l * 4 + 3; ++r) {
		Card* c = cardmatrix[l][n];
		matrix[r].replace(n * 4 + 2, 3, c->operator() (r - l * 4));
	}

	if (cardSide[l][n]) {
		return false;
	}
	else {
		cardSide[l][n] = UP;
		return true;
	}
}

/* changes the state of the specified card return false if card was down already. 
 * Throws an exception of type OutOfRange if an invalid Letter and Number combination was given.
 */
bool Board::turnFaceDown(const Letter& l, const Number& n) {
	if (outOfRange(l, n)) {
		throw OutOfRange();
	}

	//turn down the card
	for (int r = l * 4; r < l * 4 + 3; ++r) {
		matrix[r].replace(n * 4 + 2, 3, "ZZZ");
	}

	if (!cardSide[l][n]) {
		return false;
	}
	else {
		cardSide[l][n] = DOWN;
		return true;
	}
}

//RESET//
/* changes the state to all cards to be face down.  */
void Board::reset() {
	for (int i = 0; i < 25; ++i) {
		cardSide[i / 5][i % 5] = DOWN;
	}

	for (int boardRows = 0; boardRows < rows; ++boardRows) {
		for (int cardRows = 0; cardRows < 3; ++cardRows) {
			if (cardRows == 1) {
				matrix[boardRows * 4 + cardRows] = 'A' + boardRows;
				matrix[boardRows * 4 + cardRows] += " ";
			}
			else {
				matrix[boardRows * 4 + cardRows] = "  ";
			}
			for (int cardColumns = 1; cardColumns < 20; ++cardColumns) {
				if (cardColumns % 4 == 0 || (boardRows == 2 && cardColumns >= 9 && cardColumns <= 11)) {
					matrix[boardRows * 4 + cardRows] += " ";
				}
				else {
					matrix[boardRows * 4 + cardRows] += "z";
				}
			}
		}
	}
	matrix[20] = "  ";
	for (int column = 1; column < 20; ++column) {
		if (column % 4 == 0) {
			matrix[20] += " ";
		}
		else if (column % 2 == 0) {
			matrix[20] += std::to_string((column + 2) / 4);
		}
		else {
			matrix[20] += " ";
		}
	}

}

//TODO
std::ostream& operator<<(std::ostream &os, const Board &b) {
	b.print(os);//print the object b(board) to os
	return os;
}
void Board::print(std::ostream &os) const {
	for (auto& i : matrix) {
		os << i;
		os << "\n";
	}
}


//REV 2.0
/* returns a pointer to the card at a given location. 
 * Throws an exception of type OutOfRange if an invalid Letter and Number combination was given.
 */
Card* Board::getCard(const Letter& l, const Number& n) const {
	if (outOfRange(l, n))
		throw OutOfRange();
	else
		return cardmatrix[l][n];
}
/* updates the pointer to card at a given location. 
 * Throws an exception of type OutOfRange if an invalid Letter and Number combination was given. 
 */
void Board::setCard(const Letter& l, const Number& n, Card* c) {
	if (outOfRange(l, n))
		throw OutOfRange();
	cardmatrix[l][n] = c;
}
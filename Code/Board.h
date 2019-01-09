#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "CardDeck.h"
/**
 * Projet CSI 2772[A] Robert Laganiere
 * Board.h
 * holds an array of strings corresponding to the screen display of the game
 * @author Maxime Cote-Gagne(8851539) & Valentin Magot(8843488)
 *
 */
#include <iostream>
#include <exception>
//ENUM
enum Letter { A, B, C, D, E};
enum Number { ONE, TWO, THREE, FOUR, FIVE };
enum CardSide {DOWN, UP};


//Exceptions
struct NoMoreCards : public std::exception {
	const char * what() const throw () {
		return "NoMoreCards exception: no cards left in the deck";
	}
};
struct OutOfRange : public std::exception {
	const char * what() const throw () {
		return "OutOfRange exception: invalid letter and number combination provided";
	}
};


class Board{
	
private:
protected://need for the implement for ExpertDisplay
    static const int rows = 5, cols = 5;
	std::string matrix[21]; //ecran meme
	Card* cardmatrix[rows][cols]; //les cartes
	CardSide cardSide[rows][cols]; //le cote d'une carte

	//TEST
	inline bool outOfRange(const Letter& l, const Number& n) const { return (l >= rows || l < 0 || n >= cols || n < 0); };
	virtual void print(std::ostream &os) const;
public:
	Board();
	virtual ~Board() {};
	Board(const Board&) = delete;
	Board& operator=(const Board&) = delete;

	bool isFaceUp(const Letter&, const Number&) const;
	bool turnFaceUp(const Letter&, const Number&);
	bool turnFaceDown(const Letter&, const Number&);

	virtual void reset();

	//void print(std::ostream &os) const;//test
	friend std::ostream& operator<<(std::ostream &os, const Board &b);


    //rev2 du projet
	Card* getCard(const Letter&, const Number&) const;
	void setCard(const Letter&, const Number&, Card*);
};


#endif
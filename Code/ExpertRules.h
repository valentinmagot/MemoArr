/**
 * Projet CSI 2772[A] Robert Laganiere
 * ExpertRules.h
 * The cards or rather have some added meaning
 * @author Maxime Cote-Gagne(8851539) & Valentin Magot(8843488)
 *
 */
#ifndef EXPERTRULES_H
#define EXPERTRULES_H

#include "Rules.h"
#include "Board.h"


class ExpertRules : public Rules
{
private:
	Board * board;
	Card *block = nullptr;//Emmagisine dans un pointeur toutes les cartes blocked
public:
	ExpertRules() : Rules() {};
	~ExpertRules() {};
	bool isValid(const Game& g);//redefined from Rules!!
	bool roundOver(const Game& g);
	void set(Board *b) { board = b; };//Set the board, from the main, to the rules
};

#endif
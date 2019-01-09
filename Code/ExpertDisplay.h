/**
 * Projet CSI 2772[A] Robert Laganiere
 * ExpertDisplay.h
 * In this version, the rules are the same as in the base mode but the board with the array of cards is removed
 * Instead only the face up cards are shown in a row along with the position they came from. 
 * @author Maxime Cote-Gagne(8851539) & Valentin Magot(8843488)
 *
 */
#ifndef EXPERTDISPLAY_H
#define EXPERTDISPLAY_H

#include "Board.h"
#include <vector>
#include <iostream>



class ExpertDisplay : public Board
{
	friend std::ostream& operator<< (std::ostream&, const Board&);
protected:
	void print(std::ostream& os) const ;
	void faceUp(const Letter&, const Number&) ;
	void faceDown(const Letter&, const Number&) ;
	void reset() ;
public:
	ExpertDisplay() : Board() {};
	~ExpertDisplay() {};
};


#endif
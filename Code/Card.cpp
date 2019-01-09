/**
 * Projet CSI 2772[A] Robert Laganiere
 * Card.cpp
 * @author Maxime Cote-Gagne(8851539) & Valentin Magot(8843488)
 *
 */
#include <iostream>
#include "Card.h"

/*The public interface of Card is to include conversion operators to type FaceAnimal and  FaceBackground*/
std::string Card::operator() (const int row) const {
	if (row > 2) {
		return "";
	}
	if (row == 1) {
		char line[] = { _background, _animal, _background, '\0' };
		return std::string(line);
	}
	else {
		char line[] = { _background, _background, _background, '\0' };
		return std::string(line);
	}
	
}


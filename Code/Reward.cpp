/**
 * Projet CSI 2772[A] Robert Laganiere
 * Reward.cpp
 * @author Maxime Cote-Gagne(8851539) & Valentin Magot(8843488)
 *
 */
#include "Reward.h"
#include <iostream>


/*print a reward*/
std::ostream &operator << (std::ostream &os, const Reward &r) {
	os << r._number;
	return os;
}

//REV 2.0
/* conversion operators to type int returning the number of rubies*/
Reward::operator int() const {
	return _number;
}
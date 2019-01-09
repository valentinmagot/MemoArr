/**
 * Projet CSI 2772[A] Robert Laganiere
 * Reward.h
 * can take one of four possible values from 1 to 4 rubies.
 * A reward must also be printable with the insertion operator cout << reward.
 * @author Maxime Cote-Gagne(8851539) & Valentin Magot(8843488)
 *
 */
#ifndef REWARD_H
#define REWARD_H

#include <iostream>

class Reward{
	friend class RewardDeck;
private:
	int _number;
	//Reward(int number);
	Reward() {};
/*#if !TEST
	Reward(int number) {
		if (number <= 4 && number >= 1) {
			_number = number;
		}
		else {
			_number = number % 4;
			if (_number == 0) {
				_number = 1;
			}
		}
	};
#endif*/
public:
//#if TEST
	//friend class Player;
	Reward(int number){
		if (number <= 4 && number >= 1) {
			_number = number;
		}
		else {
			_number = number % 4;
			if (_number == 0) {
				_number = 1;
			}
		}
	};
//#endif
	Reward(const Reward&) = delete;
	Reward& operator=(const Reward&) = delete;
	//SOME TESTING//

	friend std::ostream &operator << (std::ostream &os, const Reward &r);

	//REV 2.0
	operator int()const;
};

#if TEST
static void test_reward() {
	std::cout << std::endl << "TEST REWARD"<< std::endl;
	Reward r1(0), r2(2), r3(3);
	std::cout << "Constructor: " << std::endl;
	std::cout << "r1: " << r1 << std::endl;
	std::cout << "r2: " << r2 << std::endl;
	std::cout << "r3: " << r3 << std::endl;
}
#endif


#endif
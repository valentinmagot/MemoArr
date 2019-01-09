/**
 * Projet CSI 2772[A] Robert Laganiere
 * RwardDeck.h
 * derived from Deck<Reward> with the corresponding properties to CardDeck
 * @author Maxime Cote-Gagne(8851539) & Valentin Magot(8843488)
 *
 */
#ifndef REWARDDECK_H
#define REWARDDECK_H


#include "reward.h"
#include "deck.h"
#include <vector>
#include <iterator>
#include <iostream>
class Reward;
class RewardDeck : public Deck<Reward>{//meme structure que CardDeck juste avec les noms Reward au lieu de Card    
private:

		static RewardDeck* rd;
        static std::vector<Reward*> deck;
	    int size = -1;


		RewardDeck();

    public:
		~RewardDeck();
        RewardDeck(const RewardDeck&) = delete;
        RewardDeck& operator=(const RewardDeck&) = delete;


        static RewardDeck& make_RewardDeck();
        virtual void shuffle();
        virtual Reward* getNext();
        virtual bool isEmpty() const;
};
#if TEST
#include <iostream>
static void test_rewarddeck() {
	std::cout << std::endl << "TEST REWARDDECK" << std::endl;
	RewardDeck *rd = &RewardDeck::make_RewardDeck();

	std::cout << "Shuffle:" << std::endl;
	rd->shuffle();
	while (!rd->isEmpty()) {
		Reward* r = rd->getNext();
		std::cout << *r << ", ";
	}
	if (rd->getNext() == nullptr) {
		std::cout << "nullptr"<< std::endl;
	}
	else {
		std::cout << "not empty"<< std::endl;
	}

	std::cout << "New deck:" << std::endl;
	RewardDeck* rd2 = &RewardDeck::make_RewardDeck();
	if (rd2->getNext() == nullptr) {
		std::cout << "nullptr, deck already created" << std::endl;
	}
	else {
		std::cout <<  "new deck existed!!! should not have WORK!!!!" << std::endl;
	}
}
#endif
#endif
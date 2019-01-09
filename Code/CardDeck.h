/**
 * Projet CSI 2772[A] Robert Laganiere
 *	derived from Deck<Card>
 * @author Maxime Cote-Gagne(8851539) & Valentin Magot(8843488)
 *
 */
#ifndef CARDDECK_H
#define CARDDECK_H

#include "deck.h"
#include "card.h"
#include <vector>
#include<iostream>
//exceptions
struct CardDeckAlreadyCreated : public std::exception {
	const char * what() const throw () {
		return "CardDeckAlreadyCreated exception: one CardDeck objects can be created";
	}
};

class CardDeck : public Deck<Card>{
    private:

		static CardDeck* cd;
        static std::vector<Card*> deck;
        int size = -1;

		CardDeck();

		
    public:

        ~CardDeck();
        CardDeck(const CardDeck& cd) = delete;
        CardDeck& operator= (const CardDeck& cd) = delete;

		static CardDeck& make_CardDeck();
        virtual void shuffle();
        virtual Card* getNext();
        virtual bool isEmpty() const;
};

#if TEST
static void test_carddeck() {
	std::cout << std::endl << "TEST CARDDECK" << std::endl;
	CardDeck* cd = &CardDeck::make_CardDeck();

	std::cout << "Shuffle:" << std::endl;
	cd->shuffle();
	while (!cd->isEmpty()) {
		Card& c = *(cd->getNext());
		std::cout << c(1) << ", ";
	}
	if (cd->getNext() == nullptr) {
		std::cout << "nullptr" << std::endl;
	}
	else {
		std::cout << "not empty" << std::endl;
	}

	std::cout << "New deck:" << std::endl;
	CardDeck* cd2 = &CardDeck::make_CardDeck();
	if (cd2->getNext() == nullptr) {
		std::cout<< "nullptr, deck already created" << std::endl;
	}
	else {
		std::cout << std::endl << "new deck existed!!! should not have WORK!!!!" << std::endl;
	}
}
#endif

#endif
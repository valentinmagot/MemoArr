/**
 * Projet CSI 2772[A] Robert Laganiere
 * CardDeck.cpp
 * @author Maxime Cote-Gagne(8851539) & Valentin Magot(8843488)
 *
 */
#include "carddeck.h"
#include <algorithm>//utilise pour random_shuffle
#include <random>
#include<ctime>
std::vector<Card*> CardDeck::deck;
CardDeck* CardDeck::cd = nullptr;//Pour le singleton

/*Create a deck of card in a deck vector*/
CardDeck::CardDeck(){
	for (auto colour : { FaceBackground::Blue, FaceBackground::Green, FaceBackground::Purple, FaceBackground::Red, FaceBackground::Yellow }) {
		for (auto animal : { FaceAnimal::Crab, FaceAnimal::Octopus, FaceAnimal::Penguin, FaceAnimal::Turtle, FaceAnimal::Walrus }) {
			deck.push_back(new Card(animal, colour));

		}
	}
}

/*Singleton*/
CardDeck& CardDeck::make_CardDeck() {//make factory, review after the demo with Joel

	if (CardDeck::cd == nullptr) {
		CardDeck::cd = new CardDeck();		
		cd->size = deck.size() - 1;
	} 
	return *cd;



}

/*destroy all card in deck and clear space*/
CardDeck::~CardDeck() {
	//delete cd;
	for (auto &i : deck) {
		delete i;
	}
	deck.clear();
}

/*shuffle the deck of card*/
void CardDeck::shuffle() {//shuffle finish
	if (!deck.empty()) {
		srand(unsigned(time(NULL)));
		std::random_shuffle(deck.begin(), deck.end());//std::random_shuffle is use CHECK!
	}
	
}


/*return the next card by pointer
*will return nullptr if no more cards are available
*/
Card* CardDeck::getNext() {
	//si le deck(card/reward) est vide -> nullptr, sinon on réduit son size en retournant la card/reward enlevé
	if (isEmpty()) {
		return nullptr;
	}
	else {
		Card* c = deck[size];
		size--;
		return c;
	}
}



/*returns true if the deck is empty*/
bool CardDeck::isEmpty() const {
	//si le deck est vide 
	if (size < 0) {
		return true;
	}
	else {
		return false;
	}
}
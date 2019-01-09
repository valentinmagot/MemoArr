/**
 * Projet CSI 2772[A] Robert Laganiere
 * Deck.h
 * class Deck<C> as an abstract factory class that will be used to create a set of cards or a set of rewards.
 *  The type parameter <C> is intended to be one of {Card|Reward}.
 * The class will need the following methods
 * @author Maxime Cote-Gagne(8851539) & Valentin Magot(8843488)
 *
 */
#ifndef DECK_H
#define DECK_H
template <class C> class Deck{
public:
	virtual ~Deck() {};//destructor a ne pas inlucre dans les derives, c'Est celui pour Deck

	virtual void shuffle() = 0; // Vous devez vous servir de la fonction std::random_shuffle de la bibliothèque standard. 
	virtual C* getNext() = 0;
	virtual bool isEmpty() const = 0;
};
#endif
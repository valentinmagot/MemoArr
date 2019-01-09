/**
 * Projet CSI 2772[A] Robert Laganiere
 * Card.h
 * can take a face of one of the five possible animals and one of the five background colours.
 * A card must also be “printable” as one string per row with the method
 * @author Maxime Cote-Gagne(8851539) & Valentin Magot(8843488)
 *
 */
#ifndef CARD_H
#define CARD_H
#include <string>

/*ENUM*/
enum FaceAnimal { Crab='C', Penguin='P', Octopus='O', Walrus='W', Turtle='T' };
enum FaceBackground { Red='r', Green='g', Purple='p', Blue='b', Yellow='y' };//change to lowercase letter

class Card {
	friend class CardDeck;
public:
	//enum FaceAnimal { Crab = 'C', Penguin = 'P', Octopus = 'O', Walrus = 'W', Turtle = 'T' };
	//enum FaceBackground { Red = 'r', Green = 'g', Purple = 'p', Blue = 'b', Yellow = 'y' };//change to lowercase letter

private:
	FaceAnimal _animal;
	FaceBackground _background;
	//int nRow = 3;
	//char face, colour;

#if TEST == 0
	Card(FaceAnimal animal, FaceBackground background) :
		_animal(animal), _background(background)
	{}
#endif

public:
#if TEST == 1
		Card(FaceAnimal animal, FaceBackground background) :
			_animal(animal), _background(background)
		{}
#endif
	//string row(int row);
	//int getNRows() const { return nRow; }
	/*Card(FaceAnimal animal, FaceBackground background):
		_animal(animal), _background(background)
		{}*/
		
	void getAnimal(FaceAnimal) const;//inline au lieu de void?
	void getBackground(FaceBackground) const;//inline au lieu de void?
	
	//CardDeck en a besoins
	Card(const Card& c) = delete; //ne peut pas être copié 
	Card& operator= (const Card& c) = delete; //ni assigné
	//

	~Card() {}//destructeur

	inline int getNRows() const { //trois rangee
		return 3;	
	}

	//REV 2.0
	std::string operator() (const int row) const;


	operator FaceAnimal() const { 
		return _animal;
	}

	operator FaceBackground() const { 
		return _background; 
	}
	//END REV2.0
	//void print();
};



/*
Card c(Penguin, Red);
	for (int i = 0; i < c.getNRows(); ++i) {
		std::cout << c(i) << std::endl;
	}
	*/

#if TEST
//enum FaceAnimal { Crab = 'C', Penguin = 'P', Octopus = 'O', Walrus = 'W', Turtle = 'T' };
//enum FaceBackground { Red = 'r', Green = 'g', Purple = 'p', Blue = 'b', Yellow = 'y' };
static void test_card() {
	std::cout << std::endl;
	std::cout << "TEST CARD" << std::endl;
	Card c(FaceAnimal::Penguin, FaceBackground::Red);
	for (int i = 0; i < c.getNRows(); ++i) {
		//std::string rowString = c(row);
		//std::cout << rowString << std::endl;
		std::cout << c(i) << std::endl;
	}
	std::cout << "Card colour: " << static_cast<char>(static_cast<FaceBackground>(c)) << std::endl;
	std::cout << "Card animal: " << static_cast<char>(static_cast<FaceAnimal>(c)) << std::endl;
}
#endif
#endif

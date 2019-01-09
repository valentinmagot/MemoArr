/**
 * Projet CSI 2772[A] Robert Laganiere
 * Player.h
 * combines all information for a player including name, 
 * side of the board (top, bottom, left or right) 
 * and has the current count of rubies.
 * @author Maxime Cote-Gagne(8851539) & Valentin Magot(8843488)
 *
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include "Reward.h"
#include "Test.h"
const std::string sideArray[] = {"Top","Right","Bot","Left"}; //rotation de joueur selon l'horloge
enum Side{top,right,bot,left};//Grille top,right,bot,left



class Player {
	private:
		std::string _name;//nom du joueur
		Side _boardSide;//utilise l'enum Side
		int _rubies;//nombre de rubie d'un joueur
		bool _active;//statut d'un joueur(a son tour de jouer ou non)
		bool _endOfGame;//partie terminé ou non
	public:

		Player(std::string name, Side side);//constructeur a 2 arguments avec nom du joueur et son cote du board
		Player(const Player&);//copie-constructeur
		~Player();//destructeur


		std::string getName() const;
		void setActive(bool);
		bool isActive() const;//const sinon on peut pas prendre la valeur...
		int getNRubies() const;
		void addReward(const Reward&);
		void setDisplayMode(bool endOfGame);

		//Rev 2.0
		Side getSide() const;

		friend std::ostream& operator<<(std::ostream&, const Player&);
};




#if TEST

static void test_player() {
	std::cout << "PLAYER CLASS TEST" << std::endl;
	Side side = top;
	Player playerOne("Joe", side);
	side = right;
	Player playerTwo("Maxime", side);
	side = bot;
	Player playerThree("Valentin", side);
	side = left;
	Player playerFour("Robert", side);
	std::cout << std::endl;

	std::cout << "isActive()" << std::endl;
	std::cout << playerOne.isActive() << " = " << playerOne;
	playerOne.setActive(true);
	std::cout << playerOne.isActive() << " = " << playerOne << std::endl;

	std::cout << "getSide()" << std::endl;
	std::cout << playerOne.getSide() << " = " << sideArray[playerOne.getSide()] <<std::endl;
	std::cout << std::endl;

	std::cout << "setDisplayMode()" << std::endl;
	std::cout << "endOfGame False:" << std::endl;
	std::cout << playerOne;
	std::cout << "endOfGame true:" << std::endl;
	playerOne.setDisplayMode(true);
	playerTwo.setDisplayMode(true);
	playerThree.setDisplayMode(true);
	playerFour.setDisplayMode(true);
	std::cout << playerOne;
	std::cout << std::endl;

	std::cout << "addReward()" << std::endl;
	Reward r1(1), r2(4), r3(3), r4(2);
	std::cout << playerOne;
	std::cout << playerTwo;
	std::cout << playerThree;
	std::cout << playerFour;

	playerOne.addReward(r1);
	std::cout << playerOne;
	playerTwo.addReward(r2);
	std::cout << playerTwo;
	playerThree.addReward(r3);
	std::cout << playerThree;
	playerFour.addReward(r4);
	std::cout << playerFour << std::endl;

	std::cout << "getNRubies()" << std::endl;
	std::cout << playerOne.getNRubies() << std::endl;

	std::cout << "getName()" << std::endl;
	std::cout << playerOne.getName();

}
#endif //second one
#endif //first one
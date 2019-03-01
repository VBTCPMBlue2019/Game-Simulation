// Game-Simulation.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
using namespace std;
#include <iostream>
#include <windows.h>
#include <string>

// Battle Mechanics
int endefeated = 0; //enemies defeated
int turn = 0; //even equals player move , odd equals enemy turn

//Character Info
string name;
double ATK = 10;
double DEF = 10;
double mHP = 10; //Max HP
double cHP = mHP; //Current HP
int movechoice;

// Enemy Info
string ename = "test";
double eATK;
double eDEF;
double emHP; //Max HP
double ecHP; //Current HP

// MovePower & DefPower
double atk; //Maximum HP removed from a move
double def; // Actual HP removed from player
double eatk; // same as atk, but for enemy
double edef; // same as def, but for enemy

//Name Prompt
int nameprompt(){ // gathers username
	int nameconfirm = 0;
	cout << "What is the name of your player? " << endl;
	do{
		getline(cin, name);
		cout << name << ", are you sure?(Yes = 1/No = 0)" << endl;
		cin >> nameconfirm;
	} while (nameconfirm == 0);
	return 0;
}
//Story
void story() {
	cout << "T";
	Sleep(100);
	cout << "h";
	Sleep(100);
	cout << "e ";
	Sleep(100);

	cout << "t";
	Sleep(100);
	cout << "o";
	Sleep(100);
	cout << "w";
	Sleep(100);
	cout << "n ";
	Sleep(100);

	cout << "n";
	Sleep(100);
	cout << "e";
	Sleep(100);
	cout << "e";
	Sleep(100);
	cout << "d";
	Sleep(100);
	cout << "s ";
	Sleep(100);

	cout << "y";
	Sleep(100);
	cout << "o";
	Sleep(100);
	cout << "u, ";
	Sleep(150);

	cout << name << "! " << endl;
	Sleep(750);

	cout << "There ";
	Sleep(200);
	cout << "are ";
	Sleep(200);
	cout << "monsters ";
	Sleep(200);
	cout << "enslaving ";
	Sleep(200);
	cout << "the ";
	Sleep(200);
	cout << "townsfolk. ";
	Sleep(200);

	cout << "Save ";
	Sleep(400);
	cout << "Textopia ";
	Sleep(400);
	cout << "from ";
	Sleep(400);
	cout << "the ";
	Sleep(400);
	cout << "monster ";
	Sleep(400);
	cout << "horde! " << endl;
	Sleep(2000);
	cout << "\n\n\n\n" << endl;

}
// Enemy Loader
void enloader() {
	if (endefeated == 0) {
		ename = "Goblin";
		eATK = 2;
		eDEF = 2;
		emHP = 10;
		ecHP = emHP;
	}
	else if (endefeated == 1) {
		ename = "Strong Goblin";
		eATK = 3;
		eDEF = 3;
		emHP = 11;
		ecHP = emHP;
	}
	else if (endefeated == 2) {
		ename = "Knight Goblin";
		eATK = 4;
		eDEF = 5;
		emHP = 14;
		ecHP = emHP;
	}
	else if (endefeated == 3) {
		ename = "King Goblin";
		eATK = 6;
		eDEF = 8;
		emHP = 16;
		ecHP = emHP;
	}
}
//Moveset & Attack
void charmoveset() {
	atk = 0;
	movechoice = 0;
	cout << "What move would you like to make?" << endl;
	cout << endl;
	cout << "___________________________________________________________________________________________" << endl;
	cout << "|1 - Basic Attack|2 - Strong Attack, but takes some HP|3 - Health Sack, which regens 4 HP!|" << endl;
	cout << "|________________|____________________________________|___________________________________|" << endl;
	do {
		cin >> movechoice;
		if (movechoice == 1) { // Basic Attack
			atk = .5 * ATK;
		}
		else if (movechoice == 2) { // Strong Attack
			atk = .75 * ATK; 
			cHP = cHP - .5;
		}
		else if (movechoice == 3) { // Health Sack
			cHP = cHP + 4.0;
			if (cHP > mHP) {
				cHP = mHP;
			}
		}
		else { // If movechoice is invalid, tell the user to make a valid move, then repeat what is in this massive do-while loop.
			cout << "Please make a valid move." << endl;
			movechoice = 0;
		}
	} while (movechoice == 0);
}
//Battle Mode
void battle() {
		bool enemydefeat = false;
		enloader();
		Sleep(500);
		turn = 0;
		cout << ename << " has appeared! He has " << emHP << " HP!" << endl; // Prints enemy is here code
		cout << "\n\n\n" << endl;
		do {
			do {
				cout << name << " , your HP is at " << cHP << "." << endl;
				charmoveset();
				edef = atk / eDEF; // Actual HP Removed = Maximum Potential HP Removed / Enemy DEF stat
				ecHP = ecHP - edef; // Enemy New Current HP = Enemy Old Current HP - Actual HP Removed
				turn++; 
			} while (turn % 2 == 0); // turn is even

			cout << ename << " has " << ecHP << " HP!" << endl;
			cout << "\n\n\n" << endl;
			Sleep(500);

			if (ecHP <= 0) { // If enemy is defeated, stop the current battle and continue
				bool enemydefeat = true;
				break;
			}

			else {
				//Enemy Attack
				do {
					eatk = (.45 * eATK); // Player Max HP Removed = .45 * Enemy ATK stat
					def = eatk / DEF; // Actual HP removed = Enemy Max HP Removed
					cHP = cHP - def; // Player New Current HP = Player Old Current HP - Actual HP Removed
					turn++;
				} while (turn % 2 != 0); // turn isn't even
			}

		} while (enemydefeat == false);
		endefeated++;
		cout << ename << " has been defeated!" << endl;
		cHP = mHP; // sets current HP to maximum HP
		Sleep(250);
		cout << "You applied a healing spell. " << name << " now has " << cHP << " HP!" << endl;
		cout << "\n\n\n\n\n\n" << endl;
}
//Order of Stuff
int main(){
	int i = 0;
	cout << "Welcome to TBG Adventures. We begin in:" << endl;
	Sleep(500);
	cout << "3" << endl;
	Sleep(500);
	cout << "2" << endl;
	Sleep(500);
	cout << "1" << endl;
	Sleep(500);
	nameprompt();
	story();
	do {
		battle();
		i++;
	} while (i < 3); // 3 battles
	cout << "Congratutlations! Textopia is saved from the monster horde!";
	cout << "\n\n\n\n\n\n\n\n\n\n" << endl;
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Game-Simulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "pch.h"
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
// Battle Mechanics
int endefeated = 0; //enemies defeated
int turn = 0; //even equals player move , odd equals enemy turn
int i = 1;
bool enemydefeat = false;
bool devtag = false;
bool easteregg1 = false;
int stage = 0; //tracks current stage of a boss fight

//Character Info
string name = " ";
unsigned long ATK = 10;
unsigned long  DEF = 10;
unsigned long  mHP = 10; //Max HP
unsigned long cHP = mHP; //Current HP
int movechoice;

// Enemy Info
string ename = "test";
double eATK;
double eDEF;
double emHP; //Max HP
double ecHP; //Current HP
double eACU;
bool auth = true;

// MovePower & DefPower
double atk; //Maximum HP removed from a move
double def; // Actual HP removed from player
double eatk; // same as atk, but for enemy
double edef; // same as def, but for enemy

//Name Prompt
int nameprompt(){ // gathers username
	int nameconfirm = 0;
	int namechange = 0;
	cout << "What is the name of your player? " << endl;
	do {
		getline(cin, name);
			if (name == "p") {
			devtag = true;
			cout << " (Developer mode activated! Enter values for character stats):" << endl;
			cin >> ATK;
			cin >> DEF;
			cin >> mHP;
			cout << "Now that you're probably overpowered would you like to change your name?" << endl;
			name = " ";
		}
		cout << name << ", are you sure?(Yes = 1/No = 0)" << endl;
		cin >> nameconfirm;
		if (name == "DeadFace") {
			cout << "I   ";
			Sleep(250);
			cout << "w o u l d n ' t   ";
			Sleep(250);
			cout << "d o   ";
			Sleep(250);
			cout << "t h a t   ";
			Sleep(250);
			cout << "i f   ";
			Sleep(250);
			cout << "I   ";
			Sleep(250);
			cout << "w e r e   ";
			Sleep(250);
			cout << "y o u   ";
			Sleep(250);
			cout << ". . ." << endl;
			Sleep(250);
			cout << "2 - There are plenty of other names to choose. (Change your name)" << endl << "1 - (I won't lie; only death awaits you at the end of this path)." << endl;
			cin >> namechange;
			
		}
		while(namechange == 2) {
			nameconfirm = 0;
			cout << "What shall you change it to?" << endl << " ";
			cin >> name;
			if (name != " ") {
				nameconfirm = 1;
				namechange = 0;
			}
			else if(name == " ") {
				cout << "Choose a non-single blank name" << endl;
			}
			
		}
			if (nameconfirm == 1 && name == "DeadFace") {
				cout << "F o o l i s h   ";
				Sleep(500);
				cout << "w a r r i o r . . .   ";
				Sleep(1000);
				cout << "y o u ' l l   ";
				Sleep(500);
				cout << "r e g r e t   ";
				Sleep(500);
				cout << "c r o s s i n g   ";
				Sleep(500);
				cout << "m e . . .  " << endl;
				Sleep(500);
				easteregg1 = true;
			}
			else if (nameconfirm == 1 && name != "DeadFace") {
				cout << "Smart choice. There are plenty of other names." << endl;
				break;
			}
				
	} while (nameconfirm == 0);
	return 0;
}
//Story
void story() {
	if (name == "DeadFace") {
		easteregg1 = 1;
	}
	else if (easteregg1 == 0) {
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
	else if (endefeated == 4) {
		ename = "Orc Grunt";
		eATK = 4;
		eDEF = 4;
		emHP = 20;
		ecHP = emHP;
		i = 0;
	}
	if (easteregg1 == true) {
		ename = "DeadFace, The Demon Slayer";
		stage = 1;
		eATK = 25;
		eDEF = 100;
		emHP = 1;
		ecHP = emHP;
	}
	else if (stage == 2) {
		ename = "DeadFace, The Demon Slayer";
		eATK = 50;
		eDEF = 50;
		emHP = 3;
		ecHP = emHP;
	}
	else if (stage == 3) {
		ename = "DeadFace, The Demon Slayer";
		eATK = 100;
		eDEF = 25;
		emHP = 5;
		ecHP = emHP;
	}
	else if (stage == 4) {
		ename = "DeadFace, The Demon Slayer";
		eATK = 200;
		eDEF = 10;
		emHP = 10;
		ecHP = emHP;
	}
	else if (stage == 5) {
		ename = "DeadFace, The Paradox";
		eATK = 999999999999999;
		eDEF = 999999999999999;
		emHP = 999999999999999;
		ecHP = emHP;
if (devtag == true && easteregg1 == true) {
			cout << "a h h . . .   t r y i n g   t o   c h e a t   t o   b e a t   m e ?" << endl << " y o u '  r e   g o i n g   t o   h a v e   a   b a d   t i m e . . . " << endl;
			stage = 5;
		}
	}
}

void charmoveset() {
	atk = 0;
	movechoice = 0;
	cout << "What move would you like to make?" << endl;
	cout << endl;
	cout << "________________________________________________________" << endl;
	cout << "|1-Light Attack  |2-Strong Attack  |3-Recover 4 HP     |" << endl;
	cout << "|________________|_________________|___________________|" << endl;
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
		else if (movechoice != 1 || movechoice != 2 || movechoice != 3) { // If movechoice is invalid, tell the user to make a valid move, then repeat what is in this massive do-while loop.
			cout << "Please make a valid move." << endl;
		}
	} while (movechoice == 0);
}
//Battle Mode
void battle() {
	bool playerdefeat = false;
	bool enemydefeat = false;
	enloader();
	Sleep(500);
	turn = 0;
	cout << ename << " has appeared! He has " << emHP << " HP!" << endl; // Prints enemy is here code
	cout << "\n\n\n" << endl;
	do {
		cout << name << " , your HP is at " << cHP << "." << endl;
		charmoveset();
		if (cHP <= 0) {
			cout << "oof that looked like it hurt";
			break;
			break;
		}
		else do {
			edef = atk / eDEF; // Actual HP Removed = Maximum Potential HP Removed / Enemy DEF stat
			ecHP = ecHP - edef; // Enemy New Current HP = Enemy Old Current HP - Actual HP Removed
			turn++;
		} while (turn % 2 == 0); // turn is even
		if (ecHP <= 0) { // If enemy is defeated, stop the current battle and continues to next encounter
			enemydefeat = true;
			endefeated++;
			break;
		}
		if (enemydefeat == true && stage == 1) {
			stage = 2;
		}
		if (enemydefeat == true && stage == 2) {
			stage = 3;
		}
		if (enemydefeat == true && stage == 3) {
			stage = 4;
		}
		if (enemydefeat == true && stage == 4) {
			stage = 5;
		}
		//Enemy Attack
		else do {
				eatk = (.45 * eATK); // Player Max HP Removed = .45 * Enemy ATK stat
				def = eatk / DEF; // Actual HP removed = Enemy Max HP Removed
				cHP = cHP - def; // Player New Current HP = Player Old Current HP - Actual HP Removed
				cout << ename << " has " << ecHP << " HP!" << endl;
				cout << "\n\n\n" << endl;
				Sleep(500);
				turn++;
			} while (turn % 2 != 0); // turn isn't even
	} while (enemydefeat == false);
	cout << ename << " has been defeated!" << endl;
	cHP = mHP; // sets current HP to maximum HP
	Sleep(250);
	cout << "You applied a healing spell. " << name << " now has " << cHP << " HP!" << endl;
	cout << "\n\n\n\n\n\n" << endl;
}
//experience and leveling up (W.I.P.)
void EXP() {

}
//Order of Stuff 
int main() {
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
	} while (i != 0); //unlimited encounters until you beat the final enemy; it then sets encounters to 0
	cout << "Congratutlations! Textopia is saved from the monster horde!";
	cout << "\n\n\n\n\n\n\n\n\n\n" << endl;
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
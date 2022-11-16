#pragma once

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

// function to print the slots as numbers between 1-9

void printSlots(int* slot1, int* slot2, int* slot3) {
	srand(time(NULL));
	*slot1 = rand() % 9 + 1;
	*slot2 = rand() % 9 + 1;
	*slot3 = rand() % 9 + 1;

	// printing actual layout and numbers to the console

	cout << endl << "---------------";
	cout << endl << " | " << *slot1;
	cout << " | " << *slot2;
	cout << " | " << *slot3 << " |";
	cout << endl << "---------------" << endl;
}
// function actually running the slot

int slotMachine() {
	Bank* bank = bank->getInstance();
	int slot1{ 0 };
	int slot2{ 0 };
	int slot3{ 0 };
	int playerSelection{ 0 };
	cout << "Welcome to the slot machine! Every spin is $5" << endl;
	// loop until user chooses to quit byt entering "2"
	while (playerSelection != 2) {
		// check to make sure balance is at least 5
		if (bank->checkCashBalance() >= 5) {
			bank->withdrawCash(5);
			// take player choice
			cout << endl << "1\tSpin the slot machine";
			cout << endl << "2\tQuit" << endl;
			cout << endl << "What would you like to do? ";
			cin >> playerSelection;
			switch (playerSelection) {
			case 1:
				// clear the screen before every print of the slots
				system("CLS");

				printSlots(&slot1, &slot2, &slot3);
				// check for 7 7 7
				if (slot1 == 7 && slot2 == 7 && slot3 == 7) {
					cout << endl << "   Jackpot!" << endl;
					bank->depositCash(500);
				}
				// check for three same number
				if (slot1 == slot2 && slot2 == slot3) {
					cout << endl << "   You Win!" << endl;
					bank->depositCash(100);
				}
				// check if two are the same number
				else if (slot1 == slot2 || slot2 == slot3 || slot1 == slot3) {
					cout << endl << "   You win!" << endl;
					bank->depositCash(5);
				}
				// if none are same, they lose $5
				else {
					cout << endl << "   You lose!" << endl;
				}
				// print the new balance after every spin
				cout << endl << "New balance is: $" << bank->checkCashBalance() << endl;
				// if they choose to quit, breaks loop
			case 2:
				break;
			}
		}
		// if they dont have minimum of $5, breaks
		else {
			cout << endl << "You're out of money, sorry!";
			break;
		}
	}
	return 0;
}

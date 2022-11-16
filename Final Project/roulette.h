#pragma once


#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void spin_roulette(int* win_num) {
	srand(time(NULL));
	*win_num = rand() % 35;

	cout << endl << "The winning number is: " << endl;
	cout << *win_num << endl;

}

int roulette() {
	Bank* bank = bank->getInstance();

	int bet_amount;
	int win_num;
	int bet_num;

	cout << "Welcome to Roulette!" << endl;

	//exit option
	do {
		cout << "Please enter bet amount or '0' to leave." << endl;
		cin >> bet_amount;
		//bet amount outcomes
		if (bet_amount == 0) {
			//pull intro function
			break;
		}
		else if (bet_amount > bank->checkCashBalance()) {
			cout << "You do not have enough money please go to the bank or bet less" << endl;
		}
		else {
			cout << "Enter number between 1 and 36 for bet or" << endl;
			cout << "'44' if betting on Red (Even) or '55' for Black(odd): " << endl;
			cin >> bet_num;
			if (bet_num > 36 && bet_num != 44 && bet_num != 55) {
				cout << "That is not a valid roulette number." << endl;
			}

			else {
				//take bet from bank
				bank->withdrawCash(bet_amount);

				//spin roulette
				spin_roulette(&win_num);
				if (bet_num == win_num) {
					bet_amount = 35 * bet_amount;
					cout << "You Won $" << bet_amount << '!' << endl;
					//add to bank

					bank->depositCash(bet_amount);

				}
				else if (win_num % 2 == 0 && bet_num == 44) {
					bet_amount = (2 * bet_amount);
					cout << "Red! \nYou Won $" << bet_amount << '!' << endl;
					//add to bank

					bank->depositCash(bet_amount);
				}
				else if (win_num % 2 == 1 && bet_num == 55) {
					bet_amount = (2 * bet_amount);
					cout << "Black! \nYou Won $" << bet_amount << '!' << endl;
					//add to bank

					bank->depositCash(bet_amount);
				}

				else {
					cout << "You Lost!" << endl;
				}
			}
		}
	} while (bet_amount != 0);

	return bank->checkCashBalance();
}

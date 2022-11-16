#include<iostream>
#include<chrono>
#include<thread>
#include "Bank.h" 
#include "slotMachine.h"
#include "roulette.h"


using namespace std;


//Setup the bank
Bank* Bank::instance = 0;


//Type out chars
void TypeOutStrings(char character, int numberOfTimes, int waitBetweenChar) {
    for (int i = 0; i < numberOfTimes; i++) {
        cout << character;
        this_thread::sleep_for(chrono::milliseconds(waitBetweenChar));
    }
    cout << endl;
}
//Type out Strings
void TypeOutStrings(string stringToType, int waitBetweenChar) {
    for (int i = 0; i < stringToType.length(); i++) {
        cout << stringToType[i];
        this_thread::sleep_for(chrono::milliseconds(waitBetweenChar));
    }
    cout << endl;
}


void Intro() {
    TypeOutStrings('*', 40, 20);
    TypeOutStrings('*', 40, 20);
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "            C A S I N O              \n";
    TypeOutStrings('*', 40, 20);
    TypeOutStrings('*', 40, 20);

    this_thread::sleep_for(chrono::milliseconds(1000));
    TypeOutStrings("Welcome to the Casino!\n\n\n", 25);
    this_thread::sleep_for(chrono::milliseconds(1000));
}

void GetPlayerDeposit() {
    //Get bank instance
    Bank* bank = bank->getInstance();

    TypeOutStrings("To begin, please enter the amount of \n", 25);
    TypeOutStrings("money you would like to start with:\n", 25);
    //Get bank instance
    //Deposit intial amount
    int depositAmount;
    cin >> depositAmount;
    if (depositAmount > 0) {
        bank->depositCash(depositAmount);
    }
    else {
        TypeOutStrings("Invalid Entry\n", 25);
        GetPlayerDeposit();
    }

}

void SelectGame() {
    //Get bank instance
    Bank* bank = bank->getInstance();


    //Game Scene Management
    cout << "\n\n";
    this_thread::sleep_for(chrono::milliseconds(1000));
    TypeOutStrings('*', 40, 20);
    TypeOutStrings("Please enter 1 to play roulette or 2 \n", 25);
    TypeOutStrings("2 to play the slots \n", 25);
   
    int gameSelection;
    cin >> gameSelection;
    system("cls");
    this_thread::sleep_for(chrono::milliseconds(50));
    if (gameSelection == 1) {
        roulette();
    }

    else if (gameSelection == 2) {
        slotMachine();
    }
    else {
        TypeOutStrings("Invalid Entry\n", 25);
        SelectGame();
    }
}


int main()
{
    //Get bank instance
    Bank* bank = bank->getInstance();

    Intro();
    GetPlayerDeposit();
    cout << "Your balance is $" << bank->checkCashBalance();
    while (bank->checkCashBalance() != 0) {
        system("cls");
        SelectGame();

    }
    cout << "You are broke. You lose!" << endl;
}

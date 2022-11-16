#pragma once
//Bank Singleton
class Bank {
    static Bank* instance;
    int cash;

    Bank() {
        cash = 0;
    }

public:
    static Bank* getInstance() {
        if (!instance)
            instance = new Bank;
        return instance;
    }

    int checkCashBalance() {
        return this->cash;
    }

    void withdrawCash(int _cash) {
        this->cash = cash - _cash;
    }

    void depositCash(int _cash) {
        this->cash = cash + _cash;
    }
};
//
// Created by User on 22.10.2020.
//

#ifndef N04_PRACTICE12_ACCOUNT_H
#define N04_PRACTICE12_ACCOUNT_H

#include <iostream>
#include <string>
using namespace std;

class Account{
private:
    int key;
public:
    string accountNumber;
    string fullName;
    string address;
    Account();
    Account(int key);
    Account(int key, string num, string name, string address);
    string info();
    int getKey();
    void setKey(string key);
    Account* getObjectByKey(int key);
    void printinfo();
};

#endif //N04_PRACTICE12_ACCOUNT_H

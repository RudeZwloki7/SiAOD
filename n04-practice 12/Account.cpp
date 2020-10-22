//
// Created by User on 22.10.2020.
//

#include "Account.h"

using namespace std;

Account::Account() {}

Account::Account(int key) {
    this->key = key;
}

Account::Account(int key, string num, string name, string address) {
    this->key = key;
    accountNumber = num;
    fullName = name;
    this->address = address;
}
string Account::info() {
    return to_string(key)+"/"+accountNumber+"/"+fullName+"/"+address;
}
void Account::printinfo() {
    cout<<"Account holder:\n\r"<<"\tID: "<< accountNumber << "\n\r\tFull name: "<<fullName << "\n\r\tAddress: "<< address <<"\n\r";
}
int Account::getKey() {
    return key;
}
void Account::setKey(string key) {
    this->key = stoi(key);
}

Account* Account::getObjectByKey(int key) {
    if (key == this->key) {
        return this;
    }
    return nullptr;
}
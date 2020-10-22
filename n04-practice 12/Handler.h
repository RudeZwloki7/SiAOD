//
// Created by User on 22.10.2020.
//

#ifndef N04_PRACTICE12_HANDLER_H
#define N04_PRACTICE12_HANDLER_H

#include "Account.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


class Handler{
private:
    string filename;
public:
    Handler();
    Handler(string filename);
    void makeTestData();
    void writeDataToFile(vector<Account> &data);
    void readDataFromFile(vector<Account> &data);
    Account findDataByKey(int key);
    bool updateDataAddressByKey(int key, string newAddress);
    bool deleteDataByKey(int key);
    void printAllData();
};

#endif //N04_PRACTICE12_HANDLER_H

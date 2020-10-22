//
// Created by User on 22.10.2020.
//

#include "Handler.h"

Handler::Handler() {
    this->filename = "file";
}

Handler::Handler(string filename) {
    this->filename = filename;
}

void Handler::makeTestData() {
    vector <Account> testData;
    Account acc1 = Account(1, "1042456", "John White", "HillWalleye, Blue st. 12");
    Account acc2 = Account(2, "1015123", "George Black", "London, Independence st. 7");
    Account acc3 = Account(3, "1452453", "Rick Decard", "Los-Angeles, Bladerunner st. 6");
    testData.push_back(acc1);
    testData.push_back(acc2);
    testData.push_back(acc3);
    writeDataToFile(testData);
}

void Handler::writeDataToFile(vector <Account> &data) {
    ofstream fout(filename);
    for (int i = 0; i < data.size(); i++) {
        fout << data.at(i).info();
        if (i != data.size() - 1) {
            fout << endl;
        }
    }
    //fout.close();
}

void Handler::readDataFromFile(vector<Account> &data) {
    ifstream fin;
    fin.open(filename);

    if (fin.is_open()) {
        data.clear();
        Account temp;
        string key;

        while (fin.good()) {
            getline(fin, key, '/');

            if (key.empty()||key=="\n") {
                break;
            } 

            temp.setKey(key);
            getline(fin, temp.accountNumber, '/');
            getline(fin, temp.fullName, '/');
            getline(fin, temp.address, '\n');
            data.push_back(temp);
        }
    } else {
        cout << "Can't open file " << filename << endl;
    }

    fin.close();
}

Account Handler::findDataByKey(int key) {
    vector<Account> data;
    readDataFromFile(data);
    for (int i =0; i<data.size();i++){
        if (key==data.at(i).getKey()){
            data.at(i).printinfo();
            return data.at(i);
        }
    }
    cout<<"Account holder not found"<<endl;
    return NULL;
}

bool Handler::updateDataAddressByKey(int key,string newAddress) {
    vector<Account> data;
    readDataFromFile(data);

    for (auto & i : data) {
        if (i.getKey() == key) {
            i.address = newAddress;
            writeDataToFile(data);
            return true;
        }
    }

    return false;
}

bool Handler::deleteDataByKey(int key) {
    vector<Account> data;
    readDataFromFile(data);
    if (data.size() < key) {
        return false;
    } else if (key == 1) {
        data.clear();
    } else {
        data[key - 1] = data.at(data.size() - 1);
        data.pop_back();
    }

    writeDataToFile(data);
    return true;
}

void Handler::printAllData() {
    vector<Account> data;
    readDataFromFile(data);
    for (auto & i : data) {
        i.printinfo();
    }
}


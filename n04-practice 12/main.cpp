#include <iostream>
#include <string>
#include "Handler.h"

int main() {
    string filename = "test.txt";
    Handler handler(filename);
    handler.makeTestData();

    cout<<"All records:\n";
    handler.printAllData();

    cout<<"Third record:"<<endl;
    handler.findDataByKey(3);

    cout<<"Update:"<<endl;
    handler.updateDataAddressByKey(1,"new address");
    handler.printAllData();

    cout<<"Delete second:"<<endl;
    handler.deleteDataByKey(2);

    handler.printAllData();
    return 0;
}

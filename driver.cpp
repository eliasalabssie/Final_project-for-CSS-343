#include <iostream>
#include <fstream>
#include "Blockbuster.h"

using namespace std;

int main(){
    Blockbuster b;

    b.PrintMovies();

    b.PrintCustomers();

    b.PrintCommands();

    b.ActivateCommands();

    //b.printHistory(9000);
    //b.printInventory();
    //for (auto& it: b.customers) {
    //    b.printHistory(it.first);
    //}

    //string line;
    //if (commands.is_open()){
    //    while (getline(commands, line)){
    //        cout << line << endl;
    //    }
    //    commands.close();
    //}
    //else{
    //    cout << "File not found." << endl;
    //}
    return 0;
}
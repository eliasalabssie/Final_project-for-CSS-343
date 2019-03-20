#include <iostream>
#include <fstream>
#include "Blockbuster.h"

using namespace std;

int main(){
    Blockbuster b;

    ifstream movies ("data4movies.txt");
    b.BuildMovies(movies);
    b.printInventory();

    ifstream customers ("data4customers.txt");
    b.BuildCustomers(customers);
    b.PrintCustomers();

    ifstream commands("data4commands.txt");
    b.BuildCommands(commands);
    b.PrintCommands();

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
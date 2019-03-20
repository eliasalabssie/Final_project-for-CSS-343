#include <iostream>
#include <fstream>
#include "Blockbuster.h"

using namespace std;

int main(){
    Blockbuster b;

    ifstream movies ("data4movies.txt");
    b.BuildMovies(movies);
    b.printInventory();
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
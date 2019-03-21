/** Lloyd Deng, Antong Cheng, Elias Alabssie
 * THIS PROGRAM COMPILES AT uw1-320-07.uwb.edu ON PORT 22,
 * WITH THE STATEMENT: g++ -std=c++11 *.cpp
 *
 * Driver file for Program 4.
 * This file initializes the Blockbuster object, which holds three sets, an unordered_map, and a vector. (From STL)
 * These structures control movie stocking, customer accounts, and customer commands.
 *
 * Initialization requires three files, which are listed in Blockbuster.cpp at lines 31, 35, 39.
 * data4movies.txt should detail the initial stocking of the Blockbuster movie database.
 * data4customers.txt should detail the initial customer accounts registered with Blockbuster.
 * data4commands.txt should detail the list of commands to be executed by the Blockbuster automation program.
 * Detailed syntax for these files can be found in assignment4.doc.
 *
 * Blockbuster's constructor automatically initializes the Blockbuster with these files.
 * activateCommands() will run through the commands database and execute them as specified in assignment4.doc.
 * Additional commands, printMovies();, printCustomers(); and printCommands(); are provided to read from the database.
 * All other functions are to aid with the initialization or execution process.
 */

#include <iostream>
#include <fstream>
#include "Blockbuster.h"

using namespace std;

int main(){
    Blockbuster b;

    //b.printMovies();
    //b.printCustomers();
    //b.printCommands();

    b.activateCommands();
    return 0;
}
//
// Created by lloyd on 2019.03.11.
//

#ifndef ASSIGNMENT4_BLOCKBUSTER_H
#define ASSIGNMENT4_BLOCKBUSTER_H

#include "movie.cpp"
#include "customer.cpp"
#include "command.cpp"

#include <set>
#include <vector>
#include <map>

using namespace std;

class Blockbuster {
public:
    Blockbuster();
    void printInventory();
    void printHistory(int ID);
    bool movieborrow(string title);
    bool moviereturn(string title);

private:
    vector<set<Movie>> movies;
    map<int, Customer> customers;
    vector<Command> commands;
};


#endif //ASSIGNMENT4_BLOCKBUSTER_H

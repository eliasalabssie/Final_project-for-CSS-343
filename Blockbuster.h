#ifndef ASSIGNMENT4_BLOCKBUSTER_H
#define ASSIGNMENT4_BLOCKBUSTER_H

#include "Customer.h"
#include "Command.h"
#include "Movie.h"
#include "Classic.h"
#include "Comedy.h"
#include "Drama.h"

#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Blockbuster {
    public:
        Blockbuster();
        Blockbuster(const Blockbuster &);
        ~Blockbuster();
        void printInventory();
        void printHistory(int);
        bool movieBorrow(const Command&);
        bool movieReturn(const Command&);
        void buildCommands(istream&);//puts the commands in the data structure
        void printCommands();
        void activateCommands();//iterates through commands data structure and makes respective calls
        void buildCustomers(istream&);//puts the customers in the data structure
        void printCustomers();
        void buildMovies(istream&);//puts the movies in the data structure
        void printMovies();
        void stringCleanUp(string &);

private:
        set<Classic> classics;
        set<Comedy> comedies;
        set<Drama> dramas;
        unordered_map<int, string> customers;
        vector<Command> commands;
};

#endif //ASSIGNMENT4_BLOCKBUSTER_H

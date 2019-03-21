/*
//--------------------------------------------------------------------------------
Assignment: Lab 4
Group Members: Lloyd Deng, Antong Cheng, Elias Alabssie
Date: March 20, 2019
//---------------------------------------------------------------------------------------

//------------------------ Drama.cpp -------------------------------------------------
//Parent: Movie
//Child: None

//description: implementation for the Drama class.

//-------------------------------------------------------------------------------------
*/


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
        void BuildCommands(istream&);//puts the commands in the data structure
        void PrintCommands();
        void ActivateCommands();//iterates through commands data structure and makes respective calls
        void BuildCustomers(istream&);//puts the customers in the data structure
        void PrintCustomers();
        void BuildMovies(istream&);//puts the movies in the data structure
        void PrintMovies();
        void stringCleanUp(string &);

private:
        set<Classic> classics;
        set<Comedy> comedies;
        set<Drama> dramas;
        unordered_map<int, string> customers;
        vector<Command> commands;
};

#endif //ASSIGNMENT4_BLOCKBUSTER_H

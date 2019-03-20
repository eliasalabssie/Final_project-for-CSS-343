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

//#include <iostream>
//#include <string>

#include "Blockbuster.h"

Blockbuster::Blockbuster(){
    vector<set<Movie>> movies;
    //set<Movie> x;
    //movies.insert(x);

    map<int, Customer> customers;
    vector<Command> commands;
}

Blockbuster::Blockbuster(const Blockbuster &other){
    this->movies = other.movies;
    this->customers = other.customers;
    this->commands = other.commands;
}

Blockbuster::~Blockbuster(){
    vector<set<Movie>> movies;
    map<int, Customer> customers;
    vector<Command> commands;
}

void Blockbuster::printInventory(){
    for (int g = 0; g < movies.size(); g++){ //iterating over three genres in Blockbuster
        for (Movie elem : movies[g]){
            cout << elem;
        }

        //for (int m = 0; m < movies[g].size(); m++){ //Doesn't work because elements in a set can't be referenced using [].
        //    cout << movies[g][m];
        //}
    }
}

void Blockbuster::printHistory(int ID){
    for (int command = 0; command < commands.size(); command++){
        if (ID = commands[command].getID()){
            cout << commands[command].toString();
        }
    }
}

bool Blockbuster::movieborrow(string title){
    for (int g = 0; g < movies.size(); g++){ //iterating over three genres in Blockbuster
        for (int m = 0; m < movies[g].size(); m++){
            for (Movie elem : movies[g]){
                if (elem.getTitle() == title){
                    elem.setStock(elem.getStock() - 1);
                }
                cout << elem;
            }
            //if (movies[g][m].getTitle() == title){
            //    movies[g][m].setStock(movies[g][m].getStock() - 1);
            //}
        }
    }
}

bool Blockbuster::moviereturn(string title){
    for (int g = 0; g < movies.size(); g++){ //iterating over three genres in Blockbuster
        for (int m = 0; m < movies[g].size(); m++){
            for (Movie elem : movies[g]){
                if (elem.getTitle() == title){
                    elem.setStock(elem.getStock() + 1);
                }
                cout << elem;
            }
            //if (movies[g][m].getTitle() == title){
            //    movies[g][m].setStock(movies[g][m].getStock() + 1);
            //}
        }
    }
}

void Blockbuster::BuildCommands(istream& inFile){
    char action;
    int ID;
    char media;
    char genre;

}

void Blockbuster::BuildCustomers(istream& inFile){
    int ID;
    string lastName, firstName, name;
    for(;;){
        inFile >> ID >> lastName >> firstName;
        name = firstName + " " + lastName;
        //Customer* temp = new Customer(ID, name);
        /*
            Now, insert temp into data structure
        */
        //temp = nullptr;
        if(inFile.eof()){
            break;
        }
    }
}

void Blockbuster::BuildMovies(istream& inFile){
    char genre;
    int stock, releaseMonth, releaseYear;
    string director, title, actor;
    string temp;
    for(;;){
        genre = inFile.get();
        if(genre == 'C'){
            getline(inFile, temp, ','); //flush the first comma
            getline(inFile, temp, ',');
            stock = atoi(temp.c_str());
            getline(inFile, temp, ',');
            director = temp;
            getline(inFile, temp, ',');
            title = temp;
            for(;;){
                getline(inFile, temp, ' ');
                string::const_iterator findInt = temp.begin();
                while(findInt != temp.end() && isdigit(*findInt)){
                    findInt++;
                }
                if(!temp.empty() && findInt == temp.end()){
                    releaseMonth = atoi(temp.c_str());
                    break;
                }
                else{
                    actor = actor + " " + temp;
                    continue;
                }
            }
            getline(inFile, temp, '\r');//flush return key
            releaseYear = atoi(temp.c_str());
            Classic input(stock, director, title, actor, releaseMonth, releaseYear);

            //cout << input << endl; //WORKS!!

            set<Classic> testing;//WORKS!!!
            testing.insert(input);
            for (auto m : testing){
                cout << m << endl;
            }

            //movies[0].insert(input);
            //for (Movie m : movies[0]){
            //    cout << m << ' ' << endl;
            //}

        }
        else if (genre == 'D'){
            getline(inFile, temp, ','); //flush the first comma
            getline(inFile, temp, ',');
            stock = atoi(temp.c_str());
            getline(inFile, temp, ',');
            director = temp;
            getline(inFile, temp, ',');
            title = temp;
            temp = inFile.get();
            releaseYear = atoi(temp.c_str());
            Drama input(stock, director, title, releaseYear);
            getline(inFile, temp, '\r');//flush return key
        }
        else if (genre == 'F'){
            getline(inFile, temp, ','); //flush the first comma
            getline(inFile, temp, ',');
            stock = atoi(temp.c_str());
            getline(inFile, temp, ',');
            director = temp;
            getline(inFile, temp, ',');
            title = temp;
            temp = inFile.get();
            releaseYear = atoi(temp.c_str());
            Drama input(stock, director, title, releaseYear);
            getline(inFile, temp, '\r');//flush return key
        }
        else{
            getline(inFile, temp, '\r');//flush return key
            continue;
        }
        if(inFile.eof()){
            break;
        }
    }
}
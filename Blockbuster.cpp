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

#include <iostream>
#include <string>

#include "Blockbuster.h"
#include "Movie.h"
#include "Classic.h"
#include "Comedy.h"
#include "Drama.h"

//Blockbuster::Blockbuster(){
//    movies;
//    customers;
//    commands;
//}
//
//Blockbuster::Blockbuster(Blockbuster &other){
//    this->movies = other.movies;
//    this->customers = other.customers;
//    this->commands = other.commands;
//}
//
//Blockbuster::~Blockbuster(){
//}
//
//void Blockbuster::printInventory(){
//    for (int g = 0; g < movies.size(); g++){ //iterating over three genres in Blockbuster
//        for (Movie elem : movies[g]){
//            cout << elem;
//        }
//
//        //for (int m = 0; m < movies[g].size(); m++){ //Doesn't work because elements in a set can't be referenced using [].
//        //    cout << movies[g][m];
//        //}
//    }
//}
//
//void Blockbuster::printHistory(int ID){
//    for (int command = 0; command < commands.size(); command++){
//        if (ID = commands[command].getID()){
//            cout << commands[command].toString();
//        }
//    }
//}
//
//bool Blockbuster::movieborrow(string title){
//    for (int g = 0; g < movies.size(); g++){ //iterating over three genres in Blockbuster
//        for (int m = 0; m < movies[g].size(); m++){
//            for (Movie elem : movies[g]){
//                if (elem.getTitle() == title){
//                    elem.setStock(elem.getStock() - 1);
//                }
//                cout << elem;
//            }
//            //if (movies[g][m].getTitle() == title){
//            //    movies[g][m].setStock(movies[g][m].getStock() - 1);
//            //}
//        }
//    }
//}
//
//bool Blockbuster::moviereturn(string title){
//    for (int g = 0; g < movies.size(); g++){ //iterating over three genres in Blockbuster
//        for (int m = 0; m < movies[g].size(); m++){
//            for (Movie elem : movies[g]){
//                if (elem.getTitle() == title){
//                    elem.setStock(elem.getStock() + 1);
//                }
//                cout << elem;
//            }
//            //if (movies[g][m].getTitle() == title){
//            //    movies[g][m].setStock(movies[g][m].getStock() + 1);
//            //}
//        }
//    }
//}

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
            getline(inFile, temp, ',');
            stock = atoi(temp.c_str());
            getline(inFile, temp, ',');
            director = temp;
            getline(inFile, temp, ',');
            title = temp;
            getline(inFile, temp, ',');
            /*
                now, what's left are the actor's name and month & year of the movie
                but we have to isolate them into 3 variables before proceeding
            */
            Classic input(stock, director, title, actor, releaseMonth, releaseYear);
            /*
                put the object in the data structure
            */
            getline(inFile, temp, '\n');
        }
        else if (genre == 'D'){
            getline(inFile, temp, ',');
            stock = atoi(temp.c_str());
            getline(inFile, temp, ',');
            director = temp;
            getline(inFile, temp, ',');
            title = temp;
            temp = inFile.get();
            releaseYear = atoi(temp.c_str());
            Drama input(stock, director, title, releaseYear);
            getline(inFile, temp, '\n');
        }
        else if (genre == 'F'){
            getline(inFile, temp, ',');
            stock = atoi(temp.c_str());
            getline(inFile, temp, ',');
            director = temp;
            getline(inFile, temp, ',');
            title = temp;
            temp = inFile.get();
            releaseYear = atoi(temp.c_str());
            Drama input(stock, director, title, releaseYear);
            getline(inFile, temp, '\n');
        }
        else{
            getline(inFile, temp, '\n');
            continue;
        }
        if(inFile.eof()){
            break;
        }
    }
}
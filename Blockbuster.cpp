//
// Created by lloyd on 2019.03.11.
//

#include "Blockbuster.h"

Blockbuster::Blockbuster(){
    set<Movie> movie = {};
    movies.push_back(movie);
    customers = {};
    commands = {};
}

void Blockbuster::printInventory(){
    for (int genre = 0; genre < movies.size(); genre++){ //iterating over three genres in Blockbuster
        for (int movie = 0; movie < movies[genre].size(); movie++){
            cout << movies[genre][movie];
        }
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
    for (int genre = 0; genre < movies.size(); genre++){ //iterating over three genres in Blockbuster
        for (int movie = 0; movie < movies[genre].size(); movie++){
            if (movies[genre][movie].getTitle = title){
                movies[genre][movie].setStock(movies[genre][movie].getStock() - 1);
            }
        }
    }
}

bool Blockbuster::moviereturn(string title){
    for (int genre = 0; genre < movies.size(); genre++){ //iterating over three genres in Blockbuster
        for (int movie = 0; movie < movies[genre].size(); movie++){
            if (movies[genre][movie].getTitle = title){
                movies[genre][movie].setStock(movies[genre][movie].getStock() + 1);
            }
        }
    }
}
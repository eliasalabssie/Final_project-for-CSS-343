//
// Created by lloyd on 2019.03.11.
//

#include "Blockbuster.h"

Blockbuster::Blockbuster(){
    movies;
    customers;
    commands;
}

void Blockbuster::printInventory(){
    set<int> x;
    x.insert(9);
    x.insert(8);
    for (int p : x){
        cout << p;
    }

    //cout << x[0];

    for (int g = 0; g < movies.size(); g++){ //iterating over three genres in Blockbuster
        for (Movie elem : movies[g]){
            cout << elem;
        }

        for (int m = 0; m < movies[g].size(); m++){
            //cout << movies[g][m];
            int x = *std::next(movies.begin(), m);
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
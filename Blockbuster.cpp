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
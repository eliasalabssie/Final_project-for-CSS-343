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
    map<int, string> customers;
    //map<int, Customer> customers;
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
    string title;
    string director;
    string actor;
    int month;
    int year;
    string flush;
    string temp;

    for(;;){
        inFile >> action;

        if (action == 'I') {
            Command insert(action);
            commands.push_back(insert);
        }
        else if (action == 'H') {
            getline(inFile, temp);
            ID = stoi(temp);
            Command insert(action, ID);
            commands.push_back(insert);

        }
        else if (action == 'B' | action == 'R') {
            inFile >> ID >> media >> genre;

            if (genre == 'C'){
                inFile >> month >> year;
                getline(inFile, temp);
                actor = temp;

                Command insert(action, ID, media, genre, month, year, actor);
                commands.push_back(insert);
            }
            else if (genre == 'D'){
                getline(inFile, temp, ',');
                director = temp;
                getline(inFile, temp, ',');
                title = temp;

                Command insert(action, ID, media, genre, director, title);
                commands.push_back(insert);
            }
            else if (genre == 'F'){
                getline(inFile, temp, ',');
                title = temp;
                inFile >> year;

                Command insert(action, ID, media, genre, title, year);
                commands.push_back(insert);
            }
            else{
                cout << "Invalid video code." << endl;
                getline(inFile, flush, '\n');//no nonsense
            }
        }
        else {
            cout << "Invalid action code." << endl;
            getline(inFile, flush, '\n');//no nonsense
        }

        if(inFile.eof()){
            break;
        }
    }
}

void Blockbuster::PrintCommands() {
    for (Command c : commands){
        cout << c << endl;
    }
}

void Blockbuster::BuildCustomers(istream& inFile){
    int ID;
    string lastName, firstName, name;
    for(;;){
        inFile >> ID >> lastName >> firstName;
        name = firstName + " " + lastName;
        //Customer* temp = new Customer(ID, name);
        //customers.insert(pair<int, Customer>(ID, temp);
        Customer insert(ID, name);
        //customers.insert(pair<int, Customer>(ID, insert));
        //customers[ID] = insert;
        customers[ID] = name;
        //temp = nullptr;
        if(inFile.eof()){
            break;
        }
    }
}

void Blockbuster::PrintCustomers(){
    for(auto it = customers.cbegin(); it != customers.cend(); ++it) {
        cout << it->first << " " << it->second << endl;
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
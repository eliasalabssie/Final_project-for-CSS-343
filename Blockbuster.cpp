/** Lloyd Deng, Antong Cheng, Elias Alabssie
 * Blockbuster structure for Program 4.
 * Blockbuster holds three sets, an unordered_map, and a vector. (From STL)
 * These structures control movie stocking, customer accounts, and customer commands.
 *
 * Initialization requires three files, which are listed at lines 31, 35, 39.
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

Blockbuster::Blockbuster(){
    cout << "Initializing Blockbuster." << endl << endl;

    set<Classic> classics;
    set<Comedy> comedies;
    set<Drama> dramas;
    unordered_map<int, string> customers;
    vector<Command> commands;

    ifstream data4movies ("data4movies.txt");
    cout << "Building movies database." << endl;
    buildMovies(data4movies);

    ifstream data4customers ("data4customers.txt");
    cout << "Building customers database." << endl;
    buildCustomers(data4customers);

    ifstream data4commands("data4commands.txt");
    cout << "Building commands database." << endl;
    buildCommands(data4commands);
}

Blockbuster::Blockbuster(const Blockbuster &other){
    this->classics = other.classics;
    this->comedies = other.comedies;
    this->dramas = other.dramas;
    this->customers = other.customers;
    this->commands = other.commands;
}

Blockbuster::~Blockbuster(){
    set<Classic> classics;
    set<Comedy> comedies;
    set<Drama> dramas;
    unordered_map<int, string> customers;
    vector<Command> commands;
}

void Blockbuster::printInventory() {
    for (Classic C : classics){
        cout << C << ' ' << endl;
    }
    for (Drama D : dramas){
        cout << D << ' ' << endl;
    }
    for (Comedy F : comedies){
        cout << F << ' ' << endl;
    }
    cout << endl;
}

void Blockbuster::printHistory(int ID){
    //cout << "Calling printHistory" << endl;
    for (Command c : commands){
        if (c.getID() == ID && c.getAction() != 'H') {
            cout << c << endl;
        }
    }
    cout << endl;
}

bool Blockbuster::movieBorrow(const Command& borrow){
	if (borrow.getGenre() == 'C'){
		for(Classic c : classics){
			if(c.getMonth() == borrow.getMonth() && c.getYear() == borrow.getYear()
               && c.getActor() == borrow.getActor()){
			    if (c.getStock() - 1 < 0){ //First, ensure we have stock available.
			        cout << c.getTitle() << " is out of stock. We won't be able to process " << customers[borrow.getID()] << "'s borrow request." << endl;
			        return false;
			    }
			    else{ //If we do have stock:
                    // c.setStock(c.getStock() - 1); //Elements of set may not be modified
                    Classic insert = c; //Instead, deep copy
                    classics.erase(c); //Remove original
                    insert.setStock(insert.getStock() - 1); //Modify copy
                    classics.insert(insert); //Insert copy
                    return true; //Borrow successful.
                }
            }
        }
    }
    else if (borrow.getGenre() == 'F'){
        for(Comedy f : comedies){
            if(f.getTitle() == borrow.getTitle() && f.getYear() == borrow.getYear()){
                if (f.getStock() - 1 < 0){ //First, ensure we have stock available.
                    cout << f.getTitle() << " is out of stock. We won't be able to process " << customers[borrow.getID()] << "'s order." << endl;
                    return false;
                }
                else {
                    Comedy insert = f;
                    comedies.erase(f);
                    insert.setStock(insert.getStock() - 1);
                    comedies.insert(insert);
                    return true;
                }
            }
        }
    }
    else if (borrow.getGenre() == 'D'){
        for(Drama d : dramas){
            if(d.getDirector() == borrow.getDirector() && d.getTitle() == borrow.getTitle()){
                if (d.getStock() - 1 < 0){ //First, ensure we have stock available.
                    cout << d.getTitle() << " is out of stock. We won't be able to process " << customers[borrow.getID()] << "'s order." << endl;
                    return false;
                }
                else {
                    Drama insert = d;
                    dramas.erase(d);
                    insert.setStock(insert.getStock() - 1);
                    dramas.insert(insert);
                    return true;
                }
            }
        }
    }
    else{
        cout << "incorrect data and/or incorrect command at line: " << borrow.toString() << endl;
        return false;
    }
}

bool Blockbuster::movieReturn(const Command& other){
    if (other.getGenre() == 'C'){
        for(Classic c : classics){
            if(c.getMonth() == other.getMonth() && c.getYear() == other.getYear()
               && c.getActor() == other.getActor()){
                if (c.getStock() + 1 > 10) { //Ensure nobody is returning more movies than they borrowed.
                    cout << c.getTitle() << " exceeds the amount of initial stock. We won't be able to process "
                         << customers[other.getID()] << "'s order." << endl;
                    return false;
                }
                else{
                    // c.setStock(c.getStock() - 1); //Elements of set may not be modified
                    Classic insert = c; //Instead, deep copy
                    classics.erase(c); //Remove original
                    insert.setStock(insert.getStock() + 1); //Modify copy
                    classics.insert(insert); //Insert copy
                    return true; //Return successful.
                }
            }
        }
    }
    else if (other.getGenre() == 'F'){
        for(Comedy f : comedies){
            if(f.getTitle() == other.getTitle() && f.getYear() == other.getYear()){
                if (f.getStock() + 1 > 10) {
                    cout << f.getTitle() << " exceeds the amount of initial stock. We won't be able to process "
                         << customers[other.getID()] << "'s order." << endl;
                    return false;
                }
                else{
                    Comedy insert = f;
                    comedies.erase(f);
                    insert.setStock(insert.getStock() + 1);
                    comedies.insert(insert);
                    return true;
                }
            }
        }
    }
    else if (other.getGenre() == 'D') {
        for (Drama d : dramas) {
            if (d.getDirector() == other.getDirector() && d.getTitle() == other.getTitle()) {
                if (d.getStock() + 1 > 10) {
                    cout << d.getTitle() << " exceeds the amount of initial stock. We won't be able to process "
                         << customers[other.getID()] << "'s order." << endl;
                    return false;
                }
            } else {
                Drama insert = d;
                dramas.erase(d);
                insert.setStock(insert.getStock() + 1);
                dramas.insert(insert);
                return true;
            }
        }
    }
    else{
        cout << "incorrect data and/or incorrect command in data4commands.txt at line: " << other.toString() << endl;
        return false;
    }
}

void Blockbuster::buildCommands(istream& inFile){
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
    bool movieOwned = false;

    for(;;){
        inFile >> action;

        if(inFile.eof()){
            cout << endl;
            break;
        }

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

            if (customers.count(ID) <= 0){
                cout << "Customer ID does not exist within database: " << ID << endl;
            }
            if (media != 'D'){
                cout << "Unsupported Media type: " << media << endl;
            }
            if (genre == 'C'){
                inFile >> month >> year;
                getline(inFile, temp);
                actor = temp;

                stringCleanUp(actor);

                for(Classic c : classics) {
                    if (c.getMonth() == month && c.getYear() == year && c.getActor() == actor) { //ensure the movie exists within our database.
                        Command insert(action, ID, media, genre, month, year, actor);
                        commands.push_back(insert);
                        movieOwned = true;
                    }
                }
                if (movieOwned == false){
                    cout << "Blockbuster does not own a movie from " << month << " " << year << " starring " << actor << "." << endl;
                }
                movieOwned = false;
            }
            else if (genre == 'D'){
                getline(inFile, temp, ',');
                director = temp;
                getline(inFile, temp, ',');
                title = temp;

                stringCleanUp(director);
                stringCleanUp(title);

                for(Drama d : dramas) {
                    if (d.getDirector() == director && d.getTitle() == title) { //ensure the movie exists within our database.
                        Command insert(action, ID, media, genre, director, title);
                        commands.push_back(insert);
                        movieOwned = true;
                    }
                }
                if (movieOwned == false){
                    cout << "Blockbuster does not own a movie by " << director << " titled " << title << "." << endl;
                }
                movieOwned = false;
            }
            else if (genre == 'F'){
                getline(inFile, temp, ',');
                title = temp;
                inFile >> year;

                stringCleanUp(title);

                for(Comedy f : comedies) {
                    if (f.getTitle() == title && f.getYear() == year) { //ensure the movie exists within our database.
                        Command insert(action, ID, media, genre, title, year);
                        commands.push_back(insert);
                        movieOwned = true;
                    }
                }
                if (movieOwned == false){
                    cout << "Blockbuster does not own a movie titled " << title << " from " << year << "." << endl;
                }
                movieOwned = false;
            }
            else{
                getline(inFile, temp, '\n');//no nonsense
                cout << "Invalid video code in data4commands.txt at line: " << action << " "
                    << genre << " " << temp << endl;
            }
        }
        else {
	        getline(inFile, temp, '\n');//no nonsense
            cout << "Invalid action code in data4commands.txt at line: " << action << " " << temp << endl;
        }
    }
}

void Blockbuster::printCommands() {
    //cout << "Calling printCommands" << endl;
    for (Command c : commands){
        cout << c << endl;
    }
    cout << endl;
}

void Blockbuster::activateCommands() {
    cout << "Blockbuster opening; running commands." << endl;
    for (Command c : commands){
        if (c.getAction() == 'B'){
            movieBorrow(c);
        }
        else if (c.getAction() == 'R'){
            movieReturn(c);
        }
        else if (c.getAction() == 'I'){
            printInventory();
        }
        else if (c.getAction() == 'H'){
            printHistory(c.getID());
        }
        else{
            cout << "Invalid action code: " << c << endl;
        }
    }
}

void Blockbuster::buildCustomers(istream& inFile){
    int ID;
    string lastName, firstName, name;

    for(;;){
        inFile >> ID >> lastName >> firstName;
        name = firstName + " " + lastName;
        Customer insert(ID, name);
        customers[ID] = name;

        if(inFile.eof()){
            cout << endl;
            break;
        }
    }
}

void Blockbuster::printCustomers(){
    //cout << "Calling printCustomers" << endl;
    for(auto it = customers.cbegin(); it != customers.cend(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
    cout << endl;
}

void Blockbuster::buildMovies(istream& inFile){
    char genre;
    int stock, releaseMonth, releaseYear;
    string director, title, actor;
    string temp;

    for(;;){
        genre = inFile.get();

        if(inFile.eof()){
            cout << endl;
            break;
        }

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
            getline(inFile, temp, '\n');//flush return key

            releaseYear = atoi(temp.c_str()); //cleanup
            stringCleanUp(director);
            stringCleanUp(title);
            stringCleanUp(actor);

            Classic input(stock, director, title, actor, releaseMonth, releaseYear); //create classic object
            actor = ""; //clear buffer
            classics.insert(input); //insert classic object into data structure
        }
        else if (genre == 'D'){
            getline(inFile, temp, ','); //flush the first comma
            getline(inFile, temp, ',');
            stock = atoi(temp.c_str());
            getline(inFile, temp, ',');
            director = temp;
            getline(inFile, temp, ',');
            title = temp;
            getline(inFile, temp);

            releaseYear = atoi(temp.c_str()); //cleanup
            stringCleanUp(director);
            stringCleanUp(title);

            Drama input(stock, director, title, releaseYear); //create drama object
            dramas.insert(input); //insert drama object into data structure
        }
        else if (genre == 'F'){
            getline(inFile, temp, ','); //flush the first comma
            getline(inFile, temp, ',');
            stock = atoi(temp.c_str());
            getline(inFile, temp, ',');
            director = temp;
            getline(inFile, temp, ',');
            title = temp;
            getline(inFile, temp);

            releaseYear = atoi(temp.c_str()); //cleanup
            stringCleanUp(director);
            stringCleanUp(title);

            Comedy input(stock, director, title, releaseYear); //create comedy object
            comedies.insert(input); //insert comedy object into data structure
        }
        else{
            cout << "Invalid video code in data4movies.txt at line: " << genre << " " << temp << endl;
            getline(inFile, temp, '\n');//flush return key
        }
    }
}

void Blockbuster::printMovies() {
    cout << endl;
    for (Classic c : classics){
        cout << c << ' ' << endl;
    }
    for (Drama d : dramas){
        cout << d << ' ' << endl;
    }
    for (Comedy f : comedies){
        cout << f << ' ' << endl;
    }
    cout << endl;
}

void Blockbuster::stringCleanUp(string &s) {
    while (!s.empty() && s[0] == ' ') {
        s = s.substr(1, s.size()); //remove spaces at beginning of string
    }
    while (!s.empty() && (s[s.size() - 1] == '\r' | s[s.size() - 1] == '\n')) {
        s = s.substr(0, s.size() - 1); //remove return carriage and/or newline character at end of string
    }
    while (!s.empty() && s[s.size()] == ' ') {
        s = s.substr(0, s.size()); //remove spaces at end of string
    }
}
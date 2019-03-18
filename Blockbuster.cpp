#include "Blockbuster.h"
Blockbuster::Blockbuster(){
}

Blockbuster::~Blockbuster(){
}

void Blockbuster::BuildCommands(std::ifstream& inFile){
	char action;
	int ID;
	char media;
	char genre;


}

void Blockbuster::BuildCustomers(std::ifstream& inFile){
	int ID;
	std::string lastName, firstName, name;
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

void Blockbuster::BuildMovies(std::ifstream& inFile){
	char genre;
	int stock, releaseMonth, releaseYear;
	std::string director, title, actor;
	std::string temp;
	for(;;){
		genre = inFile.get();
		if(genre == 'C'){
			std::getline(inFile, temp, ',');
			stock = atoi(temp.c_str()));
			std::getline(inFile, temp, ',');
			director = temp;
			std::getline(inFile, temp, ',');
			title = temp;
			std::getline(inFile, temp, ',');
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
			std::getline(inFile, temp, ',');
			stock = atoi(temp.c_str()));
			std::getline(inFile, temp, ',');
			director = temp;
			std::getline(inFile, temp, ',');
			title = temp;
			temp = inFile.get();
			releaseYear = atoi(temp.c_str()));
			Drama input(stock, director, title, releaseYear);
			getline(inFile, temp, '\n');
		}
		else if (genre == 'F'){
			std::getline(inFile, temp, ',');
			stock = atoi(temp.c_str()));
			std::getline(inFile, temp, ',');
			director = temp;
			std::getline(inFile, temp, ',');
			title = temp;
			temp = inFile.get();
			releaseYear = atoi(temp.c_str()));
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

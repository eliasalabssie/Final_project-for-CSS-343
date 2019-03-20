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

#include <sstream>
#include "Drama.h"

//------------------------------------ Drama -----------------------------------------
// Description: empty construct of Drama class
//-----------------------------------------------------------------------------------
Drama::Drama(){
	this->setGenre('c');
	this->setStock(0);
	this->setDirector("");
	this->setTitle("");
	this->setYear(-1);
}

//---------------------------------------- Drama(int, string, string, string)-------------
// Description: construct Drama class from director and year published
// -----------------------------------------------------------------------------------------
Drama::Drama(int stock, string director, string title, int year){
	this->setGenre('c');
	this->setStock(stock);
	this->setDirector(director);
	this->setTitle(title);
	this->setYear(year);
}

//---------------------------------------- Drama(Drama&)------------------------------
// Description: construct Drama class from another Drama object
//-------------------------------------------------------------------------------------
Drama::Drama(const Drama& other){
	this->setGenre(other.getGenre());
	this->setStock(other.getStock());
	this->setDirector(other.getDirector());
	this->setTitle(other.getTitle());
	this->setYear(other.getYear());
}

//---------------------------------------- ~Drama ------------------------------------
// Description: destructs the Drama object
//-------------------------------------------------------------------------------------
Drama::~Drama(){
	this->setGenre('c');
	this->setStock(0);
	this->setDirector("");
	this->setTitle("");
	this->setYear(-1);
}

//---------------------------------------- getDirector -----------------------------
// Description: returns the director of the Movie
//-------------------------------------------------------------------------------------
string Drama::getDirector() const{
	return director;
}

//---------------------------------------- getYear -----------------------------
// Description: returns the year that the Movie published
//-------------------------------------------------------------------------------------
int Drama::getYear() const{
	return year;
}

//---------------------------------------- setDirector -----------------------------
// Description: sets the director data member
//-------------------------------------------------------------------------------------
void Drama::setDirector(string director){
	this->director = director;
}

//---------------------------------------- setYear ----------------------------------
// Description: sets the year to the argument year
//-------------------------------------------------------------------------------------
void Drama::setYear(int year){
	this->year = year;
}

//--------------------------------- operator== ----------------------------------------------
//description: compare two Drama objects
//Pre: Drama movies with the same director and title but different year of release. are
//considered to be different(for inventory purpuse).
//--------------------------------------------------------------------------------------------
bool Drama::operator==(const Drama& other) const{
	return (getDirector() == other.getDirector()) &&
		   (getTitle() == other.getTitle()) &&
		   (getYear() == other.getYear());
}

//------------------------------------- operator != -----------------------------------------
//description: compare two Drama objects
//Pre: Drama movies with the same director and title but different year of release. are
//considered to be different(for inventory purpuse).
//--------------------------------------------------------------------------------------------
bool Drama::operator!=(const Drama& other) const{
	return !(*this == other);
}

//------------------------------------- operator > -----------------------------------------
//description: compare two Drama objects
//Pre: Drama movies with the same director and title but different year of release. are
//considered to be different(for inventory purpuse).
//--------------------------------------------------------------------------------------------
bool Drama::operator>(const Drama& other) const{
	//compare by director
	if (this->getDirector() > other.getDirector()){
		return true;
	}

	//compare by title
	else if(this->getDirector() == other.getDirector()){
		if(this->getTitle() > other.getTitle()){
			return true;
		}
	}

	return false;
}


//------------------------------------- operator < -----------------------------------------
//description: compare two Drama objects
//Pre: Drama movies with the same director and title but different year of release. are
//considered to be different(for inventory purpuse).
//--------------------------------------------------------------------------------------------
bool Drama::operator<(const Drama &other)const{
	return !(*this > other | *this == other);
}

//------------------------------------ operator<<  --------------------------------------------
ostream& operator<<(ostream &o, Drama &other){
	o << other.toString();
	return o;
}

// -------------------------- operator>> ---------------------------------------
istream& operator>>(istream &i, Drama &other){
	//i >> movie.genre >> movie.stock >> movie.title; //TODO
	return i;
}

//---------------------------------------- isIncomplete --------------------------
//Helper method to ensure that a Drama Movie is proper
//----------------------------------------------------------------------------------------
bool Drama::isIncomplete() const{
	return (getGenre() != 'f') || (getStock() < 0) || (getDirector().compare("") == 0) ||
		   (getTitle().compare("") == 0);
}

//---------------------------------------- toString --------------------------
//outputs string format of a Drama Movie object
//----------------------------------------------------------------------------------------
string Drama::toString() const{
	if(isIncomplete()){
		return "";
	}

	string genreString(1, getGenre());
	string stockString = static_cast<ostringstream*>( &(ostringstream() << getStock()) )->str();
	string yearString = static_cast<ostringstream*>( &(ostringstream() << getYear()) )->str();

	return  genreString + " " + stockString + " " + getDirector() + " " + getTitle() + " "  + yearString;
}

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

#include"Drama.h"
#include <sstream>

//---------------------------------------- Drama() ------------------------------------------
// default constructor
//-----------------------------------------------------------------------------------------
Drama::Drama(){
	this->setGenre('c');
	this->setStock(0);
	this->setDirector("");
	this->setTitle("");
	this->setYear(-1);
}

//---------------------------------------- Drama(int, string, string, string)-------------
// constructor with fields
//-----------------------------------------------------------------------------------------
Drama::Drama(int stock, string director, string title, int year){
	this->setGenre('c');
	this->setStock(stock);
	this->setDirector(director);
	this->setTitle(title);
	this->setYear(year);
}

//---------------------------------------- Drama(Drama)-------------
// copy constructor
//-----------------------------------------------------------------------------------------
Drama::Drama(const Drama& other){
	this->setGenre(other.getGenre());
	this->setStock(other.getStock());
	this->setDirector(other.getDirector());
	this->setTitle(other.getTitle());
	this->setYear(other.getYear());
}

//---------------------------------------- ~Drama ----------------------------------------
//destructor
//-----------------------------------------------------------------------------------------
Drama::~Drama(){
	this->setGenre('c');
	this->setStock(0);
	this->setDirector("");
	this->setTitle("");
	this->setYear(-1);
}

//---------------------------------------- getDirector ------------------------------------
//returns the Drama movie director
//-----------------------------------------------------------------------------------------
string Drama::getDirector() const{
	return director;
}

//---------------------------------------- getYear ------------------------------------
//returns the Drama movie release year
//-----------------------------------------------------------------------------------------
int Drama::getYear() const{
	return year;
}

//---------------------------------------- setDirector ------------------------------------
//sets the Drama movie director
//-----------------------------------------------------------------------------------------
void Drama::setDirector(string director){
	this->director = director;
}

//---------------------------------------- setYear ---------------------------------------
//sets the Drama movie year
//-----------------------------------------------------------------------------------------
void Drama::setYear(int year){
	this->year = year;
}

//---------------------------------------- == --------------------------
//compares the Drama movie by date published and actor
//----------------------------------------------------------------------------------------
bool Drama::operator==(const Drama& other) const{
	return (getDirector() == other.getDirector()) &&
		   (getTitle() == other.getTitle()) &&
		   (getYear() == other.getYear());
}

//---------------------------------------- != --------------------------
//compares the Drama movie by date published and actor
//----------------------------------------------------------------------------------------
bool Drama::operator!=(const Drama& other) const{
	return !(*this == other);
}

//---------------------------------------- > --------------------------
//compares the Drama movie by date published and actor
//----------------------------------------------------------------------------------------
bool Drama::operator>(const Drama& other) const{
	//compare by title
	if(getTitle().compare(other.getTitle()) > 0){
		return true;
	}

		//compare by year
	else if(this->getYear() > other.getYear()){
		return true;
	}
	return false;
}

//---------------------------------------- < --------------------------
//compares the Drama movie by date published and actor
//----------------------------------------------------------------------------------------
bool Drama::operator<(const Drama &other)const{
	return !(*this > other | *this == other);
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

	return  genreString + "" + stockString + "" + getDirector() + "" + getTitle() + ""  + yearString;
}
//end of Drama.cpp
/*
//--------------------------------------------------------------------------------
Assignment: Lab 4
Group Members: Lloyd Deng, Antong Cheng, Elias Alabssie
Date: March 20, 2019
//---------------------------------------------------------------------------------------

//------------------------ Comedy.cpp -------------------------------------------------
//Parent: Movie
//Child: None

//description: implementation for the Comedy class.

//-------------------------------------------------------------------------------------
*/

#include"Comedy.h"
#include <sstream>

//---------------------------------------- Comedy() ------------------------------------------
// default constructor
//-----------------------------------------------------------------------------------------
Comedy::Comedy(){
	this->setGenre('c');
	this->setStock(0);
	this->setDirector("");
	this->setTitle("");
	this->setYear(-1);
}

//---------------------------------------- Comedy(int, string, string, string)-------------
// constructor with fields
//-----------------------------------------------------------------------------------------
Comedy::Comedy(int stock, string director, string title, int year){
	this->setGenre('c');
	this->setStock(stock);
	this->setDirector(director);
	this->setTitle(title);
	this->setYear(year);
}

//---------------------------------------- Comedy(Comedy)-------------
// copy constructor
//-----------------------------------------------------------------------------------------
Comedy::Comedy(const Comedy& other){
	this->setGenre(other.getGenre());
	this->setStock(other.getStock());
	this->setDirector(other.getDirector());
	this->setTitle(other.getTitle());
	this->setYear(other.getYear());
}

//---------------------------------------- ~Comedy ----------------------------------------
//destructor 
//-----------------------------------------------------------------------------------------
Comedy::~Comedy(){
	this->setGenre('c');
	this->setStock(0);
	this->setDirector("");
	this->setTitle("");
	this->setYear(-1);
}

//---------------------------------------- getDirector ------------------------------------
//returns the Comedy movie director
//-----------------------------------------------------------------------------------------
string Comedy::getDirector() const{
	return director;
}

//---------------------------------------- getYear ------------------------------------
//returns the Comedy movie release year
//-----------------------------------------------------------------------------------------
int Comedy::getYear() const{
	return year;
}

//---------------------------------------- setDirector ------------------------------------
//sets the Comedy movie director
//-----------------------------------------------------------------------------------------
void Comedy::setDirector(string director){
	this->director = director;
}

//---------------------------------------- setYear --- ------------------------------------
//sets the Comedy movie year
//-----------------------------------------------------------------------------------------
void Comedy::setYear(int year){
	this->year = year;
}

//---------------------------------------- == --------------------------
//compares the Comedy movie by date published and actor
//----------------------------------------------------------------------------------------
bool Comedy::operator==(const Comedy& other) const{
	return (getDirector() == other.getDirector()) &&
		   (getTitle() == other.getTitle()) &&
		   (getYear() == other.getYear());
}

//---------------------------------------- != --------------------------
//compares the Comedy movie by date published and actor
//----------------------------------------------------------------------------------------
bool Comedy::operator!=(const Comedy& other) const{
	return !(*this == other);
}

//---------------------------------------- > --------------------------
//compares the Comedy movie by date published and actor
//----------------------------------------------------------------------------------------
bool Comedy::operator>(const Comedy& other) const{
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
//compares the Comedy movie by date published and actor
//----------------------------------------------------------------------------------------
bool Comedy::operator<(const Comedy &other)const{
	return !(*this > other | *this == other);
}

//---------------------------------------- isIncomplete --------------------------
//Helper method to ensure that a Comedy Movie is proper
//----------------------------------------------------------------------------------------
bool Comedy::isIncomplete() const{
	return (getGenre() != 'f') || (getStock() < 0) || (getDirector().compare("") == 0) ||
		   (getTitle().compare("") == 0);
}

//---------------------------------------- toString --------------------------
//outputs string format of a Comedy Movie object
//----------------------------------------------------------------------------------------
string Comedy::toString() const{
	if(isIncomplete()){
		return "";
	}

	string genreString(1, getGenre());
	string stockString = static_cast<ostringstream*>( &(ostringstream() << getStock()) )->str();
	string yearString = static_cast<ostringstream*>( &(ostringstream() << getYear()) )->str();

	return  genreString + "" + stockString + "" + getDirector() + "" + getTitle() + ""  + yearString;
}
//end of Comedy.cpp
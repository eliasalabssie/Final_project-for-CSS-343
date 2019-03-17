/*
//--------------------------------------------------------------------------------
Assignment: Lab 4
Group Members: Lloyd Deng, Antong Cheng, Elias Alabssie
Date: March 20, 2019
//---------------------------------------------------------------------------------------

//------------------------ Classic.cpp -------------------------------------------------
//Parent: Movie
//Child: None

//description: implementation for the Classic class. 

//-------------------------------------------------------------------------------------
*/

#include"Classic.h"
#include <sstream>

//---------------------------------------- Classic --------------------------------------
// default constructor
//-----------------------------------------------------------------------------------------
Classic::Classic(){
	this->setGenre('c');
	this->setStock(0);
	this->setDirector("");
	this->setTitle("");
	this->setActor("");
	this->setMonth(-1);
	this->setYear(-1);
}

//---------------------------------------- Classic --------------------------------------
// constructor with fields
//-----------------------------------------------------------------------------------------
Classic::Classic(int stock, string director, string title, string actor, int month, int year){
	this->setGenre('c');
	this->setStock(stock);
	this->setDirector(director);
	this->setTitle(title);
	this->setActor(actor);
	this->setMonth(month);
	this->setYear(year);
}

//---------------------------------------- Classic --------------------------------------
// copy constructor
//-----------------------------------------------------------------------------------------
Classic::Classic(const Classic& other) {
	this->setGenre(other.getGenre());
	this->setStock(other.getStock());
	this->setDirector(other.getDirector());
	this->setTitle(other.getTitle());
	this->setActor(other.getActor());
	this->setMonth(other.getMonth());
	this->setYear(other.getYear());
}

//---------------------------------------- ~Classic --------------------------------------
//destructor
//-----------------------------------------------------------------------------------------
Classic::~Classic(){
	this->setGenre('c');
	this->setStock(0);
	this->setDirector("");
	this->setTitle("");
	this->setActor("");
	this->setMonth(-1);
	this->setYear(-1);
}

//---------------------------------------- getDirector ----------------------------
//returns director
//-----------------------------------------------------------------------------------------
string Classic::getDirector() const{
	return director;
}

//---------------------------------------- getActor --------------------------
//returns actor
//-----------------------------------------------------------------------------------------
string Classic::getActor()const{
	return actor;
}

//---------------------------------------- getMonth ----------------------------------
//returns month
//----------------------------------------------------------------------------------------
int Classic::getMonth()const{
	return month;
}

//---------------------------------------- getYear ---------------------------------------
//returns year
//----------------------------------------------------------------------------------------
int Classic::getYear()const{
	return year;
}

//---------------------------------------- setDirector --------------------------
//sets director
//----------------------------------------------------------------------------------------
void Classic::setDirector(string director){
	 this->director = director;
}


//---------------------------------------- setActor --------------------------
//sets majorActorLastName 
//----------------------------------------------------------------------------------------
void Classic::setActor(string actor){
	this->actor = actor;
}

//---------------------------------------- setMonth --------------------------
//sets month
//----------------------------------------------------------------------------------------
void Classic::setMonth(int month){
	this->month = month;
}

//---------------------------------------- setYear --------------------------
//sets year
//----------------------------------------------------------------------------------------
void Classic::setYear(int year){
	this->year = year;
}

//---------------------------------------- == --------------------------
//compares the Classic movie by date published and actor
//----------------------------------------------------------------------------------------
 bool Classic::operator==(const Classic& other) const{
	return (getDirector() == other.getDirector()) &&
		   (getTitle() == other.getTitle()) &&
		   (getActor() == other.getActor()) &&
		   (getMonth() == other.getMonth()) &&
		   (getYear() == other.getYear());
}

//---------------------------------------- != --------------------------
//compares the Classic movie by date published and actor
//----------------------------------------------------------------------------------------
 bool Classic::operator!=(const Classic& other) const{
	 return !(*this == other);
 }

 //---------------------------------------- > --------------------------
//compares the Classic movie by date published and actor
//----------------------------------------------------------------------------------------
 bool Classic:: operator>(const Classic &other)const{
 	//compare by year
 	if(this->getYear() > other.getYear()){
 		return true;
 	}

 	//compare by date
 	else if(this->getMonth() > other.getMonth()){
 		return true;
 	}

 	//compare by actor
 	else if (this->getActor() > other.getActor()){
 		return true;
 	}

 	return false;
 }

//---------------------------------------- < --------------------------
//compares the Classic movie by date published and actor
//----------------------------------------------------------------------------------------
bool Classic:: operator<(const Classic &other)const{
	return !(*this > other | *this == other);
}

//---------------------------------------- isIncomplete --------------------------
//Helper method to ensure that a Classic Movie is proper
//----------------------------------------------------------------------------------------
bool Classic::isIncomplete() const{
	return (getGenre() != 'c') || (getStock() < 0) || (getDirector().compare("") == 0) ||
		   (getTitle().compare("") == 0) || (getActor().compare("") == 0) ||
		   (getMonth() < 0) || (getYear() < 0);
}

//---------------------------------------- toString --------------------------
//outputs string format of a Classic Movie object
//----------------------------------------------------------------------------------------
string Classic::toString() const{
	if(isIncomplete()){
		return "";
	}

	string genreString(1, getGenre());
	string stockString = static_cast<ostringstream*>( &(ostringstream() << getStock()) )->str();
	string monthString = static_cast<ostringstream*>( &(ostringstream() << getMonth()) )->str();
	string yearString = static_cast<ostringstream*>( &(ostringstream() << getYear()) )->str();

	return  genreString + "" + stockString + "" + getDirector() + "" + getTitle() + "" + getActor() + "" + monthString + "" + yearString;
}
 //end of Classic.cpp
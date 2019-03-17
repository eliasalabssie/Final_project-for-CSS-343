/*
//-------------------------------------------------------------------------------
Assignment: Lab 4
Group Members: Lloyd Deng, Antong Cheng, Elias Alabssie
Date: March 20, 2019
//--------------------------------------------------------------------------------

//------------------------ Drama.cpp -----------------------------------
//Parent: Movie
//Chil: None

//description: implementation for the Drama class. 

//---------------------------------------------------------------------
*/

#include"Drama.h"


//------------------------ ------------ Drama -----------------------------------------
// Description: empty construct of Drama class 
//-----------------------------------------------------------------------------------
Drama::Drama()
{
	this->setStock(0);
	this->director = "";
	this->setTitle("");
	this->year = "";	
}


//---------------------------------------- Drama(string, string)-----------------------
// Description: construct Drama class from direcotr and year published
//-------------------------------------------------------------------------------------
Drama::Drama(int amount, string director, string title, string year)  
{
	
	this->setStock(amount);
	this->director = director;
	this->setTitle(title);
	this->year = year;

}


//---------------------------------------- Drama(Drama&)------------------------------
// Description: construct Drama class from onother Drama object
//-------------------------------------------------------------------------------------
Drama::Drama(Drama& other const){
	setStock(other.getStock());
	setDirector(other.getDirector());
	setTitle(other.getTitle());
	seReleaseYear(other.getReleaseYear());
}


//---------------------------------------- ~Drama ------------------------------------
// Description: destructs the Drama object
//-------------------------------------------------------------------------------------
Drama::~Drama()
{


}
	

//---------------------------------------- getDirector -----------------------------
// Description: returns the director of the Movie
//-------------------------------------------------------------------------------------
string Drama::getDirector() const 
{
	return director;

}


//---------------------------------------- getYear -----------------------------
// Description: returns the year that the Movie published
//-------------------------------------------------------------------------------------
string Drama::getYear() const
{
	return year;

}


//---------------------------------------- setDirector -----------------------------
// Description: sets the director data member
//-------------------------------------------------------------------------------------
void Drama::setDirector(string director)
{

	this->director = director;
	
}


//---------------------------------------- setYear ----------------------------------
// Description: sets the year to the argument year
//-------------------------------------------------------------------------------------
void Drama::setYear(string year) 
{

	this->year = year;
	
}


//--------------------------------- operator== ----------------------------------------------
//description: compare two Drama objects
//Pre: Drama movies with the same director and title but different year of release. are
//considered to be different(for inventory purpuse).
//--------------------------------------------------------------------------------------------
bool Drama::operator==(const Drama& movie) const
{

 	if(this->director == movie.director && this->getTitle() == movie.getTitle() && this->year == movie.year)  
 	{
 		return true;

 	}

 	return false;		

}


//------------------------------------- operator != -----------------------------------------
//description: compare two Drama objects
//Pre: Drama movies with the same director and title but different year of release. are
//considered to be different(for inventory purpuse).
//--------------------------------------------------------------------------------------------
 bool Drama::operator!=(const Drama& movie) const
 {
 		bool notEqual = (*this == movie);
 		return !notEqual;

 }


//------------------------------------- operator > -----------------------------------------
//description: compare two Drama objects
//Pre: Drama movies with the same director and title but different year of release. are
//considered to be different(for inventory purpuse).
//--------------------------------------------------------------------------------------------
bool Drama::operator >(const Drama &drama)const
{
	if(this->getDirector() > drama.getDirector())
	{
		return true;
	}
	return this->getTitle() > drama.getTitle(); 


}



//------------------------------------- operator < -----------------------------------------
//description: compare two Drama objects
//Pre: Drama movies with the same director and title but different year of release. are
//considered to be different(for inventory purpuse).
//--------------------------------------------------------------------------------------------
bool Drama::operator<(const Drama &drama)const
{
	bool greaterThan = (*this > drama);
	return !greaterThan;


}//end of Drama.cpp file

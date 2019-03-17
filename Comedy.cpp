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

//---------------------------------------- Comedy ------------------------------------------
//constr
//-----------------------------------------------------------------------------------------
Comedy::Comedy(){
	this->setGenre('c');
	this->setStock(0);
	this->setDirector("");
	this->setTitle("");
	this->setYear(-1);
}

//---------------------------------------- Comedy(int, string, string, string)-------------
//constr
//-----------------------------------------------------------------------------------------
Comedy::Comedy(int amount, string director, string title, string year)  
{
	this->setStock(amount);
	this->director = director;
	this->setTitle(title);
	this->year = year;
}

//---------------------------------------- Comedy(int, string, string, string)-------------
//copy constr
//-----------------------------------------------------------------------------------------
Comedy::Comedy(const Comedy& other){
	setStock(other.getStock());
	setDirector(other.getDirector());
	setTitle(other.getTitle());
	seReleaseYear(other.getReleaseYear());
}


//---------------------------------------- ~Comedy ----------------------------------------
//destructor 
//-----------------------------------------------------------------------------------------
Comedy::~Comedy()
{


}
	

//---------------------------------------- getDirector ------------------------------------
//returns the Comedy movie director
//-----------------------------------------------------------------------------------------
string Comedy::getDirector() const 
{
	return director;

}


//---------------------------------------- getYear ------------------------------------
//returns the Comedy movie release year
//-----------------------------------------------------------------------------------------
string Comedy::getYear() const
{
	return year;

}


//---------------------------------------- setDirector ------------------------------------
//sets the Comedy movie director 
//-----------------------------------------------------------------------------------------
void Comedy::setDirector(string director)
{

	this->director = director;
	
}


//---------------------------------------- setYear --- ------------------------------------
//sets the Comedy movie year
//-----------------------------------------------------------------------------------------
void Comedy::setYear(string year) 
{

	this->year = year;
	
}


//---------------------------------------- operator ==  -----------------------------------
//comepares Comedy movies
//-----------------------------------------------------------------------------------------
 bool Comedy:: operator==(const Comedy& movie) const
 {

 	if(director == movie.director && this->getTitle() == movie.getTitle() && year == movie.year)  
 		{
 			return true;

 		}

 		return false;		

 }


//---------------------------------------- operator!=  -----------------------------------
//comepares Comedy movies by their title and year released
//-----------------------------------------------------------------------------------------
 bool Comedy::operator!=(const Comedy& movie) const
 {
 		bool notEqual = (*this == movie);
 		return !notEqual;

 }


//---------------------------------------- operator > -----------------------------------
//comepares Comedy movies by their title and year released
//-----------------------------------------------------------------------------------------
bool Comedy::operator>(Comedy &comedy)const
{
	if(this->getTitle() > comedy.getTitle())
	{
		return true;
	}
	
	return this->year > comedy.year;

}


//---------------------------------------- operator <  -----------------------------------
//comepares Comedy movies by their title and year released
//-----------------------------------------------------------------------------------------
bool Comedy::operator<(Comedy&comedy)const
{

	bool lessThan = (*this > comedy);
	return !lessThan;

}










	


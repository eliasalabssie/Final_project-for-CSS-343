/*
//-----------------------------------------------------------------------------
Assignment: Lab 4
Group Members: Lloyd Deng, Antong Cheng, Elias Alabssie
Date: March 20, 2019
//-----------------------------------------------------------------------------

//------------------------Movie.cpp -------------------------------------------
//Parent: None
//Children: Drama.h, Classic.h, Comedy.h

//description: implementation of the Movie class. 

//--------------------------------------------------------------------------
*/
#include"Movie.h"

Movie:: Movie(){
	this->genre = '\0';
	this->stock = 0;
	this->title = "";
}//end of movie


//--------------- Movie-------------------------------------------------------------
// Description: construct the movie class form genre, stock, and title
//----------------------------------------------------------------------------------
Movie::Movie(char genre, int stock, string title){
	this->genre = genre;
	this->stock = stock;
	this->title = title;
}//end of Movie(char, int, string) 



// ------------------------- Movie(Movie&) --------------------------------------------
// Description: copy construcotor
// ----------------------------------------------------------------------------------------
Movie::Movie(const Movie &movie){
	*this = movie;
}//end of Movie(const Movie&)


// destructor -------------- ~Movie -------------------------------------------------------
// Description: destructor
// ----------------------------------------------------------------------------------------
Movie::~Movie(){

}//end 

//---------------------------------- getStock ------------------------------------------
//returns stock
//---------------------------------------------------------------------------------------  
 int Movie::getStock() const{
 	return stock;
 }//end


//----------------------------------------- getGenre ------------------------------------
 //returns genre(the char symball of the movie)
 //--------------------------------------------------------------------------------------
 char Movie:: getGenre() const{
 	return genre;
 }//end


 //----------------------------------------- getTittle ----------------------------------
 //return tittle of the movie
 //--------------------------------------------------------------------------------------
string Movie::getTitle() const{
	return title;
}//end
		
		
//----------------------------------------- setStock ----------------------------------
 //updates the amount of movie in teh store to indicated value
 //--------------------------------------------------------------------------------------		
 void Movie::setStock(int stock){
 	this->stock = stock;
 }//end


 //----------------------------------------- setGenre ----------------------------------
 //changes the movie genre to the indicated symbol
 //--------------------------------------------------------------------------------------		
 void Movie::setGenre(char genre){
 	this->genre = genre;
 }//end


 //----------------------------------------- setTitle -----------------------------------
 //Changes the title
 //--------------------------------------------------------------------------------------		
 void Movie:: setTitle(string title){
 	this->title = title;
 }//end


// equality operator
 bool Movie::operator ==(const Movie &movie) const{
 		// check for equality. but doesn't compare by stock data memeber
 		if(genre == movie.genre && title == movie.title){
 			return true;
 		}
 		return false;
 }

 // inequality operator
 bool Movie::operator !=(const Movie& movie) const{
	bool notEqual = *this == movie;
	return !notEqual;
}



//------------------------------------ operator<<  --------------------------------------------
ostream& operator<<(ostream &o, Movie &movie){
	o << movie.genre << " " << movie.stock << " " << movie.title;
	return o;
}

// -------------------------- operator>> ---------------------------------------
istream& operator>>(istream &i, Movie &movie){
	 i >> movie.genre >> movie.stock >> movie.title;
	 return i;
}
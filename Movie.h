
/*
//-------------------------------------------------------------------------------
Assignment: Lab 4
Group Members: Lloyd Deng, Antong Cheng, Elias Alabssie
Date: March 20, 2019
//--------------------------------------------------------------------------------

//------------------------Movie.h -----------------------------------
//Parent: None
//Children: Drama, Classic, Comedy

//description: interface for the Movie class. 

//---------------------------------------------------------------------
*/

#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <iostream>

using namespace std;

class Movie{
	//friend classes
	friend ostream& operator<<(ostream &outStream, Movie &movie);
	friend istream& operator>>(istream &iStream, Movie &movie);

	public:
		Movie();
		Movie(char, int, string);
		Movie(const Movie &movie);
		virtual ~Movie();

		// Getters
		virtual int getStock() const; 
		virtual char getGenre() const; 
		virtual string getTitle() const; 

		// Setters
		virtual void setStock(int);
		virtual void setGenre(char);
		virtual void setTitle(string);
		virtual bool operator ==(const Movie& ) const;
		virtual bool operator !=(const Movie& ) const;

	private:
		char genre;
		int stock;
		string title;
};
#endif
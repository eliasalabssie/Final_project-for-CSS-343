/*
//-------------------------------------------------------------------------------
Assignment: Lab 4
Group Members: Lloyd Deng, Antong Cheng, Elias Alabssie
Date: March 20, 2019
//--------------------------------------------------------------------------------

//------------------------ Comedy.h -----------------------------------
//Parent: Movie.h
//Chil: None

//description: interface for the Comedy class.

//---------------------------------------------------------------------
*/
#ifndef Comedy_H
#define Comedy_H

#include <string>
#include <iostream>
#include "Movie.h"

using namespace std;

class Comedy:public Movie{
	//friend classes
	friend ostream& operator<<(ostream &, Comedy &);
	friend istream& operator>>(istream &, Comedy &);

	public:
		//constructors
		Comedy();
		Comedy(int, string, string, int);
		Comedy(const Comedy &);

		//destructor
		~Comedy();

		// getters
		string getDirector() const;
		int getYear() const;

		// setters
		void setDirector(string);
		void setYear(int) ;

		// operator overloads
		bool operator==(const Comedy&) const;
		bool operator!=(const Comedy&) const;
		bool operator>(const Comedy&) const;
		bool operator<(const Comedy&) const;

		//miscellaneous
		bool isIncomplete() const;
		string toString() const;

	private:
		string director;
		int year;
};
#endif
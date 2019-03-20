/*
//-------------------------------------------------------------------------------
Assignment: Lab 4
Group Members: Lloyd Deng, Antong Cheng, Elias Alabssie
Date: March 20, 2019
//--------------------------------------------------------------------------------

//------------------------ Drama.h -----------------------------------
//Parent: Movie.h
//Chil: None

//description: interface for the Drama class.

//---------------------------------------------------------------------
*/
#ifndef DRAMA_H
#define DRAMA_H

#include <string>
#include <iostream>
#include "Movie.h"

using namespace std;

class Drama:public Movie{
	//friend classes
	friend ostream& operator<<(ostream &, Drama &);
	friend istream& operator>>(istream &, Drama &);

	public:
		//constructors
		Drama();
		Drama(int, string, string, int);
		Drama(const Drama &);

		//destructor
		~Drama();

		// getters
		string getDirector() const;
		int getYear() const;

		// setters
		void setDirector(string);
		void setYear(int);

		// operator overloads
		bool operator==(const Drama&) const;
		bool operator!=(const Drama&) const;
		bool operator>(const Drama&) const;
		bool operator<(const Drama&) const;

		//miscellaneous
		bool isIncomplete() const;
		string toString() const;

	private:
		string director;
		int year;
};
#endif
/*
//-------------------------------------------------------------------------------
Assignment: Lab 4
Group Members: Lloyd Deng, Antong Cheng, Elias Alabssie
Date: March 20, 2019
//--------------------------------------------------------------------------------

//------------------------Classic.h -----------------------------------
//Parent: Movie.h
//Children:None

//description: interface for the Classic class. 

//---------------------------------------------------------------------
*/
#ifndef CLASSIC_H
#define CLASSIC_H

#include <string>
#include <iostream>
#include "Movie.h"

using namespace std;

class Classic:public Movie{
	//friend classes
	friend ostream& operator<<(ostream &, Classic &);
	friend istream& operator>>(istream &, Classic &);

	public:
		// constructors
		Classic();
		Classic(int, string, string, string, int, int);
		Classic(const Classic &);

		// destructor
		~Classic();

		// getters
		string getDirector() const;
		string getActor() const;
		int getMonth() const;
		int getYear() const;

		// setters
		void setDirector(string);
		void setActor(string);
		void setMonth(int);
		void setYear(int);

		// operator overloads
		bool operator==(const Classic&) const;
		bool operator!=(const Classic&) const;
		bool operator>(const Classic&) const;
		bool operator<(const Classic&) const;

		//miscellaneous
		bool isIncomplete() const;
		string toString() const;

	private:
		string director;
		string actor;
		int month;
		int year;
};
#endif
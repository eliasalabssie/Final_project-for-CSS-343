/*
//-------------------------------------------------------------------------------
Assignment: Lab 4
Group Members: Lloyd Deng, Antong Cheng, Elias Alabssie
Date: March 20, 2019
//--------------------------------------------------------------------------------

//------------------------ Drama.h -----------------------------------
//Parent: Movie
//Chil: None

//description: interface for the Drama class. 

//---------------------------------------------------------------------
*/

#ifndef DRAMA_H
#define DRAMA_H

#include"Movie.h"
#include<iostream>
#include<string>
using namespace std;


class Drama:public Movie
{

	public:
	
		//constructors/destructor
		Drama();
		Drama(int stock, string director, string title, string year);
		Drama(const Drama&);
		~Drama();

		// Getters
		string getDirector() const ;
		string getYear() const;

		// Setters
		void setDirector(string director);
		void setYear(string year) ;
		
		
		// operator overloads
		bool operator==(const Drama& ) const;
		bool operator!=(const Drama& ) const;
		bool operator>(const Drama &)const;
		bool operator<(const Drama &)const;

	private:
		string director;
		string year;
	
};
#endif


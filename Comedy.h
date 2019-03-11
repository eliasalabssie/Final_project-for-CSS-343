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

#include<iostream>
#include<string>
#include"Movie.h"
using namespace std;


class Comedy:public Movie
{
	
	
	public:
	
		//constr/destr
		Comedy();
		Comedy(int, string, string, string);
		Comedy(Comedy&);
		~Comedy();
		

		// Getters
		string getDirector() const;
		string getYear() const;
		

		// Setters
		void setDirector(string director);
		void setYear(string year) ;
		
		
		// operator overloads
		bool operator==(const Comedy& movie) const;
		bool operator!=(const Comedy& movie) const;
		bool operator>(Comedy &comedy)const;
		bool operator<(Comedy&comedy)const;

	private:
		string director;
		string year;

	
};
#endif 

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
#include<string>
#include<iostream>
#include"Movie.h"

using namespace std;


class Classic: public Movie
{


	public:
		
		Classic();
		
		Classic(int stock, string directorFirstName, string directorLastName, string title, 
						string majorAfirstName, string majorAlastName, string date, string year);
		
		Classic(Classic& const);
		~Classic();

		
		// Getters
		string getDirectorFirstName() const;
		string getDirectorLastName() const;
		string getMajorActorFirstName()const;
		string getMajorActorLastName()const;
		string getDate()const;
		string getYear()const;
		

		// Setters
		void setDirectorFirstName(string);
		void setDirectorLastName(string);
		void setMajorActorFirstName(string);
		void setMajorActorLastName(string);
		void setDtate(string);
		void setYear(string);
		
		// operator overloads
		bool operator==(const Classic&) const;
		bool operator!=(const Classic&) const;
		bool operator>(const Classic &)const;
		bool operator<(const Classic &)const;

	private:

		string dirctorFirstName;
		string dirctorLastName;
		string majorActorFirstName;
		string majorActorLastName;
		string date;
		string year;
		
};
#endif

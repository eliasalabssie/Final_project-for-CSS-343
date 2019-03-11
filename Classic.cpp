/*
//--------------------------------------------------------------------------------
Assignment: Lab 4
Group Members: Lloyd Deng, Antong Cheng, Elias Alabssie
Date: March 20, 2019
//---------------------------------------------------------------------------------------

//------------------------ Classic.cpp -------------------------------------------------
//Parent: Movie
//Chil: None

//description: implementation for the Classic class. 

//-------------------------------------------------------------------------------------
*/

#include"Classic.h"

//---------------------------------------- Classic --------------------------------------
//constr
//-----------------------------------------------------------------------------------------
Classic::Classic()
{
	this->setStock(0);
	dirctorFirstName = "";
	dirctorLastName = "";
	this->setTitle("");
	majorActorFirstName = "";
	majorActorLastName = "";
	date = "";
	year = "";

}

//---------------------------------------- Classic --------------------------------------
//constr
//-----------------------------------------------------------------------------------------
Classic::Classic(int stock, string directorFirstName, string directorLastName, string title, 
					string majorAfirstName, string majorAlastName, string date, string year)  
{

	this->setStock(stock);
	this->dirctorFirstName = directorFirstName;
	this->dirctorLastName = directorLastName;
	this->setTitle(title);
	this->majorActorFirstName = majorActorFirstName;
	this->majorActorLastName = majorActorLastName;
	this->date = date;
	this->year = year;
}

//---------------------------------------- Classic --------------------------------------
//copy constr
//-----------------------------------------------------------------------------------------
Classic::Classic(Classic &classics)
{

	*this  = classics;

}


//---------------------------------------- ~Classic --------------------------------------
//destructor
//-----------------------------------------------------------------------------------------
Classic::~Classic()
{


}
	

//---------------------------------------- getDirectorFirstName ----------------------------
//returns directorsFirstName
//-----------------------------------------------------------------------------------------
string Classic::getDirectorFirstName() const
{


	return dirctorFirstName;
}


//---------------------------------------- getDirectorLastName ----------------------------
//returns directorsFirstName
//-----------------------------------------------------------------------------------------
string Classic::getDirectorLastName() const
{

	return dirctorLastName;
}


//---------------------------------------- getMajorActorFirstName --------------------------
//returns directorsFirstName
//-----------------------------------------------------------------------------------------
string Classic::getMajorActorFirstName()const
{

	return majorActorFirstName;
}


//---------------------------------------- getMajorActorLastName --------------------------
//returns directorLastName
//----------------------------------------------------------------------------------------
string Classic::getMajorActorLastName()const
{

	return majorActorLastName;
}


//---------------------------------------- getDtate --------- --------------------------
//returns the date the calssic movie published
//----------------------------------------------------------------------------------------
string Classic::getDate()const
{
	return date;
}


//---------------------------------------- getYear ---------------------------------------
//returns returns the year the calssic movie published
//----------------------------------------------------------------------------------------
string Classic::getYear()const
{

	return year;
}


//---------------------------------------- setDirectorFirstName  --------------------------
//sets the directorsFirstName
//----------------------------------------------------------------------------------------
void Classic::setDirectorFirstName(string firstName)
{
	this->dirctorFirstName = firstName;

}



//---------------------------------------- setDirectorLastName --------------------------
//sets the  directorLastName 
//----------------------------------------------------------------------------------------
void Classic::setDirectorLastName(string lastName)
{

	this->dirctorLastName = lastName;
}


//---------------------------------------- getMajorActorFirstName --------------------------
//sets majorActorLastName 
//----------------------------------------------------------------------------------------
void Classic::setMajorActorFirstName(string firstName)
{

	this->majorActorFirstName = firstName;
}


//---------------------------------------- getMajorActorFirstName --------------------------
//sets the setMajorActorLastName
//----------------------------------------------------------------------------------------
void Classic::setMajorActorLastName(string lastName)
{
	this->majorActorLastName = lastName;
}


//---------------------------------------- getMajorActorFirstName --------------------------
//sets the date that Classic movie published
//----------------------------------------------------------------------------------------
void Classic::setDtate(string date)
{
	this->date = date;
}


//---------------------------------------- getMajorActorFirstName --------------------------
//sets the year that Classic movie published
//----------------------------------------------------------------------------------------
void Classic::setYear(string year)
{

	this->year = year;
}



//---------------------------------------- getMajorActorFirstName --------------------------
//compares the Classic movie by date published and actor
//----------------------------------------------------------------------------------------
 bool Classic::operator==(const Classic& movie) const
 {

 	if(majorActorFirstName == movie.majorActorFirstName && majorActorLastName == movie.majorActorLastName
 			 && date == movie.date && year == movie.year)  
 		{
 			return true;

 		}

 	return false;		

 }


//---------------------------------------- getMajorActorFirstName --------------------------
//compares the Classic movie by date published and actor
//----------------------------------------------------------------------------------------
 bool Classic::operator!=(const Classic& movie) const
 {
 		bool notEqual = (*this == movie);
 		return !notEqual;

 }


 //---------------------------------------- getMajorActorFirstName --------------------------
//compares the Classic movie by date published and actor
//----------------------------------------------------------------------------------------
 bool Classic:: operator>(const Classic &classics)const
 {

 	//compare by year
 	if(this->year > classics.year)
 	{
 		return true;
 	}
 	//compare by date
 	else if(this->date > classics.date)
 	{
 		return true;
 	}

 	//compare by majorActorFirstName
 	else if(majorActorFirstName > classics.majorActorFirstName)
 	{
 		return true;
 	}

 	//compare by majorActorLastName 
 	return majorActorLastName > classics.majorActorLastName;

 }



//---------------------------------------- getMajorActorFirstName --------------------------
//compares the Classic movie by date published and actor
//----------------------------------------------------------------------------------------
bool Classic:: operator<(const Classic &classics)const
{

	bool lessThan = (*this > classics);
	return !lessThan;
}

 //end of Classic.cpp

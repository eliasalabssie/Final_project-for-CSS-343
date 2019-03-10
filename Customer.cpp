
/*
//-------------------------------------------------------------------------------
Assignment: Lab 4
Group Members: Lloyd Deng, Antong Cheng, Elias Alabssie
Date: March 20, 2019
//--------------------------------------------------------------------------------

//------------------------Customer.h -----------------------------------
//Parent: None
//Child: None

//description: interface for the Customer class. 

//---------------------------------------------------------------------
*/

#include "Customer.h"

//empty contructor
Customer::Customer()
{
	ID = 0;
	firstName = "";
	lastName  = "";

}//end of Custormer()


//constructs Customer object from customer ID, first and last name 
Customer::Customer(int id, string firstName, string lastName)
{
	this->ID = id;
	this->firstName = firstName;
	this->lastName = lastName;

}//end of Custormer


//copy constructor
Customer::Customer(Customer &custom)
{
	*this = custom;

}//end of copy constructor



//destructor
Customer:: ~Customer()
{

}//end of destructor
 

 //return customer ID
int Customer::getId() const
{
	return ID;

}//end of getId


//returns first name of the customer 
string Customer::getFisrtName()const
{
	return firstName;

}//end of getFisrtName


//returns the last name of the customer
string Customer::getLastName()const
{

	return lastName;

}//end of getLastName
 


 //set the customer ID
void Customer::setId(int id)
{
	this->ID = id;

}//end of setId


//set the first name of the customer
void Customer::setFirstName(string firstName)
{

	this->firstName = firstName;

}//end of setFirstName



//set the last name of the customer
void Customer::setLastName(string lastName)
{
	this->lastName = lastName;


}//end of setLastName


//overloading equality operator
bool Customer::operator==(Customer &custom)const
{
	if(ID == custom.ID && firstName == custom.firstName && lastName == custom.lastName)
	{
		return true;
	}
	return false;

}//end of ==overload


////overloading not equal operator
bool Customer::operator !=(Customer &custom)const
{
	bool notEqual = *this == custom;
	return !notEqual;

}//end of != overloading


//overloading < operator
bool Customer::operator >(Customer &custom)const
{
	if(this->ID > custom.ID)
	{
		return true;
	}

	else if(this->lastName > custom.lastName)
	{
		return true;
	}

	else 
	{
		return firstName > custom.firstName;
	}

}


//overloading > operator
bool Customer::operator<(Customer &custom)const
{

	 bool  lessThan =  *this > custom;
	 return !lessThan;

}//end of > overloading


// insertion operator (<<) overloading
ostream& operator<<(ostream &outStream, Customer &custom)
{
	outStream << custom.ID << " " << custom.lastName << " " << custom.firstName;
	return outStream;

}//last name, first name



// extraction operator (>>) overloading
istream& operator>>(istream &iStream, Customer &custom)
{

	iStream >> custom.ID >> custom.lastName >> custom.firstName;
	return iStream;
}//end of operator >>
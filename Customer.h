
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

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Customer
{

	friend ostream& operator<<(ostream &outStream, Customer &custom);
	friend istream& operator>>(istream &iStream, Customer &custom);
	
	public:
		Customer();
    	Customer(int, string, string);
    	Customer(Customer &custom);
    	~Customer();

    	//getters
    	int getId()const;
    	string getFisrtName()const;
    	string getLastName()const;

    	//setters
    	void setId(int id);
    	void setFirstName(string);
    	void setLastName(string);
    	
    	//operator overloads
    	bool operator ==(Customer &custom)const;
    	bool operator !=(Customer &custom)const;
    	bool operator<(Customer &custom)const;
    	bool operator>(Customer &custom)const;
    

	private:
		int ID;
        string firstName;
        string lastName;	
};
#endif
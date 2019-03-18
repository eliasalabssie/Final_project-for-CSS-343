
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

#include <iostream>
#include <string>

using namespace std;

class Customer {

	friend ostream& operator<<(ostream &, Customer &);
	friend istream& operator>>(istream &, Customer &);
	
	public:
		//constructors
		Customer();
    	Customer(int, string);
    	Customer(Customer &);
    	~Customer();

    	//getters
    	int getId()const;
    	string getName()const;

    	//setters
    	void setId(int);
    	void setName(string);
    	
    	//operator overloads
    	bool operator==(Customer &)const;
    	bool operator!=(Customer &)const;
    	bool operator<(Customer &)const;
    	bool operator>(Customer &)const;
    

	private:
		int ID;
        string name;
};
#endif
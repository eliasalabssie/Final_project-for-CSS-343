
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

//default contructor
Customer::Customer(){
	ID = 0;
	name = "";
}

//constructs Customer given customer ID and name
Customer::Customer(int id, string name){
	this->ID = id;
	this->name = name;
}

//copy constructor
Customer::Customer(Customer &c){
	*this = c;

}

//destructor
Customer:: ~Customer(){
	ID = 0;
	name = "";
}

 //return customer ID
int Customer::getId() const{
	return ID;
}

//returns customer name
string Customer::getName()const{
	return name;

}

 //set customer ID
void Customer::setId(int ID){
	this->ID = ID;

}

 //set the customer name
void Customer::setName(string name){
	this->name = name;
}

//overloaded equality operator
bool Customer::operator==(Customer &c)const{
    return ID == c.ID && name == c.name;
}

//overloaded inequality operator
bool Customer::operator!=(Customer &c)const{
	return !(*this == c);
}

//overloaded comparison operator
bool Customer::operator >(Customer &c)const{
	if(this->ID > c.ID){
		return true;
	}

	else if(this->ID == c.ID && this->name > c.name){
	    cerr << "DANGER: ID collision.";
		return true;
	}
	return false;
}

//overloaded comparison operator
bool Customer::operator<(Customer &c)const{
    return !(*this > c);
}

// overloaded extraction operator
ostream& operator<<(ostream &out, Customer &c){
	out << c.ID << " " << c.name;
	return out;
}

// overloaded insertion operator
istream& operator>>(istream &in, Customer &c){
	in >> c.ID >> c.name;
	return in;
}
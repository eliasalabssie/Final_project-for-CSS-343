//
// Created by lloyd on 2019.03.06.
//

#include <sstream>
#include "Command.h"

using namespace std;

//constructor
Command::Command(){
    char action = '\0';
    int ID = -1;
    char format = '\0';
    char genre = '\0';
    int month = -1;
    int year = -1;
    string actor = "";
    string director = "";
    string title = "";
}

//inventory command
Command::Command(char action) : action(action), ID(-1) {
    //int ID = -1;
    format = '\0';
    genre =  '\0';
    month = -1;
    year = -1;
    actor = "";
    string director = "";
    string title = "";
}

//history command
Command::Command(char action, int ID) : action(action), ID(ID) {
    format = '\0';
    genre =  '\0';
    month = -1;
    year = -1;
    actor = "";
    string director = "";
    string title = "";
}

//borrow/return command for comedy movie
Command::Command(char action, int ID, char format, char genre, string title, int year) :
        action(action), ID(ID), format(format), genre(genre), title(title), year(year){
    director = "";
    actor = "";
    month = -1;
}

//borrow/return command for drama
Command::Command(char action, int ID, char format, char genre, string director, string title) :
        action(action), ID(ID), format(format), genre(genre), director(director), title(title){
    actor = "";
    month = -1;
    year = -1;
}

//borrow/return command for classic
Command::Command(char action, int ID, char format, char genre, int month, int year, string actor) :
        action(action), ID(ID), format(format), genre(genre), month(month), year(year), actor(actor){
    director = "";
    title = "";
}

//copy constructor
Command::Command(const Command &other){
    this->action = other.action;
    this->ID = other.ID;
    this->format = other.format;
    this->genre = other.genre;
    this->month = other.month;
    this->year = other.year;
    this-> actor = other.actor;
    this->director = other.director;
    this->title = other.title;
}

//destructor
Command::~Command(){
    char action = '\0';
    int ID = -1;
    char format = '\0';
    char genre = '\0';
    int month = -1;
    int year = -1;
    string actor = "";
    string director = "";
    string title = "";
}

//------------------------------------ operator<<  --------------------------------------------
ostream& operator<<(ostream &o, Command &other){
    o << other.toString();
    return o;
}

// -------------------------- operator>> ---------------------------------------
istream& operator>>(istream &i, Command &movie){
    //i >> movie.genre >> movie.stock >> movie.title; //TODO
    return i;
}

//toString command
string Command::toString() const{
    stringstream stream;
    stream << ID;
    string sID = stream.str();
    stream.str(""); //Clear buffer
    stream << month;
    string smonth = stream.str();
    stream.str(""); //Clear buffer
    stream << year;
    string syear = stream.str();
    string saction(1, action);
    if (sID == "-1"){
        sID = "";
    }
    if (smonth == "-1"){
        smonth = "";
    }
    if (syear == "-1"){
        syear = "";
    }
    return saction + " " + sID + " " + format + " " + genre + " " + director + " " + title + " " + smonth + " " + syear + " " + actor ;
}

//getter
char Command::getAction() const{
    return action;
}

int Command::getID() const{
    return ID;
}

char Command::getFormat() const{
    return format;
}

char Command::getGenre() const{
    return genre;
}
int Command::getMonth() const{
    return month;
}
int Command::getYear() const{
    return year;
}
string Command::getActor() const{
    return actor;
}
string Command::getDirector() const{
    return director;
}
string Command::getTitle() const{
    return title;
}

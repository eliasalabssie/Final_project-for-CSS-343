//
// Created by lloyd on 2019.03.06.
//

#include <string>
#include <sstream>
#include "command.h"

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
}

//inventory command
Command::Command(char action) : action(action) {
}

//history command
Command::Command(char action, int ID) : action(action), ID(ID) {
}

//borrow/return command for classic movie
Command::Command(char action, int ID, char format, char genre, string actor, int year) :
        action(action), ID(ID), format(format), genre(genre), actor(actor), year(year){
    month = -1;
}

//borrow/return command for comedy, drama
Command::Command(char action, int ID, char format, char genre, int month, int year, string actor) :
        action(action), ID(ID), format(format), genre(genre), month(month), year(year), actor(actor){
}

//toString command
string Command::toString(){
    stringstream stream;
    stream << ID;
    string sID = stream.str();
    stream.str(""); //Clear buffer
    stream << month;
    string smonth = stream.str();
    stream.str(""); //Clear buffer
    stream << year;
    string syear = stream.str();
    return action + sID + format + genre + smonth + syear + actor;
}

//ID getter
int Command::getID(){
    return ID;
}

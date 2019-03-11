//
// Created by lloyd on 2019.03.06.
//

#include <string>
#include <sstream>
#include "command.h"

using namespace std;

Command::Command(){
    char action = '';
    int ID = -1;
    char format = '';
    char genre = '';
    int month = -1;
    int year = -1;
    string actor = "";
}

Command::Command(char action, int ID, char format, char genre, string actor, int year) :
        action(action), ID(ID), format(format), genre(genre), actor(actor), year(year){
    month = -1;
}

Command::Command(char action, int ID, char format, char genre, int month, int year, string actor) :
        action(action), ID(ID), format(format), genre(genre), month(month), year(year), actor(actor){
}

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

int Command::getID(){
    return ID;
}

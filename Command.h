//
// Created by lloyd on 2019.03.06.
//

#ifndef ASSIGNMENT4_COMMAND_H
#define ASSIGNMENT4_COMMAND_H

//#include <string>

using namespace std;

class Command {

public:
    Command();
    Command(char);
    Command(char, int);
    Command(char, int, char, char, string, int);
    Command(char, int, char, char, int, int, string);
    Command(const Command &);
    ~Command();
    string toString();
    int getID();

private:
    char action;
    int ID;
    char format;
    char genre;
    int month;
    int year;
    string actor;
};

#endif //ASSIGNMENT4_COMMAND_H

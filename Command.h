//
// Created by lloyd on 2019.03.06.
//

#ifndef ASSIGNMENT4_COMMAND_H
#define ASSIGNMENT4_COMMAND_H

//#include <string>

using namespace std;

class Command {
    //friend classes
    friend ostream& operator<<(ostream &, Command &);
    friend istream& operator>>(istream &, Command &);

    public:
        //constructors
        Command();
        Command(char);
        Command(char, int);
        Command(char, int, char, char, string, int);
        Command(char, int, char, char, string, string);
        Command(char, int, char, char, int, int, string);
        Command(const Command &);

        //destructor
        ~Command();

        //getters
        int getID();

        //miscellaneous
        string toString();

    private:
        char action;
        int ID;
        char format;
        char genre;
        int month;
        int year;
        string actor;
        string director;
        string title;
};

#endif //ASSIGNMENT4_COMMAND_H

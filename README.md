Lloyd Deng, Antong Cheng, Elias Alabssie
2019 March 20.

THIS PROGRAM COMPILES AT uw1-320-07.uwb.edu ON PORT 22,
WITH THE STATEMENT: g++ -std=c++11 *.cpp
 
 Expected output can be seen in output.txt.
 
 * Assignment 4 initializes the Blockbuster object, which holds three sets, an unordered_map, and a vector. (From STL)
 * These structures control movie stocking, customer accounts, and customer commands.
 *
 * Initialization requires three files, which are listed in Blockbuster.cpp at lines 31, 35, 39.
 * data4movies.txt should detail the initial stocking of the Blockbuster movie database.
 * data4customers.txt should detail the initial customer accounts registered with Blockbuster.
 * data4commands.txt should detail the list of commands to be executed by the Blockbuster automation program.
 * Detailed syntax for these files can be found in assignment4.doc.
 *
 * Blockbuster's constructor automatically initializes the Blockbuster with these files.
 * activateCommands() will run through the commands database and execute them as specified in assignment4.doc.
 * Additional commands, printMovies();, printCustomers(); and printCommands(); are provided to read from the database.
 * All other functions are to aid with the initialization or execution process.
 
Group members:
	Elias Alabssie
	-Wrote Customer.cpp
	-Wrote Customer.h
	-Wrote header for Customer.cpp
	-Implemented destructor for Blockbuster.cpp
	
	Antong Cheng:
	-Wrote Class Descriptions for assignment4design.pdf
	-Wrote MovieDriver.cpp
	-Wrote Movie.cpp
	-Wrote Classic.cpp
	-Wrote Comedy.cpp
	-Wrote Drama.cpp
	-Implemented command execution in Blockbuster.cpp
	-Implemented edge cases in Blockbuster.cpp
	
	Lloyd Deng:
	-Wrote Overview for assignment4design.pdf
	-Drew UML diagram in assignment4design.pdf
	-Wrote Command.cpp
	-Implemented database read and write in Blockbuster.cpp
	-Debugged Blockbuster.cpp

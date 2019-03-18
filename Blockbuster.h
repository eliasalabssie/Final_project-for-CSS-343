#ifndef BLOCKBUSTER_H
#define BLOCKBUSTER_H

#include <iostream>
#include <fstream>
class Blockbuster{
	public: 
		Blockbuster();
		~Blockbuster();
		void BuildCommands(std::ifstream&);
		void BuildCustomers(std::ifstream&);//puts the customers in the data structure
		void BuildMovies(std::ifstream&);//puts the movies in the data structure
	private:
};

#endif

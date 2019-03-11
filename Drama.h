
#ifndef DRAMA_H
#define DRAMA_H
#include "Movie.h"

class Drama: public Movie{
	public:
		Drama();
		Drama(int, std::string, std::string, int);
		
		bool operator==(const Drama&) const;
		bool operator!=(const Drama&) const;
		bool operator>(const Drama&) const;
		bool operator<(const Drama&) const;

		char getGenre() const;
		
		bool isIncomplete() const;
		std::string toString() const;
	private:
		char genre;
};
#endif

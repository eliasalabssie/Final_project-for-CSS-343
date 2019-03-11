
#ifndef COMEDY_H
#define COMEDY_H
#include "Movie.h"

class Comedy: public Movie{
	public:
		Comedy();
		Comedy(int, std::string, std::string, int);
		
		bool operator==(const Comedy&) const;
		bool operator!=(const Comedy&) const;
		bool operator>(const Comedy&) const;
		bool operator<(const Comedy&) const;

		char getGenre() const;
		
		bool isIncomplete() const;
		std::string toString() const;
	private:
		char genre;
};
#endif

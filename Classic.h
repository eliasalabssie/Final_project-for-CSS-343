
#ifndef CLASSIC_H
#define CLASSIC_H		
#include "Movie.h"

class Classic: public Movie{
	public:
		Classic();
		Classic(int, std::string, std::string, std::string, int, int);
		~Classic();

		bool operator==(const Classic&) const;
		bool operator!=(const Classic&) const;
		bool operator>(const Classic&) const;
		bool operator<(const Classic&) const;
		
		char getGenre() const;
		std::string getActor() const;
		int getReleaseMonth() const;

		void setActor(std::string actor);
		void setReleaseMonth(int releaseMonth);
		
		bool isIncomplete() const;
		std::string toString() const;
	private:
		char genre;
		std::string actor;
		int releaseMonth;
};
#endif

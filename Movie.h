#ifndef MOVIE_H
#define MOVIE_H

class Movie{
	public:
		Movie();
		~Movie();

		int getStock() const;
		std::string getDirector() const;
		std::string getTitle() const;
		int getReleaseYear() const;
		
		void setStock(int);
		void setDirector(std::string);
		void setTitle(std::string);
		void setReleaseYear(int);

	private:
		int stock;
		std::string director;
		std::string title;
		int releaseYear;
};
#endif

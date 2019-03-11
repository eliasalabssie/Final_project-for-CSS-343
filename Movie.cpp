
#include "Movie.h"

Movie::Movie(){
	stock = -1;
	director = "";
	title = "";
	releaseYear = -1;
}

Movie::~Movie(){
}

int Movie::getStock() const{
	return stock;
}

std::string Movie::getDirector() const{
	return director;
}

std::string Movie::getTitle() const{
	return title;
}

int Movie::getReleaseYear() const{
	return releaseYear;
}

void Movie::setStock(int stock){
	this->stock = stock;
}

void Movie::setDirector(std::string director){
	this->director = director;
}

void Movie::setTitle(std::string title){
	this->title = title;
}

void Movie::setReleaseYear(int releaseYear){
	this->releaseYear = releaseYear;
}

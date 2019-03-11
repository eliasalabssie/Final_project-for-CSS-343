#include <string>
#include "Drama.h"

Drama::Drama(){
	genre = 'd';
}

Drama::Drama(int stock, std::string director, std::string title, int releaseYear){
	setStock(stock);
	setDirector(director);
	setTitle(title);
	setReleaseYear(releaseYear);
}

bool Drama::operator==(const Drama& other) const {
	return (getDirector() == other.getDirector()) && 
		(getTitle() == other.getTitle()) &&
		(getReleaseYear() == other.getReleaseYear());
}

bool Drama::operator!=(const Drama& other) const {
	return !((*this) == other);
}

bool Drama::operator>(const Drama& other) const {
	if(getDirector().compare(other.getDirector()) > 0){
		return true;
	}
	if(getTitle().compare(other.getTitle()) > 0){
		return true;
	}
	return false;
}
bool Drama::operator<(const Drama& other) const {
	if(getDirector().compare(other.getDirector()) < 0){
		return true;
	}
	if(getTitle().compare(other.getTitle()) < 0){
		return true;
	}
	return false;
}

char Drama::getGenre() const{
	return genre;
}

bool Drama::isIncomplete() const{
	return (getGenre() != 'd') || (getStock() < 0) || (getDirector().compare("") == 0) || 
		(getTitle().compare("") == 0) || (getReleaseYear() < 0);
}


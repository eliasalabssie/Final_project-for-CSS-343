#include <string>
#include "Comedy.h"

Comedy::Comedy(){
	genre = 'f';
}

Comedy::Comedy(int stock, std::string director, std::string title, int releaseYear){
	setStock(stock);
	setDirector(director);
	setTitle(title);
	setReleaseYear(releaseYear);
}

bool Comedy::operator==(const Comedy& other) const {
	return (getDirector() == other.getDirector()) && 
		(getTitle() == other.getTitle()) &&
		(getReleaseYear() == other.getReleaseYear());
}

bool Comedy::operator!=(const Comedy& other) const {
	return !((*this) == other);
}

bool Comedy::operator>(const Comedy& other) const {
	if(getTitle().compare(other.getTitle()) > 0){
		return true;
	}
	if(getReleaseYear() > other.getReleaseYear()){
		return true;
	}
	return false;
}
bool Comedy::operator<(const Comedy& other) const {
	if(getTitle().compare(other.getTitle()) < 0){
		return true;
	}
	if(getReleaseYear() < other.getReleaseYear()){
		return true;
	}
	return false;
}

char Comedy::getGenre() const{
	return genre;
}

bool Comedy::isIncomplete() const{
	return (getGenre() != 'f') || (getStock() < 0) || (getDirector().compare("") == 0) || 
		(getTitle().compare("") == 0) || (getReleaseYear() < 0);
}


#include <string>
#include "Classic.h"

Classic::Classic(){
	genre = 'c';
	actor = "";
	releaseMonth = -1;
}

Classic::~Classic(){
}

Classic::Classic(int stock, std::string director, std::string title, std::string actor, int releaseMonth, int releaseYear){
	this->genre = genre;
	setStock(stock);
	setDirector(director);
	setTitle(title);
	setActor(actor);
	setReleaseMonth(releaseMonth);
	setReleaseYear(releaseYear);
}

bool Classic::operator==(const Classic& other) const {
	return (getDirector() == other.getDirector()) && 
		(getTitle() == other.getTitle()) &&
		(getActor() == other.getActor()) && 
		(getReleaseMonth() == other.getReleaseMonth()) &&
		(getReleaseYear() == other.getReleaseYear());
}

bool Classic::operator!=(const Classic& other) const {
	return !((*this) == other);
}

bool Classic::operator>(const Classic& other) const {
	if(getReleaseYear() > other.getReleaseYear()){
		return true;
	}
	if(getReleaseMonth() > other.getReleaseMonth()){
		return true;
	}
	if((getActor()).compare(other.getActor()) > 0){
		return true;
	}
	return false;
}
bool Classic::operator<(const Classic& other) const {
	if(getReleaseYear() < other.getReleaseYear()){
		return true;
	}
	if(getReleaseMonth() < other.getReleaseMonth()){
		return true;
	}
	if(getActor().compare(other.getActor()) < 0){
		return true;
	}
	return false;
}

std::string Classic::getActor() const{
	return actor;
}

char Classic::getGenre() const{
	return genre;
}

int Classic::getReleaseMonth() const{
	return releaseMonth;
}
		
void Classic::setActor(std::string actor){
	this->actor = actor;
}

void Classic::setReleaseMonth(int releaseMonth){
	this->releaseMonth = releaseMonth;
}

bool Classic::isIncomplete() const{
	return (getGenre() != 'c') || (getStock() < 0) || (getDirector().compare("") == 0) || 
		(getTitle().compare("") == 0) || (getActor().compare("") == 0) ||
		(getReleaseMonth() < 0) || (getReleaseYear() < 0);
}

/*std::string Classic::toString() const{
	if(isIncomplete()){
		return "";
	}
	std::string genreString(1, getGenre());
	return  genreString + "" + getStock() + "" + getDirector() + "" + getTitle() + "" + getActor() + "" + getReleaseMonth() + "" + getReleaseYear();
}*/

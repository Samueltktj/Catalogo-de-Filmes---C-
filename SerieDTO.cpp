#include "SerieDTO.h"



using namespace std;

SerieDTO::SerieDTO(int id, string name,int year,int season,int episodes,string actors,string characters,string channel,double rating) {
    this->id = id;//id da série
    this->nameSerie = name;//nome da série
    this->yearLaunch = year;//ano de lançamento
    this->season = season;//número de temporadas
    this->numberEpisodes = episodes;//número de episódios
    this->mainActors = actors;//lista de atores principais
    this->mainCharacters = characters;//personagens principais
    this->channel = channel;//canal de streaming
    this->rating = rating;//nota da serie
};

SerieDTO::~SerieDTO(){
    
}
//getters
int SerieDTO::getId(){return this -> id;}
string SerieDTO::getName(){return this -> nameSerie;}
int SerieDTO::getYear() {return this -> yearLaunch;}
int SerieDTO::getSeason() {return this -> season;}
int SerieDTO::getEpisodes() {return this -> numberEpisodes;}
string SerieDTO::getActors() {return this -> mainActors;}
string SerieDTO::getCharacters() {return this -> mainCharacters;}
string SerieDTO::getChannel() {return this -> channel;}
double SerieDTO::getRating() {return this -> rating;}
//setters
void SerieDTO::setId(int id){this->id = id;}
void SerieDTO::setName(string name){this->nameSerie = name;}
void SerieDTO::setYear(int year){this->yearLaunch = year;}
void SerieDTO::setSeason(int season){this->season = season;}
void SerieDTO::setEpisodes(int episodes){this->numberEpisodes = episodes;}
void SerieDTO::setActors(string actors){this->mainActors = actors;}
void SerieDTO::setCharacters(string characters){this->mainCharacters = characters;}
void SerieDTO::setChannel(string channel){this->channel = channel;}
void SerieDTO::setRating(double rating){this->rating = rating;}

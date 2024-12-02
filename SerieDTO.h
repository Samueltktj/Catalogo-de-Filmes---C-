#ifndef SERIEDTO_H
#define SERIEDTO_H

#include <vector>
#include <string>


using namespace std;

class SerieDTO {
    private:
		int id;
        string nameSerie;
        int yearLaunch;
        int season;
        int numberEpisodes;
        string mainActors;
        string mainCharacters;
        string channel;
        double rating;
    
    public:
    	SerieDTO(int id, string name,int year,int season,int episodes,string actors,string characters,string channel,double rating);
		~SerieDTO();
		int getId();
		string getName();
	    int getYear();
	    int getSeason();
	    int getEpisodes();
	    string getActors();
	    string getCharacters();
	    string getChannel();
	    double getRating();
		void setId(int id);
		void setName(string name);
		void setYear(int year);
		void setSeason(int season);
		void setEpisodes(int episodes);
		void setActors(string actors);
		void setCharacters(string characters);
		void setChannel(string channel);
		void setRating(double rating);
};
#endif

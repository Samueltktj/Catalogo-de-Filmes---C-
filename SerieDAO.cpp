#include "SerieDAO.h"


using namespace std;

SerieDAO::SerieDAO(MemoryDBConnection* connection) {
    this->DBSeries = connection;
    //delete connection;
};

SerieDAO::~SerieDAO(){
    this->DBSeries = NULL;
    delete this->DBSeries;
}

//getters e setters
MemoryDBConnection* SerieDAO::getDB(){
    return this->DBSeries;
}
//Implementar voids para simular em memoria a execucao e pesquisa de series

//fixing
void SerieDAO::adicionarSerieNova(SerieDTO *serieNova) {
    int id = 1;
    //verifica se nao esta vazio, se estiver sera o primeiro id, entao apenas pula para serieNova->setId(id) e cria a primeira serie de Id 1
    if(!DBSeries->getSeriesDB().empty()){
        //verifica em um loop todos os ids do vetor de DTOs, quando encontra uma similaridade, 
        //incrementa o valor de id, volta ao inicio e verifica a validade do proximo valor id
         for(int i = 0; i < DBSeries->getSeriesDB().size(); i++){
            if(id == DBSeries->getSeriesDB()[i]->getId()) {
                id++;
                i = 0;
            }
        }
    }
    serieNova->setId(id);
    //inserie nova serie no vetor de DTO
    (this->DBSeries->getSeriesDB()).push_back(serieNova);
}

SerieDTO* SerieDAO::buscarSerie(string nomeSerie) {
    //usando expressao lambda encontra serie com o mesmo nome, recebido como string
    auto i = find_if(DBSeries->getSeriesDB().begin(), DBSeries->getSeriesDB().end(), [&nomeSerie](SerieDTO* serie){
        return nomeSerie == serie->getName();
    });
    //se encontrado, retorna o DTO
    if(i != DBSeries->getSeriesDB().end()){
        return *i;
    }
    
}

void SerieDAO::editarSerie(int serieId, string name, int year, int season, int episodes, string actors, string characters, string channel, double rating) {
    //usando expressao lambda encontra serie com o mesmo id, recebido como int
    auto i = find_if(DBSeries->getSeriesDB().begin(), DBSeries->getSeriesDB().end(), [&serieId](SerieDTO* serie){
        return serieId == serie->getId();
    });
    //se encontrado, edita o DTO
    if(i != DBSeries->getSeriesDB().end()){
        (*i)->setName(name);
        (*i)->setYear(year);
        (*i)->setSeason(season);
        (*i)->setEpisodes(episodes);
        (*i)->setActors(actors);
        (*i)->setCharacters(characters);
        (*i)->setChannel(channel);
        (*i)->setRating(rating);
    }
}


void SerieDAO::excluirSerie(int serieId) {
    //usando expressao lambda encontra serie com o mesmo id, recebido como int
    auto i = find_if(DBSeries->getSeriesDB().begin(), DBSeries->getSeriesDB().end(), [&serieId](SerieDTO* serie){
        return serieId == serie->getId();
    });
    //se encontrado, deleta o DTO na posicao em que foi encontrado
    if(i != DBSeries->getSeriesDB().end())
        DBSeries->getSeriesDB().erase(i);

}




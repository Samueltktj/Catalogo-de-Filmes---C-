#ifndef ABSTRACTSERIEDAO_H
#define ABSTRACTSERIEDAO_H

#include "SerieDTO.h"
#include "MemoryDBConnection.h"

class AbstractSerieDAO{
    public: 
        AbstractSerieDAO();
        virtual ~AbstractSerieDAO();
        
        virtual MemoryDBConnection* getDB() = 0;
        virtual void adicionarSerieNova(SerieDTO *serieNova) = 0;
        virtual SerieDTO* buscarSerie(string nomeDaSerie) = 0;
        virtual void editarSerie(int id, string name, int year, int season, int episodes, string actors, string characters, string channel, double rating) = 0;
        virtual void excluirSerie(int serieId) = 0;
};

#endif
#ifndef SERIEDAO_H
#define SERIEDAO_H

#include <algorithm>
#include "AbstractSerieDAO.h"

using namespace std;

class SerieDAO : public AbstractSerieDAO {
    private:
		MemoryDBConnection *DBSeries;
    
    public:
		SerieDAO(MemoryDBConnection* connection);
		~SerieDAO();
		MemoryDBConnection* getDB();
		void adicionarSerieNova(SerieDTO *serieNova);
		SerieDTO* buscarSerie(string nomeDaSerie);
		void editarSerie(int id, string name, int year, int season, int episodes, string actors, string characters, string channel, double rating);
		void excluirSerie(int serieId);
};







#endif

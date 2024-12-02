#include "MemoryDBConnection.h"

vector<SerieDTO*>& MemoryDBConnection::getSeriesDB() {return this->catalogoSeriesDB;}

void MemoryDBConnection::closeConnection(){

    for(SerieDTO* indexDelete : this->getSeriesDB()){
        delete indexDelete;
        indexDelete = NULL;
    }

    this->catalogoSeriesDB.clear();
}

MemoryDBConnection::~MemoryDBConnection() {this->closeConnection();}
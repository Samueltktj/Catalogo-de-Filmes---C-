#ifndef MEMORYDBCONNECTION_H
#define MEMORYDBCONNECTION_H

#include <vector>
#include "SerieDTO.h"

class MemoryDBConnection{
    private:
        vector<SerieDTO*> catalogoSeriesDB;
    public:
        vector<SerieDTO*>& getSeriesDB();
        virtual ~MemoryDBConnection();
        void closeConnection();

};

#endif
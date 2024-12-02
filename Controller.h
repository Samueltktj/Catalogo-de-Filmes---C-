#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <functional>
#include <stdexcept>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <string>
#include <iomanip>

#include "Menu.h"
#include "SistInfo.h"
#include "SerieDTO.h"
#include "SerieDAO.h"
#include "ChooseDataBase.h"
#include "MemoryDBConnection.h"


class Controller{
    private:
        MemoryDBConnection *BDMemory;
        //ServerDBConnection *BDServer; TO-DO
        SerieDAO *SDAO;
    public:
        Controller(ChooseDataBase choice);
        ~Controller();
        void start();
        void simulPreEntries();
        void addSerie();
        void searchSerie();
        void editSerie();
        void series();
        void helpSis();
        void reportByTitle();
        void reportByChannel();
        void reportByYear();
        void reportByRating();
        void reports();
        void credits();
        void clearS();
        void removeSerie();

};




#endif

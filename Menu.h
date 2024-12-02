#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Menu{
    private:
        string title;
        vector<string> options;
        static const char symbol;
    public:
        Menu(string title, vector<string> options);
        string getTitle();
        vector<string> getOptions();
        char getSymbol();
        string getSymbolLine(int change = 0);
        void setTitle(string title);
        void setOptions(vector<string> options);
        
        friend ostream& operator<<(ostream& os, Menu& menu);

};


#endif

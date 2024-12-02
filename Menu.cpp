#include "Menu.h"

    const char Menu::symbol = 62;

    Menu::Menu(string title, vector<string> options){
        this->title = title;
        this->options = options;
    }
//getters e setters
    string Menu::getTitle(){return this->title;}
    vector<string> Menu::getOptions(){return this->options;}
    char Menu::getSymbol(){return symbol;}
    void Menu::setTitle(string title){title = this->title;}
    void Menu::setOptions(vector<string> options){this->options = options;}

//cria uma linha com o simbolo de menu para separar as opcoes
    string Menu::getSymbolLine(int change){
        string symbolLine;
        int index = 0;
        while(index < 26){
            symbolLine += getSymbol() - change;
            index++;
        }
        return symbolLine;
    }
//sobrecarga de operador para imprimir o menu
    ostream& operator<<(ostream& os, Menu& menu) {
        os
        <<"\n"
        <<menu.getSymbolLine()
        <<"\n"
        <<menu.getTitle()
        <<"\n"
        <<menu.getSymbolLine(2)
        <<endl;
        int *counter = new int(1);
        for (string& option : menu.getOptions()) {
            os <<*counter<<". "<< option << "\n";
            (*counter)++;
        }
        os
        <<menu.getSymbolLine()
        <<endl;

        counter = NULL;
        delete counter;
        return os;
    }
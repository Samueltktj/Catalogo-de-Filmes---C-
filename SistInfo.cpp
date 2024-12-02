#include "SistInfo.h"

using namespace std;
//dados constantes da classe
const vector <string> SistInfo::members = {"Alona Nicolau", "Gabriel Romualdo", "Roberto Kendy", "Samuel Calegnan", "Samuel Lima"};
const string SistInfo::discipline = "SI300";
const string SistInfo::advisor = "Andre Angelis";
const string SistInfo::group = "Grupo 5";
const string SistInfo::university = "FT-Unicamp";
const string SistInfo::release= "16-06-2024";
const string SistInfo::compilationVersion = "C++11";
const string SistInfo::version = "V3";
const string SistInfo::barLine = "##########################";
const string SistInfo::helpFile = "HELP.txt";

//getters
const vector<string>& SistInfo::getMembers() {
    return members;
}

const string& SistInfo::getDiscipline() {
    return discipline;
}

const string& SistInfo::getAdvisor() {
    return advisor;
}

const string& SistInfo::getGroup() {
    return group;
}

const string& SistInfo::getUniversity() {
    return university;
}

const string& SistInfo::getRelease() {
    return release;
}

const string& SistInfo::getBarLine() {
    return barLine;
}

const string& SistInfo::getVersion(){
    return version;
}

const string& SistInfo::getCompilatedVersion(){
    return compilationVersion;
}

const string& SistInfo::getHelpFile(){
    return helpFile;
}



#include <vector>
#include "Controller.h"

using namespace std;

void welcome();

int main(){
	

	welcome();

	Controller *starting = new Controller(ChooseDataBase::MEMORY);
	starting->start();

	delete starting;
	return 0;
}


void welcome(){

	cout
	<<SistInfo::getBarLine()
	<<"\nCatalogo de Series\n"
	<<SistInfo::getBarLine()<<"\n"
	<<"Release: "<<SistInfo::getRelease()
	<<"\nVersion: "<<SistInfo::getVersion()
	<<"\n"
	<<SistInfo::getBarLine()
	<<"\n"
	<<endl;

};

#include "Controller.h"

Controller::Controller(ChooseDataBase choice){
    this->BDMemory = NULL;
    //this->BDServer = NULL;
    switch (choice){
        case ChooseDataBase::MARIADB:
            this->clearS();
            cout<<"\n@@@@@@@@@@@@@@@@@@@@@@@@@\n"
                <<  "   !!NAO IMPLEMENTADO!!  "
                <<"\n@@@@@@@@@@@@@@@@@@@@@@@@@\n"<<endl;
            break;
        case ChooseDataBase::MEMORY:
            this->clearS();
            this->BDMemory = new MemoryDBConnection();
            this->SDAO = new SerieDAO(BDMemory);
            cout<<
            "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<
            "\n -=Conexao em Memoria Instaurada=- \n"<<
            "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"<<endl;
            
            cout<<"\n...Pressione Enter para Prosseguir..."<<endl;
            while(getchar() != '\n');
            break;
    }
};

Controller::~Controller(){
            this->SDAO = NULL;
            this->BDMemory = NULL;
            delete SDAO;
            delete BDMemory;
}

//funcao para inserir dados previamente adiciondos para fim de testes
void Controller::simulPreEntries(){
    SDAO->adicionarSerieNova(new SerieDTO(0, "Breaking Bad", 2008, 5, 62, "Bryan Cranston", "Walter White", "Netflix", 9.5));
    SDAO->adicionarSerieNova(new SerieDTO(0, "Orange Is The New Black", 2013, 7, 91, "Taylor Schilling", "Piper Chapman", "Netflix", 8.1));
    SDAO->adicionarSerieNova(new SerieDTO(0, "Prison Break", 2005, 5, 90, "Wentworth Miller", "Michael Scofield", "Disney+", 8.3));
    SDAO->adicionarSerieNova(new SerieDTO(0, "The Walking Dead", 2010, 11, 177, "Andrew Lincoln", "Rick Grimes", "Netflix", 8.1));
    SDAO->adicionarSerieNova(new SerieDTO(0, "Supernatural", 2005, 15, 327, "Jared Padlecki", "Sam Winchester", "Netflix", 8.4));
    SDAO->adicionarSerieNova(new SerieDTO(0, "How I Met Your Mother", 2005, 9, 208, "Josh Radnor", "Ted Mosby", "Disney+", 8.3));
    SDAO->adicionarSerieNova(new SerieDTO(0, "Bones", 2005, 12, 246, "Emily Deschanel", "Dr. Temperance Brennan", "Disney+", 7.8));
    SDAO->adicionarSerieNova(new SerieDTO(0, "Arrow", 2012, 8, 170, "Stephen Amell", "Oliver Queen", "Netflix", 7.5));
    SDAO->adicionarSerieNova(new SerieDTO(0, "Chicago Fire", 2012, 11, 239, "Jesse Spencer", "Matthew Casey", "Amazon Prime Video", 8.0));
    SDAO->adicionarSerieNova(new SerieDTO(0, "The Newsroom", 2012, 3, 25, "Jeff Daniels", "Will McAvoy", "HBO Max", 8.6));
}

//funcao de boot
void Controller::start(){
    //chama metodo simulador de entradas anteriores
    this->simulPreEntries();
    
    string *choice = new string;
    
        //vetor de opcoes
    vector<string> *options = new vector<string>{"Series","Relatorios","Ajuda","Creditos","Sair"};
        //vetor de funcoes
    vector<function <void()>> * functions = new vector<function <void()>> 
    {[this]() {this->series();},  [this]() {this->reports();}, [this]() {this->helpSis();}, [this]() {this->credits();}};
    
        //instancia de menu
    Menu* menu = new Menu("Inicio", *options);

    
    while(1){
        this->clearS();
  
        //imprime menu sobrecarregando operador de stream
        cout<<*menu<<endl;
        //pega escolha do usuario
        getline(cin, *choice); 
       try{
            //se maior ou menor do que as opcoes, envia erro
            if(stoi(*choice)<1 || stoi(*choice)>5)
                throw invalid_argument("wrong");
            //se igual a 5, encerra o void
            if(stoi(*choice)==5){
                this->clearS();
                delete options;
                delete menu;
                delete choice;
                delete functions;
                return;
                break;                
            }
            //chama funcao na posicao do vetor
            (*functions)[stoi(*choice)-1]();

        }catch(exception &err){   
                cout<<"\n!!OPCAO INVALIDA!!"<<endl;
                cout<<"...Pressione Enter Para Continuar..."<<endl;
                while(getchar() != '\n'){   
                }
        }
        
    }
}

void Controller::addSerie(){
    this->clearS();

    Menu    *menu = new Menu("!INCLUSAO DE NOVO REGISTRO!",{"Insira os dados conforme pedido"});
    string  *nome = new string;
    string  *year = new string;
    string  *season = new string;
    string  *episodes = new string;
    string  *actor = new string;
    string  *character = new string;
    string  *channel = new string;
    string  *rating = new string;
//imprime menu de insercao de serie
    cout<<*menu<<endl;
//adquire dados do usuario
    cout<<"\nNome da Serie: ";
    getline(cin, *nome);
    cout<<"\nAno de lancamento: ";
    getline(cin, *year);
    cout<<"\nNumero de Temporadas: ";
    getline(cin, *season);
    cout<<"\nNumero de Episodios: ";
    getline(cin, *episodes);
    cout<<"\nAtor Principal: ";
    getline(cin, *actor);
    cout<<"\nPersonagem Principal: ";
    getline(cin, *character);
    cout<<"\nCanal de Stream: ";
    getline(cin, *channel);
    cout<<"\nNota no IMDb: ";
    getline(cin, *rating);
    try{
        //chama metodo para adicionar nova serie
        SDAO->adicionarSerieNova(new SerieDTO(0, *nome, stoi(*year), stoi(*season), stoi(*episodes), *actor, *character, *channel, stod(*rating)));
    }
    catch(exception &err){
        cout<<"\n!!Tipos de dados incorretos!!"<<endl;
    }
    cout<< "\n...Pressione Enter para Continuar..."<<endl;
    getchar();
    delete nome;
    delete year;
    delete season;
    delete episodes;
    delete actor;
    delete character;
    delete channel;
    delete rating;
    return;
}

void Controller::searchSerie(){
    
    this->clearS();
    
    string* name = new string;
    string* barline = new string
    ("\n###################################################\n");


    cout <<*barline<< "Digite abaixo o nome da serie que deseja recuperar\n"<<endl;
    //pega escolha do usuario
    getline(cin, *name);
        //encontra instancia que haja o mesmo getName
        auto i = find_if(SDAO->getDB()->getSeriesDB().begin(), SDAO->getDB()->getSeriesDB().end(), [&name](SerieDTO* serie) {
            return serie->getName() == *name;
        });
        //caso encontrar imprime a serie
        if (i != SDAO->getDB()->getSeriesDB().end()) {
            cout << *barline <<"\nSERIE ESCOLHIDA\n\n";
            cout << "ID: \t\t\t\t" + to_string((*i)->getId()) + "\n";
            cout << "Nome: \t\t\t\t" + (*i)->getName() + "\n";
            cout << "Lancamento:\t\t\t" + to_string((*i)->getYear()) + "\n";
            cout << "Temporadas: \t\t\t" + to_string((*i)->getSeason()) + "\n";
            cout << "Episodios: \t\t\t" + to_string((*i)->getEpisodes()) + "\n";
            cout << "Ator Principal:\t\t\t" + (*i)->getActors() + "\n";
            cout << "Personagem Principal:\t\t" + (*i)->getCharacters() + "\n";
            cout << "Disponivel em: \t\t\t" + (*i)->getChannel() + "\n";
            cout << "Nota no IMDb: \t\t\t"<< (*i)->getRating()<< "\n" + *barline;
            cout<< "\n...Pressione Enter para Continuar..."<<endl;
            while(getchar()!='\n'){};
        }//caso nao, imprime aviso que nao foi encontrada
        else{
            cout<<"Nenhum registro com este nome!"<<endl;
            cout<< "\n...Pressione Enter para Continuar..."<<endl;
            while(getchar()!='\n'){}
        }

        delete name;
        delete barline;
        return;
}

void Controller::editSerie(){

    this->clearS();
    string* id = new string;
    string* name = new string;
    string* launch = new string;
    string* season = new string;
    string *episodes = new string;
    string* actor = new string;
    string* character = new string;
    string* channel = new string;
    string* rating = new string;

    string* barline = new string("\n###################################################\n");

    cout <<*barline<< "Digite abaixo o ID da serie que deseja editar\n"<<endl;

    getline(cin, *id);
    
    try{
        //encontra serie com mesmo valor de id
        auto i = find_if(SDAO->getDB()->getSeriesDB().begin(), SDAO->getDB()->getSeriesDB().end(), [&id](SerieDTO* serie){
            return stoi(*id) == serie->getId();
        }); 
        
        if (i != SDAO->getDB()->getSeriesDB().end()) {
            cout << *barline <<"\nSERIE EM EDICAO(enter para nao alterar)\n\n";
            //para cada uma das opcoes, verifica se nao ha nada inserido, ou seja "", neste caso, permanece o mesmo valor, atribuindo o valor da serie que esta sendo editada a variavel de edicao do metodo
            cout << "Nome: \t\t\t\t" + (*i)->getName() + 
            "\n\nNOVO NOME: ";
            getline(cin, *name);
            if(*name == "")
                *name = (*i)->getName();

            cout << "Lancamento:\t\t\t" + to_string((*i)->getYear()) + 
            "\n\nNOVO LANCAMENTO: ";
            getline(cin, *launch);
            if(*launch == "")
                *launch = to_string((*i)->getYear());
                    
            cout << "Temporadas: \t\t\t" + to_string((*i)->getSeason()) + 
            "\n\nNOVO TEMPORADAS: ";
            getline(cin, *season);
            if(*season == "")
                *season = to_string((*i)->getSeason());
            
            cout << "Episodios: \t\t\t" + to_string((*i)->getEpisodes()) + 
            "\n\nNOVO EPISODIOS:";
            getline(cin, *episodes);
            if(*episodes == "")
                *episodes = to_string((*i)->getEpisodes());
                    
            cout << "Ator Principal:\t\t\t" + (*i)->getActors() + 
            "\n\nNOVO ATOR PRINCIPAL: ";
            getline(cin, *actor);
            if(*actor == "")
                *actor = (*i)->getActors();
                    
            cout << "Personagem Principal:\t\t" + (*i)->getCharacters() 
            + "\n\nNOVO PERSONAGEM PRINCIPAL: ";
            getline(cin, *character);
            if(*character == "")
                *character = (*i)->getCharacters();
                    
            cout << "Disponivel em: \t\t\t" + (*i)->getChannel() + "\n\nNOVO CANAL: ";
            getline(cin, *channel);
            if(*channel == "")
                *channel = (*i)->getChannel();
                    
                    
            cout << "Nota no IMDb: \t\t\t"<< (*i)->getRating()<< 
            "\n\nNOVA NOTA: ";
            getline(cin, *rating);
            if(*rating == "")
                *rating = to_string((*i)->getRating());
            //chama metodo editar serie
            SDAO->editarSerie((*i)->getId(), *name, stoi(*launch), stoi(*season), stoi(*episodes), *actor, *character, *channel, stod(*rating));
        }else{
            cout<<"\n\t!Serie Inexistente!\n"<<endl;
        }
    }catch(exception &err){
        cout<<"\n\t!Tipos de Dado Incorretos!\n";
    }
        
    cout<< "\n...Pressione Enter para Continuar..."<<endl;
    while(getchar() != '\n'){};
    delete id;
    delete barline;
}

void Controller::removeSerie() {
    
    this->clearS();
    string *id = new string;
    string *barline = new string
    ("\n###################################################\n");

    cout << *barline << "Digite abaixo o ID da serie que deseja excluir:\n" << endl;

    getline(cin, *id);
    //encontra serie de mesmo id
    auto i = find_if(SDAO->getDB()->getSeriesDB().begin(), SDAO->getDB()->getSeriesDB().end(), [&id](SerieDTO* serie){
        return stoi(*id) == serie->getId();
    });
    try{
        if (i != SDAO->getDB()->getSeriesDB().end()) {
            //chama o metodo DAO de delecao
            SDAO->excluirSerie((*i)->getId());
            cout << "Serie removida com sucesso!" << endl;
        }else{
            cout << "Nenhuma serie encontrada com esse ID!" << endl;
        }
    }
    catch(exception &err){
        cout<<"\n !Tipo de Dado Incorreto! \n"<<endl;
    }

    cout << "\n...Pressione Enter para Continuar..." << endl;
    while(getchar()!='\n'){};

    delete id;
    delete barline;
}

void Controller::series(){
    //opcoes de series
    vector<string> *options = new vector<string>{"Incluir um novo registro","Recuperar um registro","Editar um registro", "Excluir um registro", "Voltar"};
    vector<function<void()>> *functions = new vector<function<void()>>
    {[this]{this->addSerie();},[this]{this->searchSerie();},[this]{this->editSerie();},[this]{this->removeSerie();}};
    
    //instancia menu da opcao series
    Menu *menu = new Menu("Series", *options);
    string *choice = new string;

    while(1){
        this->clearS();
        cout<<*menu<<endl;
        getline(cin, *choice);

        try{
            //se maior ou menor que as opcoes, joga erro
            if(stoi(*choice)<1 || stoi(*choice)>5)
                throw invalid_argument("wrong");     
            //se igual a 5, encerra o void, unica saida do void basicamente
            if(stoi(*choice) == 5){
                this->clearS();
                delete options;
                delete menu;
                delete choice;
                delete functions;
                return;
            }
            //chama a funcao escolhida, menos 1 para precisao do vetor
            (*functions)[stoi(*choice)-1]();
        }catch(exception &err){    
            cout<<"\n!!OPCAO INVALIDA!!"<<endl;
            cout<<"...Pressione Enter Para Continuar..."<<endl;
            while(getchar() != '\n'){
            }
        }
    }
}

void Controller::reportByTitle(){
    
    this->clearS();

   //ordenar vetor por nome usando expressao lambda
   sort(SDAO->getDB()->getSeriesDB().begin(), SDAO->getDB()->getSeriesDB().end(), [](SerieDTO* a, SerieDTO* b){
        return a->getName() < b->getName();
   });

    cout<<"###############################################################\n"
    <<right<<setw(10)<<"!LISTA DE SERIES ORDENADA POR TITULO!\n"<<endl;

    //exibir os nomes e os ids das series com um for do vetor do db
    cout<<left<<setw(40)<<"SERIE"<<right<<setw(11)<<"ID\n"<<endl;
    for(auto i : SDAO->getDB()->getSeriesDB()){
        cout<<  left    <<  setw(40)    << i->getName() <<  right   << setw(10)<< i->getId() <<endl; 
    }


    cout<<"###############################################################\n"
        << "\n...Pressione Enter para Continuar..." << endl;
    while(getchar()!='\n'){};

}

void Controller::reportByChannel(){
   
    this->clearS();
    //ordenar vetor por canal usando expressao lambda
    sort(SDAO->getDB()->getSeriesDB().begin(), SDAO->getDB()->getSeriesDB().end(), [](SerieDTO* a, SerieDTO* b){
        return a->getChannel() < b->getChannel();
    });

    cout<<"################################################################\n"
    <<right<<setw(45)<<"!LISTA DE SERIES ORDENADA POR CANAL!\n"<<endl;

    //exibir os canais e os ids das series
    cout<<left<<setw(40)<<"CANAL"<<right<<setw(9)<<"SERIE"<<
    "\n----------------------------------------------------------------"<<endl;
    for(auto i : SDAO->getDB()->getSeriesDB()){
        cout<<  left    <<  setw(40)    << i->getChannel() <<  right   << setw(5)<< i->getName() <<endl; 
    }

        
    cout<<"################################################################\n"
        << "\n...Pressione Enter para Continuar..." << endl;
    while(getchar()!='\n'){};

}

void Controller::reportByYear(){
  
    this->clearS();
    //ordenar o vetor por ordem de ano, pelo getyear de cada um
    sort(SDAO->getDB()->getSeriesDB().begin(), SDAO->getDB()->getSeriesDB().end(), [](SerieDTO* a, SerieDTO* b){
        return a->getYear() < b->getYear();
    });

    cout<<"################################################################\n"
    <<right<<setw(45)<<"!LISTA DE SERIES ORDENADA POR CANAL!\n"<<endl;
    
    //imprimir ano e nome de cada serie chamando for de vetor do db
    cout<<left<<setw(40)<<"ANO"<<right<<setw(9)<<"SERIE"<<
    "\n----------------------------------------------------------------"<<endl;


    for(auto i : SDAO->getDB()->getSeriesDB()){
        cout<<  left    <<  setw(40)    << i->getYear() <<  right   << setw(5)<< i->getName() <<endl; 
    }

        
    cout<<"################################################################\n"
        << "\n...Pressione Enter para Continuar..." << endl;
    while(getchar()!='\n'){};

}

void Controller::reportByRating(){
    
    this->clearS();
    //organizar vetor db por ordem de nota, getrating
    sort(SDAO->getDB()->getSeriesDB().begin(), SDAO->getDB()->getSeriesDB().end(), [](SerieDTO* a, SerieDTO* b){
        return a->getRating() < b->getRating();
    });

    cout<<"################################################################\n"
    <<right<<setw(45)<<"!LISTA DE SERIES ORDENADA POR CANAL!\n"<<endl;


    //listar nome e nota em um for de vetor do db
    cout<<left<<setw(40)<<"SERIE"<<right<<setw(10)<<"NOTA"<<
    "\n----------------------------------------------------------------"<<endl;

    for(auto i : SDAO->getDB()->getSeriesDB()){
        cout<<  left    <<  setw(40)    << i->getName() <<  right   << setw(5)<< i->getRating() <<endl; 
    }
        
    cout<<"################################################################\n"
        << "\n...Pressione Enter para Continuar..." << endl;
    while(getchar()!='\n'){};
}

void Controller::reports(){
    //opcoes de relatorios
    vector<string> *options = new vector<string>{"Registros ordenados por titulo","Registros ordenados por canal/streaming","Registros ordenados por ano", "Registros ordenados por nota", "Voltar"};
    //vetor de metodos
    vector<function <void()>> *functions = new vector<function<void()>>
    {[this]{this->reportByTitle();}, [this]{this->reportByChannel();}, [this]{this->reportByYear();}, [this]{this->reportByRating();}};

    //instancia menu da opcao reports
    Menu *menu = new Menu("Reports", *options);
    string *choice = new string;

    while(1){

        this->clearS();
        cout<<*menu<<endl;
        getline(cin, *choice);
        
        try{
            //se escolha menor que um, ou maior que cinco, joga erro
            if(stoi(*choice)<1||stoi(*choice)>5)
                throw invalid_argument("wrong");
            //se escolha igual a 5, encerra o void, unica saida do void por conta da prisao de while
            if(stoi(*choice) == 5){
                delete choice;
                delete menu;
                delete options;
                delete functions;
                return;
            }
            //chama funcao no vetor de funcoes, na posicao da escolha
            (*functions)[stoi(*choice)-1]();
            
        }catch(exception &err){
            cout<<"\n!!OPCAO INVALIDA!!"<<endl;
            cout<<"...Pressione Enter Para Continuar..."<<endl;
            while(getchar() != '\n'){}
        }
    }
}

void Controller::helpSis(){

    this->clearS();
    //abre arquivo na variavel help
    ifstream help(SistInfo::getHelpFile());
    //verifica se esta aberto, caso nao, joga, avisa erro e sai do void
    if(!help.is_open()){
        cout<<"50: ERRO NO ARQUIVO DE AJUDA\n"<<endl;
        cout<<"...Pressione Enter Para Continuar..."<<endl;
        while(getchar() != '\n'){}
        return;
    }
    //variavel para ler o arquivo
    string* reading = new string;
    
    //enquanto nao chegar no final, inputar na stream da variavel a stream do arquivo
    while(getline(help, *reading)){
        cout<<*reading<<endl;
    }
    //fecha e deleta os ponteiros
    reading = NULL;
    delete reading;
    help.close();

    cout<<"\n...Pressione Enter para Prosseguir..."<<endl;
    while(getchar()!='\n'){};
}

void Controller::credits(){
    this->clearS();

    cout
    <<"\n"
    <<SistInfo::getBarLine()
    <<"\n"
    << "Advisor: "<< SistInfo::getAdvisor()
    <<"\n"
    << "Discipline: "<<SistInfo::getDiscipline()
    <<"\n"
    << "University: "<<SistInfo::getUniversity()
    <<"\n"
    <<SistInfo::getBarLine()
    <<"\n"
    << "Group: "<<SistInfo::getGroup()<<"\n"
    << "Members: \n";
    for (const string& member : SistInfo::getMembers()) {
        cout << member << "\n";
    }
    cout
    << SistInfo::getBarLine() 
    <<"\nRelease: "<<SistInfo::getRelease()
    <<"\n"
    <<SistInfo::getBarLine()
    <<"\n"
    <<endl;

    cout<<"\n...Pressione Enter para Prosseguir..."<<endl;
    while(getchar() != '\n'){};

}

void Controller::clearS() {
    
    //definicoes para limpeza de tela para diferentes OS

    #ifdef linux
    system("clear");
    #endif // linux

    #ifdef _WIN32
    system("cls");
    #endif // _WIN32

    #ifdef _WIN64
    system("cls");
    #endif // _WIN64
}



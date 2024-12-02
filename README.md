# Noite_10

## Instrucoes para compilar

1. Compilar atraves do cmd com o comando: 
    g++ -std=c++11 Start.cpp Controller.cpp Menu.cpp SistInfo.cpp SerieDTO.cpp AbstractSerieDAO.cpp SerieDAO.cpp MemoryDBConnection.cpp -o catalogo
2. Executar com .\catalogo
3. Caso haja adicao de classes, adicionar o cpp das mesmas.

## Acesso ao MariaDB

* Usuário: Si300A2024_10
* Senha: iKi3tezgGP

### Comandos

* Configuração Inicial:
    * git config --global user.name "Seu Nome": Define o nome do usuário globalmente.
    * git config --global user.email "seuemail@example.com": Define o email do usuário globalmente.

* Iniciar um Repositório:
    * git init: Inicia um novo repositório Git localmente na pasta atual.

* Clonar um Repositório Existente:
    * git clone <url>: Clona um repositório Git existente para o diretório local.

* Adicionar e Confirmar Mudanças:
    * git add <nome-do-arquivo>: Adiciona arquivos ao staging area.
    * git add .: Adiciona todos os arquivos modificados ao staging area.
    * git commit -m "Mensagem do commit": Confirma as mudanças com uma mensagem descritiva.

* Verificar o Status das Mudanças:
    * git status: Mostra o estado atual do repositório e das mudanças.

* Atualizar e Sincronizar:
    * git pull: Atualiza o repositório local com as mudanças do repositório remoto.
    * git push: Sincroniza as mudanças locais com o repositório remoto.

* Ramificação (Branching) e Mesclagem (Merging):
    * git branch: Lista as ramificações locais.
    * git branch <nome-da-branch>: Cria uma nova ramificação.
    * git checkout <nome-da-branch>: Muda para uma ramificação específica.
    * git merge <nome-da-branch>: Mescla uma ramificação específica na ramificação atual.

* Visualizar Histórico:
    * git log: Mostra o histórico de commits.
    * git log --oneline: Mostra o histórico de commits em uma linha por commit.

* Desfazer Mudanças:
    * git reset --hard HEAD: Desfaz todas as mudanças locais.
    * git checkout -- <nome-do-arquivo>: Desfaz as mudanças em um arquivo específico.

* GitHub:
    * git remote add origin <url-do-repositório>: Adiciona um repositório remoto.
    * git remote -v: Lista todos os repositórios remotos.
    * git push -u origin <nome-da-branch>: Envia a ramificação atual para o repositório remoto.


* Compilar no C++
    * g++ -o programa.exe <arquivo.cpp> <arquivo.cpp> <arquivo.cpp> ...



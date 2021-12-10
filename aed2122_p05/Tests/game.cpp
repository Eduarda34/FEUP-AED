#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;


unsigned int Game::numberOfWords(string phrase) {
  if ( phrase.length() == 0 ) return 0;

  unsigned n=1;
  size_t pos = phrase.find(' ');
  while (pos != string::npos) {
    phrase = phrase.substr(pos+1);
    pos = phrase.find(' ');
    n++;
  }
  return n;
}

Game::Game() {
	this->kids.clear();
}

Game::Game(list<Kid>& l2) {
	this->kids = l2;
}

//-----------------------------------------------------------------

//1. (a)
void Game::addKid(const Kid k1) {
    kids.push_back(k1); //Adiciona mais uma criança
}

//1. (a)
list<Kid> Game::getKids() const {
    return kids;  //Número de crianças em jogo
}

//1. (a)
void Game::setKids(const list<Kid>& l1) {
    this -> kids = l1;
}

//1. (b)
Kid Game::loseGame(string phrase) {
    int words = numberOfWords(phrase);
    int index = 0;
    while(kids.size() > 1){ //Enquanto existirem crianças em jogo
        index = (words - 1 + index) % kids.size(); //Determina o número de palavras existentes na frase
        list<Kid>:: iterator  it; //iterator: apontam para os endereços de memória; Reduzem a complexidade e tempo de execução
        it = kids.begin();

        for(int i=0; i < index; i++)
            it++;

        kids.remove(*it);
    }
    return kids.front(); //Retorna a criança que perde
}

//1. (d)
list<Kid> Game::removeOlder(unsigned id) {
    list<Kid> result = {};
    for(auto kid : kids){
        if(kid.getAge() > id){
            kids.remove(kid);
            result.push_back(kid);
        }
    }
    return result;
}

//1. (c)
queue<Kid> Game::rearrange() {
    queue<Kid> queueMenino;
    queue<Kid> queueMenina;
    list<Kid> final;
    queue<Kid> result;

    for(auto kid:kids){
        if(kid.getSex() == 'm')
            queueMenino.push(kid);
        else
            queueMenina.push(kid);
    }

    int n = queueMenina.size();
    int m = queueMenino.size();
    int boys = m/n;
    int girls = n/m;

    if(n < m){
        while (m>0 && n>0){
            final.push_back(queueMenina.front());
            queueMenina.pop();
            n--;
            for(int i=0; i < boys; i++){
                final.push_back(queueMenino.front());
                queueMenino.pop();
                m--;
            }
        }
    }
    else{
        while(m>0 && n>0){
            final.push_back(queueMenino.front());
            queueMenino.pop();
            m--;
            for(int i=0; i < girls; i++){
                final.push_back(queueMenina.front());
                queueMenina.pop();
                n--;
            }
        }
    }

    kids = final;
    while(queueMenino.size() > 0){
        result.push(queueMenino.front()); //push() -> Insere elemento na queue
        queueMenino.pop(); //pop() -> Remove elemento da queue
    }

    while(queueMenina.size() > 0){
        result.push(queueMenina.front());
        queueMenina.pop();
    }
    return result;
}

//1. (e)
bool Game::operator==(Game& g2) {
    if(this->kids.size() != g2.getKids().size())
        return false;

    else{
        for(int i=0; i < kids.size(); i++){
            if(!(this->kids.front() == g2.getKids().front()))
                return false;
        }
    }
    return true;
}

//1. (f)
list<Kid> Game::shuffle() const {
    list<Kid> result = {}, k = kids;
    int index;
    while (k.size()) {
        index = rand() % k.size(); // random index in [0..k.size()]
        int i = 0;
        for (auto kid : k) { //Tipo da variável é deduzido automaticamente do seu inicializador
            if (i == index) {
                result.push_back(kid);
                k.remove(kid);
                break;
            }
            i++;
        }
    }
    return result;
}

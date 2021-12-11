#include <iostream>
#include <string>
#include <fstream>
#include "dictionary.h"
#include <algorithm>

using namespace std;

WordMean::WordMean(string w, string m): word(w), meaning(m) {}

string WordMean::getWord() const {
    return word;
}

string WordMean::getMeaning() const {
    return meaning;
}

void WordMean::setMeaning(string m) {
    meaning = m;
}

void WordMean::setWord(string w) {
    word = w;
}

bool operator<(const WordMean &d1,const WordMean &d2){
    return d1.getWord()<d2.getWord();
}
bool operator>(const WordMean &d1,const WordMean &d2){
    return d1.getWord()>d2.getWord();
}
bool operator==(const WordMean &d1,const WordMean &d2) {
    return d1.getWord() == d2.getWord();
}

void WordMean::operator=(const WordMean &d1) {
    word = d1.getWord();
    meaning = d1.getMeaning();
    return;
}
ostream& operator<<(ostream& os, const WordMean& d){
    os<<d.getWord()<<endl<<d.getMeaning();
    return os;
}


BST<WordMean> Dictionary::getWords() const {
    return words;
}

// ---------------------------------------------

//1. (a)
void Dictionary::readFile(ifstream &f) {
    string palavra;
    string significado;
    while(getline(f, palavra)){
        getline(f, significado);
        WordMean coiso(palavra, significado);
        words.insert(coiso);
    }
}

//1. (c)
string Dictionary::consult(string word1, WordMean& previous, WordMean& next) const {
    WordMean *a;
    (*a) = words.find(WordMean(word1, ""));
    if(a != NULL)
        return a -> getMeaning();

    return "word not found";
}

//TODO
bool Dictionary::update(string word1, string mean1) {
    return true;
}

//1. (b)
void Dictionary::print() const {
    words.printTree();
}
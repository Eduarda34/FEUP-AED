#include "funSearchProblem.h"

FunSearchProblem::FunSearchProblem() {}

//-----------------------------------------------------------------

//1. (a)
int FunSearchProblem::facingSun(const vector<int> & values) {
    int edif = 1; //Assumir que existe pelo menos um edifício

    if(values.size() == 0) //Não existência de edifícios (vetor nulo)
        edif = 0;

    else{
        for(int i=1; i < values.size(); i++){
            if(values[i-1] < values[i]) //Compara o edifício com o seguinte
                edif++;
        }
    }
    return edif;
}

//1. (b)
int FunSearchProblem::squareR(int num) {
    int inicial = 0;
    int final = num;
    int centro;

    while (inicial != final){
        centro = (inicial + final) / 2;
        if(centro * centro < num){
            if(inicial == centro)
                return centro;
            inicial = centro;
        }

        if(centro * centro > num)
            final = centro;

        if(centro * centro == num){
            inicial = final = centro;
        }
    }
    return centro;
}

//1. (c)
int FunSearchProblem::smallestMissingValue(const vector<int> & values) {
    return 0;
}

//1. (d) *exercício extra*
int FunSearchProblem::minPages(const vector<int> & values, int numSt) {
    int sum = 0;
    int const refValue = sum / numSt;
    int pagAtual = 0, numLivros = 0;

    for(auto const pages : values)
        sum += pages;

    for(int i=0; i < values.size()-1; i++){
        pagAtual += values[i];

        if(pagAtual <= refValue || numLivros == 0)
            numLivros++;

        else{
            cout << "The student " << numSt << " has " << numLivros << " books with " << pagAtual << " pages\n";
            numSt--;
            pagAtual = numLivros = 0;
        }
    }
    return -1;
}


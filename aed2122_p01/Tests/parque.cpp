#include "parque.h"
#include <vector>

using namespace std;

//1. (a)
ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli) {
    this->clientes={};
    this->vagas=lotacao;
}

unsigned ParqueEstacionamento::getNumLugares() const {
    return lotacao;
}

unsigned ParqueEstacionamento::getNumMaximoClientes() const {
    return numMaximoClientes;
}

// 1. (b)
int ParqueEstacionamento::posicaoCliente(const string &nome) const {
    for(int i=0; i<clientes.size(); i++){ //Certificar que o parque está vazia/sem clientes
        if(clientes[i].nome == nome) //Verifica se o cliente existe
            return i;
        else
            return -1;
    }
}

bool ParqueEstacionamento::adicionaCliente(const string &nome) {
    if(clientes.size() == numMaximoClientes) //Verifica se o parque está cheio
        return false;

    InfoCartao info;
    info.nome = nome;
    clientes.push_back(info);
    return true;
}

//1. (c)
bool ParqueEstacionamento::entrar(const string &nome) {
    if(clientes.size() == numMaximoClientes || posicaoCliente(nome) == -1 || clientes[posicaoCliente(nome)].presente == false)
        return false; //Se o parque estiver lotado, se o nome não estiver registado

    clientes[posicaoCliente(nome)].presente = true; //Entra um cliente
    vagas --; //Diminui o número de vagas
    return true;
}

//1. (d)
bool ParqueEstacionamento::retiraCliente(const string &nome) {
    if(clientes[posicaoCliente(nome)].presente = true && posicaoCliente(nome) == -1){
        clientes.erase(clientes.begin() + posicaoCliente(nome));
        return false;
    }
    return true;
}

//1. (e)
bool ParqueEstacionamento::sair(const string &nome) {

}

//1. (f)
unsigned ParqueEstacionamento::getNumLugaresOcupados() const {
    int ocupados = lotacao - vagas;
    return ocupados;
}

unsigned  ParqueEstacionamento::getNumClientesAtuais() const {
    return clientes.size();
}
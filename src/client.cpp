#include "client.h"

//Construtor:
ccBank::Client::Client(std::string name, std::string cpf) : name(name), cpf(cpf) {}

//Métodos Getters:
std::string ccBank::Client::getName()
{
    return this->name;
}

std::string ccBank::Client::getCpf()
{
    return this->cpf;
}

std::string ccBank::Client::getNameAndCpf()
{
    std::string mergeString = "Nome: " + name + " CPF: " + cpf;
    return mergeString;
}
#include "client.h"

//Construtor:
ccBank::Client::Client(std::string name, std::string cpf) : NAME(name), CPF(cpf) 
{
    if(!ClientVerifyCpf::verifyCPF(CPF))
    {
        std::cout << "|\n| ERRO NO CPF \n|" << std::endl;
        exit(1);
    }
}

//Métodos Getters:
std::string ccBank::Client::getName()
{
    return this->NAME;
}

std::string ccBank::Client::getCpf()
{
    return this->CPF;
}

std::string ccBank::Client::getNameAndCpf()
{
    std::string mergeString = "Nome: " + NAME + " CPF: " + CPF;
    return mergeString;
}

// // // // Class ClientVerifyCPF

bool ccBank::ClientVerifyCpf::verifyCPF(const std::string& CPF)
{
    std::string cpfVerify = CPF;

    int cpfSize = cpfVerify.size();

    if(!ccBank::verifyLetter(cpfVerify))
    {
        return false;
    }
    else if (cpfSize == 11)
    {
        return true;
    }
    else if (cpfSize == 14)
    {
        if ((cpfVerify.at(3) == '.' && cpfVerify.at(7) == '.') && (cpfVerify.at(11) == '.' || cpfVerify.at(11) == '-'))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

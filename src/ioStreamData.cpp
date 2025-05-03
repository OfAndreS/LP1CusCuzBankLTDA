#include "ioStreamData.h"

bool ccBank::writeClientData(const std::string& cpf, const std::string& name) 
{

    std::ofstream arquivoSaida(RESOURCES_PATH "clientDataBase.txt", std::ios::app);

    if (arquivoSaida.is_open()) {
        arquivoSaida << cpf << " | " << name << std::endl; // Escreve no final do arquivo
        arquivoSaida.close();
        return true;
    } else {
        std::cerr << "| Erro ao abrir o arquivo!\n";
        return false;
    }
}

bool ccBank::writeAccountData(const std::string& id, ccBank::Client& client, const std::string& balance) 
{

    std::ofstream arquivoSaida(RESOURCES_PATH "accountDataBase.txt", std::ios::app);

    if (arquivoSaida.is_open()) {
        arquivoSaida << id << " | " << client.getName() << " | " << balance << std::endl; // Escreve no final do arquivo
        arquivoSaida.close();
        return true;
    } else {
        std::cerr << "| Erro ao abrir o arquivo!\n";
        return false;
    }
}
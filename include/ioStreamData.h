#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "client.h"

namespace ccBank
{
    class Client;

    bool writeClientData(const std::string& cpf, const std::string& name);

    bool writeAccountData(const std::string& id, ccBank::Client& client, const std::string& balance);


    void readData(const std::string PATH);

    std::vector<std::string> readCpfData(const std::string PATH, const std::string& cpfProcurado);

    
    bool searchCpf(const std::vector<std::string>& existingCpfs,const std::string& cpf);
    
    int searchIdReturnInt(const std::string& PATH, int idProcurado);
    
    int searchCpfReturnInt(const std::vector<std::string>& existingCpfs, const std::string& cpf);

    
    std::vector<std::string> storeDataInVector(const std::string& PATH, const int typeSearch);
    

    std::vector<std::string> returnAllLinesInVector(const std::string& PATH);
    
    std::vector<std::string> returnCpfLinesInVector(const std::string& PATH, const std::string& cpf);

    void deleteData(int number, const std::string PATH, std::vector<std::string> lines);
}
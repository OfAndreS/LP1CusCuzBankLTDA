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

    bool readData(const std::string PATH);

    void deleteData(std::string number, const std::string PATH);

    bool searchCpf(const std::vector<std::string>& existingCpfs,const std::string& cpf);

    std::vector<std::string> storeDataInVector(const std::string& PATH, const int typeSearch);
}
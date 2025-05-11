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

    bool readClientData();

    void deleteData(std::string number, const std::string PATH);
}
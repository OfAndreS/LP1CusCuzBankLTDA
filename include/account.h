#pragma once

#include <iostream>

#include "utility.h"
#include "client.h"

namespace ccBank
{
    class Client;

    class Account
    {
        private:
        //Variáveis:
        const std::string accountID; 
        ccBank::Client& accountHolder;
        double accountBalance;

        public:
            //Construtor:
            Account(std::string accountID, ccBank::Client& accountHolder);
            Account(std::string accountID, ccBank::Client& accountHolder, double accountBalance);

            //Métodos:
            std::string getInfo();

            std::string getSaldo();
    };
}
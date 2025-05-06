#pragma once

#include <iostream>
#include <iomanip>

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
            void depositar(double money);
            void sacar(double money);

            std::string getInfo();
            std::string getSaldo();
    };
}
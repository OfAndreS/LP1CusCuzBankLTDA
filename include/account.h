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
            const int TYPEFLOW;
            const std::string accountID; 
            ccBank::Client& accountHolder;
            double accountBalance;

        public:
            //Construtor:
            Account(std::string accountID, ccBank::Client& accountHolder, const int TYPEFLOW);
            Account(std::string accountID, ccBank::Client& accountHolder, double accountBalance, const int TYPEFLOW);

            //Métodos:
            void depositar(double money);
            void sacar(double money);

            void transferir(double money, ccBank::Account &destiny);
            void transferir(double money, ccBank::Account &destiny01, ccBank::Account &destiny02);

            std::string getID();
            std::string getInfo();
            std::string getSaldo();
    };
}
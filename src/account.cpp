#include "account.h"

ccBank::Account::Account(std::string accountID, ccBank::Client& accountHolder) 
    : accountID(accountID), accountHolder(accountHolder), accountBalance(0.0) 
    {
        if (!ccBank::writeAccountData(accountID, accountHolder, getSaldo()))
        {
            std::cout << "|\n| ERRO AO SALVAR NO BANCO DE DADOS \n|" << std::endl;
            exit(1);
        }
    }

ccBank::Account::Account(std::string accountID, ccBank::Client& accountHolder, double accountBalance) 
    : accountID(accountID), accountHolder(accountHolder), accountBalance(accountBalance) 
    {
        if (!ccBank::writeAccountData(accountID, accountHolder, getSaldo()))
        {
            std::cout << "|\n| ERRO AO SALVAR NO BANCO DE DADOS \n|" << std::endl;
            exit(1);
        }
    }

std::string ccBank::Account::getSaldo()
{
    return std::to_string(accountBalance);
}

std::string ccBank::Account::getInfo()
{
    printHead();
    return "| ID da Conta: " + accountID + "\n" +
           "| Client: " + accountHolder.getName() + "\n" +
           "| Saldo: " + std::to_string(accountBalance);
}

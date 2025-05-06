#include "account.h"

ccBank::Account::Account(std::string accountID, ccBank::Client& accountHolder) 
    : accountID(accountID), accountHolder(accountHolder), accountBalance(0.0)
    {
        if (accountHolder.getTypeFlow() == 1){
            if (!ccBank::writeAccountData(accountID, accountHolder, getSaldo()))
            {
                std::cout << "|\n| ERRO AO SALVAR NO BANCO DE DADOS \n|" << std::endl;
                exit(1);
            }
        }
    }

ccBank::Account::Account(std::string accountID, ccBank::Client& accountHolder, double accountBalance) 
    : accountID(accountID), accountHolder(accountHolder), accountBalance(accountBalance)
    {
        if (accountHolder.getTypeFlow() == 1){
            if (!ccBank::writeAccountData(accountID, accountHolder, getSaldo()))
            {
                std::cout << "|\n| ERRO AO SALVAR NO BANCO DE DADOS \n|" << std::endl;
                exit(1);
            }
        }
    }

void ccBank::Account::depositar(double money)
{
    if (money > 0)
    {
        this->accountBalance = money;
    }
}

void ccBank::Account::sacar(double money)
{
    if (this->accountBalance > money && money > 0)
    {
        this->accountBalance -= money; 
    }
}

std::string ccBank::Account::getSaldo()
{
    return std::to_string(accountBalance);
}

std::string ccBank::Account::getInfo()
{
    printHead();
    std::stringstream ss;
        ss << "| ID da Conta: " << accountID << "\n"
           << "| Client: " << accountHolder.getName() << "\n"
           << "| Saldo: " << std::fixed << std::setprecision(2) << accountBalance;
    return ss.str();
}

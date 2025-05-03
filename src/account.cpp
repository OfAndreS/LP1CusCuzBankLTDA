#include "account.h"

ccBank::Account::Account(std::string accountID, ccBank::Client& accountHolder) 
    : accountID(accountID), accountHolder(accountHolder), AccountBalance(0.0) 
    {}

ccBank::Account::Account(std::string accountID, ccBank::Client& accountHolder, double AccountBalance) 
    : accountID(accountID), accountHolder(accountHolder), AccountBalance(AccountBalance) 
    {}

std::string ccBank::Account::getInfo()
{
    printHead();
    return "| ID da Conta: " + accountID + "\n" +
           "| Client: " + accountHolder.getName() + "\n" +
           "| Saldo: " + std::to_string(AccountBalance);
}

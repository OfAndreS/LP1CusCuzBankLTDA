#include "account.h"

ccBank::Account::Account(std::string accountID, ccBank::Client& accountHolder) 
    : accountID(accountID), accountHolder(accountHolder), accountBalance(0.0)
    {
        if (accountHolder.getTypeFlow() == 2){
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
        if (accountHolder.getTypeFlow() == 2){
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

void ccBank::Account::transferir(double money, ccBank::Account &destiny)
{
    if (this->accountBalance < money)
    {
        std::cout << "| ERRO: Saldo insuficiente" << std::endl;
    }
    else if (getID() == destiny.getID())
    {
        std::cout << "| ERRO: Não se pode tranferir para a propria conta" << std::endl;
    }
    else
    {
        destiny.depositar(money);
        this->accountBalance -= money;

        printHead();
        
        std::cout << "| Transferido: " << std::to_string(money) << " da conta " << getID() << " para a conta " << destiny.getID() << std::endl; 
    }
}

void ccBank::Account::transferir(double money, ccBank::Account &destiny01, ccBank::Account &destiny02)
{
    if (this->accountBalance < money)
    {
        std::cout << "| ERRO: Saldo insuficiente" << std::endl;
    }
    else if (getID() == destiny01.getID() && getID() == destiny02.getID() && destiny01.getID() == destiny02.getID())
    {
        std::cout << "| ERRO: Não se pode tranferir para a propria conta" << std::endl;
    }
    else
    {
        double splitMoney = money / 2;
        this->accountBalance -= money;
        destiny01.depositar(splitMoney);
        destiny02.depositar(splitMoney);

        printHead();

        std::cout << "| Transferido: " << std::fixed << std::setprecision(2) << splitMoney << " da conta " << getID() << " para cada conta (" << destiny01.getID() << ", " << destiny02.getID() << ") " << std::endl;
    }
}

std::string ccBank::Account::getID()
{
    return this->accountID;
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

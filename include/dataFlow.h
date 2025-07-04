#pragma once

#include <iostream>
#include <limits>
#include <string>

#include "account.h"
#include "client.h"
#include "menu.h"

namespace ccBank
{
    class Client;

    class Account;

    void FirstFlowCreatClient();

    void FirstFlowDeleteClient();
    
    void FirstFlowAccessClient();
    
    void ClientFlowCreatAccount(ccBank::Client& myClient);

    void ClientFlowDeleteAccount(const std::string& cpf);

    void ClientFlowAccessAccount(ccBank::Client& myClient);

    void AccountFlowDepositar(ccBank::Account& myAccount);

    void AccountFlowSacar(ccBank::Account& myAccount);

    void AccountFlowTransferir(ccBank::Account& myAccount);

    void AccountFlowTransferirParaDuasContas(ccBank::Account& myAccount);

    void SecondFlow();

}
#include "menu.h"

void ccBank::startMenu()
    { 
        char choice = 'A';

		printLogo();

        while (choice != '0')
        {
            printHead();
            std::cout << "| MENU PRINCIPAL\n|\n| ( 1 ) Fluxo Normal\n| ( 2 ) Fluxo Predefinido\n| ( 0 ) Encerrar\n| Escolha: ";
            std::cin >> choice;

            switch (choice)
            {
            case '1':
                ccBank::firstFlowMenu();
                break;
            case '2':
				ccBank::SecondFlow();
                break;
            case '0':

                break;
            default:
                printHead();
                std::cout << "| Escolha uma alternativa valida" << std::endl;
                break;
            }
        }
    }

void ccBank::firstFlowMenu()
    { 
        char choice = 'A';

        while (choice != '0')
        {
            printHead();
            std::cout << "| CENTRAL DE ALTERNATIVAS\n|\n| ( 1 ) Acessar Cliente\n|\n| ( 2 ) Criar Cliente\n| ( 3 ) Exibir Clientes\n| ( 4 ) Excluir Cliente\n| ( 0 ) Voltar\n| Escolha: ";
            std::cin >> choice;

            switch (choice)
            {
            case '1':
                ccBank::FirstFlowAccessClient();
                break;
            case '2':
                ccBank::FirstFlowCreatClient();
                break;
            case '3':
				ccBank::readData("clientDataBase.txt");
                break;
            case '4':
                ccBank::FirstFlowDeleteClient();
            case '0':
                break;
            default:
                printHead();
                std::cout << "| Escolha uma alternativa valida" << std::endl;
                break;
            }
        }
        
    }

void ccBank::clientMenu(ccBank::Client& myClient)
{
     
    char choice = 'A';

    while (choice != '0')
    {
        printHead();
        std::cout << "| CENTRAL DO CLIENTE: " << myClient.getName() << "\n|\n| ( 1 ) Acessar Conta\n|\n| ( 2 ) Criar Conta\n| ( 3 ) Exibir Contas\n| ( 4 ) Excluir Conta\n| ( 0 ) Voltar\n| Escolha: ";
        std::cin >> choice;

        switch (choice)
        {
        case '1':
            ccBank::ClientFlowAccessAccount(myClient);
            break;
        case '2':
            ccBank::ClientFlowCreatAccount(myClient);
            break;
        case '3':
            ccBank::readCpfData("accountDataBase.txt", myClient.getCpf());
            break;
        case '4':
            ccBank::ClientFlowDeleteAccount(myClient.getCpf());
            break;
        case '0':
            break;
        default:
            printHead();
            std::cout << "| Escolha uma alternativa valida" << std::endl;
                break;
        }
    }
}

void ccBank::accountMenu(ccBank::Account& myAccount)
{
     
    char choice = 'A';

    while (choice != '0')
    {
        printHead();
        std::cout << "| CENTRAL DA CONTA: " << myAccount.getID() << "\n|\n| ( 1 ) Sacar \n| ( 2 ) Depositar \n| ( 3 ) Transferir \n| ( 4 ) Transferir para duas contas \n| ( 0 ) Voltar\n| Escolha: ";
        std::cin >> choice;

        switch (choice)
        {
        case '1':
            ccBank::AccountFlowSacar(myAccount);
            break;
        case '2':
            ccBank::AccountFlowDepositar(myAccount);
            break;
        case '3':
            ccBank::AccountFlowTransferir(myAccount);
            break;
        case '4':
            ccBank::AccountFlowTransferirParaDuasContas(myAccount);
            break;
        case '0':
            break;
        default:
            printHead();
            std::cout << "| Escolha uma alternativa valida" << std::endl;
                break;
        }
    }
}
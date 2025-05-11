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
            std::cout << "| CENTRAL DE ALTERNATIVAS\n|\n| ( 1 ) Criar Cliente\n| ( 2 ) Exibir Cliente\n| ( 3 ) Excluir Cliente\n| ( 4 ) Acessar Cliente\n| ( 0 ) Voltar\n| Escolha: ";
            std::cin >> choice;

            switch (choice)
            {
            case '1':
                ccBank::FirstFlowCreatClient();
                break;
            case '2':
				ccBank::readData("clientDataBase.txt");
                break;
            case '3':
                ccBank::FirstFlowDeleteClient();
                break;
            case '4':
                ccBank::FirstFlowAccessClient();
            case '0':
                break;
            default:
                printHead();
                std::cout << "| Escolha uma alternativa valida" << std::endl;
                break;
            }
        }
        
    }

void ccBank::clientMenu()
{
     
    char choice = 'A';

    while (choice != '0')
    {
        printHead();
        std::cout << "| CENTRAL DO CLIENTE\n|\n| ( 1 ) Criar Conta\n| ( 2 ) Exibir Conta\n| ( 3 ) Excluir Conta\n| ( 0 ) Voltar\n| Escolha: ";
        std::cin >> choice;

        switch (choice)
        {
        case '1':
            /*Code*/
            break;
        case '2':
			ccBank::readData("accountDataBase.txt");
            break;
        case '3':
            /*Code*/
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
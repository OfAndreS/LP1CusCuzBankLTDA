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
            std::cout << "| CENTRAL DE ALTERNATIVAS\n|\n| ( 1 ) Criar Cliente\n| ( 2 ) Exibir Cliente\n| ( 3 ) Excluir Cliente\n| ( 0 ) Voltar\n| Escolha: ";
            std::cin >> choice;

            switch (choice)
            {
            case '1':
                ccBank::FirstFlowCreatClient();
                break;
            case '2':
				ccBank::readClientData();
                break;
            case '3':
                ccBank::FirstFlowDeleteClient();
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
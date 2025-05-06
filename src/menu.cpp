#include "menu.h"

void ccBank::startMenu()
    { 
        char choice = 'A';

		printLogo();

        while (choice != '0')
        {
            printHead();
            std::cout << "| Central de Opcoes\n| ( 1 ) Fluxo Normal\n| ( 2 ) Fluxo Predefinido\n| ( 0 ) Encerrar\n| Escolha: ";
            std::cin >> choice;

            switch (choice)
            {
            case '1':
                /* code */
                break;
            case '2':
				ccBank::SecondFlow();
                break;
            case '0':

                break;
            default:
                std::cout << "| Escolha uma opção válida" << std::endl;
                break;
            }
        }
        
    }
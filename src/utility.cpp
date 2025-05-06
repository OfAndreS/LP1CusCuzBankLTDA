#include "utility.h"

	void ccBank::printHead()
	{
		std::cout << "\n| *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *\n" << std::endl;
	}

	void ccBank::SecondFlow()
	{
		// Criação dos clientes
		ccBank::Client client01("Ana", "111.111.111-11", 2);
		ccBank::Client client02("Bruno", "222.222.222-22", 2);
		ccBank::Client client03("Carla", "333.333.333-33", 2);

		// Criação das contas bancárias com saldos iniciais
		ccBank::Account conta01_client01("1001", client01, 1000.0);
		ccBank::Account conta02_client02("1002", client02);
		ccBank::Account conta03_client03("1003", client03);

		conta01_client01.depositar(1000);
		conta01_client01.transferir(500, conta02_client02, conta03_client03);

		std::cout << conta01_client01.getInfo() << std::endl;
		std::cout << conta02_client02.getInfo() << std::endl;
		std::cout << conta03_client03.getInfo() << std::endl;
	}

	bool ccBank::verifyLetter(const std::string& word)
	{
		for (char letter : word)
		{
			if (isalpha(letter))
			{
				return false;
			}
		}
		return true;
	}

	void ccBank::printLogo()
	{
		std::cout << " ________  ___  ___  ________  ________  ___  ___  ________         \n";
		std::cout << "|\\   ____\\|\\  \\|\\  \\|\\   ____\\|\\   ____\\|\\  \\|\\  \\|\\_____  \\        \n";
		std::cout << "\\ \\  \\___|\\ \\  \\\\\\  \\ \\  \\___|\\ \\  \\___|\\ \\  \\\\\\  \\\\|___/  /|       \n";
		std::cout << " \\ \\  \\    \\ \\  \\\\\\  \\ \\_____  \\ \\  \\    \\ \\  \\\\\\  \\   /  / /       \n";
		std::cout << "  \\ \\  \\____\\ \\  \\\\\\  \\|____|\\  \\ \\  \\____\\ \\  \\\\\\  \\ /  /_/__      \n";
		std::cout << "   \\ \\_______\\ \\_______\\____\\_\\  \\ \\_______\\ \\_______\\\\________\\    \n";
		std::cout << "    \\|_______|\\|_______|\\_________\\|_______|\\|_______|\\|_______|    \n";
		std::cout << "                       \\|_________|                                 \n";
		std::cout << "                                                                    \n";
		std::cout << " ________  ________  ________   ___  __                             \n";
		std::cout << "|\\   __  \\|\\   __  \\|\\   ___  \\|\\  \\|\\  \\                            \n";
		std::cout << "\\ \\  \\|\\ /\\ \\  \\|\\  \\ \\  \\\\ \\  \\ \\  \\/  /|_                         \n";
		std::cout << " \\ \\   __  \\ \\   __  \\ \\  \\\\ \\  \\ \\   ___  \\                        \n";
		std::cout << "  \\ \\  \\|\\  \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\\\ \\  \\                       \n";
		std::cout << "   \\ \\_______\\ \\__\\ \\__\\ \\__\\\\ \\__\\ \\__\\\\ \\__\\                      \n";
		std::cout << "    \\|_______|\\|__|\\|__|\\|__| \\|__|\\|__| \\|__|                      \n";
		std::cout << "                                                                    \n";
		std::cout << "                                                                    \n";
		std::cout << " ___   _________  ________  ________                                \n";
		std::cout << "|\\  \\ |\\___   ___\\\\   ___ \\|\\   __  \\                               \n";
		std::cout << "\\ \\  \\\\|___ \\  \\_\\ \\  \\_|\\ \\ \\  \\|\\  \\                              \n";
		std::cout << " \\ \\  \\    \\ \\  \\ \\ \\  \\ \\\\ \\ \\   __  \\                             \n";
		std::cout << "  \\ \\  \\____\\ \\  \\ \\ \\  \\_\\\\ \\ \\  \\ \\  \\                            \n";
		std::cout << "   \\ \\_______\\ \\__\\ \\ \\_______\\ \\__\\ \\__\\                           \n";
		std::cout << "    \\|_______|\\|__|  \\|_______|\\|__|\\|__|                           \n";
		std::cout << "                                                                    \n";
		std::cout << "                                                                    \n";
	}
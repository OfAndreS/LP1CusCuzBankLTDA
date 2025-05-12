	#include "dataFlow.h"
    
    void ccBank::FirstFlowAccessClient()
    {
        std::string inputCpf;

        std::cout << "\n|\n| Digite o seu CPF para acessar as contas: ";
        std::cin >> inputCpf;

        std::vector<std::string> existingCpfs = storeDataInVector("clientDataBase.txt", 2);
        if (ccBank::searchCpf(existingCpfs, inputCpf))
        {
            printHead();
            std::vector<std::string> namesInData = ccBank::storeDataInVector("clientDataBase.txt", 3);
            ccBank::Client myClient(namesInData.at(ccBank::searchCpfReturnInt(existingCpfs, inputCpf)), inputCpf, 2);
            std::cout << "| Cliente acessado com sucesso!" << std::endl;
            ccBank::clientMenu(myClient);
        }
        else
        {
            printHead();
            std::cout << "| ERRO: Cliente inexistente!" << std::endl;
        }
    }
    
    void ccBank::FirstFlowCreatClient()
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora o '\n' restante no buffer

        std::string name;
        std::string cpf;

        std::cout << "| Digite seu primeiro Nome: ";
        std::getline(std::cin, name);

        std::cout << "| Digite seu cpf: ";
        std::cin >> cpf;

        ccBank::Client client(name, cpf, 1);
    }

    void ccBank::FirstFlowDeleteClient()
    {
        std::string inputNumber;

        ccBank::readData("clientDataBase.txt");

        std::cout << "\n|\n| Digite o numero para excluir a conta: ";
        std::cin >> inputNumber;

        ccBank::deleteData(inputNumber, "clientDataBase.txt");
    }

    void ccBank::ClientFlowDeleteClient()
    {
        std::string inputNumber;

        ccBank::readCpfData("accountDataBase.txt");

        std::cout << "\n|\n| Digite o numero para excluir a conta: ";
        std::cin >> inputNumber;

        ccBank::deleteData(inputNumber, "accountDataBase.txt");
    }

    void ccBank::ClientFlowCreatAccount(ccBank::Client& myClient)
    {
        ccBank::Account myAccount(std::to_string(ccBank::generateRandomNumber()), myClient);

        ccBank::printHead();
        std::cout << "| Conta com ID: " << myAccount.getID() << " criada com sucesso!" << std::endl;
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
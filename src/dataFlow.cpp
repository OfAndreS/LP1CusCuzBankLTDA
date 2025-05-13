	#include "dataFlow.h"
    
    void ccBank::FirstFlowAccessClient()
    {
        const std::string& PATH = "clientDataBase.txt";
        std::string inputCpf;

        std::cout << "\n|\n| Digite o seu CPF para acessar as contas: ";
        std::cin >> inputCpf;

        std::vector<std::string> existingCpfs = storeDataInVector(PATH, 2);
        if (ccBank::searchCpf(existingCpfs, inputCpf))
        {
            std::vector<std::string> namesInData = ccBank::storeDataInVector(PATH, 3);
            ccBank::Client myClient(namesInData.at(ccBank::searchCpfReturnInt(existingCpfs, inputCpf)), inputCpf, 2);
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
        const std::string& PATH = "clientDataBase.txt";
        std::string inputNumber;

        ccBank::readData(PATH);

        std::cout << "\n|\n| ( 0 ) Voltar | Digite o numero para excluir a conta: ";
        std::cin >> inputNumber;

        if (inputNumber == "0") return;

        ccBank::deleteData(std::stoi(inputNumber), PATH, ccBank::returnAllLinesInVector(PATH));
    }

    void ccBank::ClientFlowDeleteAccount(const std::string& cpf)
    {
        const std::string& PATH = "accountDataBase.txt";
        std::string inputID;

        ccBank::readCpfData(PATH, cpf);

        std::cout << "\n|\n| ( 0 ) Voltar | Digite o ID para excluir a conta: ";
        std::cin >> inputID;

        if (inputID == "0") return;

        ccBank::deleteData(ccBank::searchIdReturnInt(PATH, std::stoi(inputID)), PATH, ccBank::returnAllLinesInVector(PATH));
    }

    void ccBank::ClientFlowCreatAccount(ccBank::Client& myClient)
    {
        ccBank::Account myAccount(std::to_string(ccBank::generateRandomNumber()), myClient, 1);

        ccBank::printHead();
        std::cout << "| Conta com ID: " << myAccount.getID() << " criada com sucesso!" << std::endl;
    }

    void ccBank::ClientFlowAccessAccount(ccBank::Client& myClient)
    {
        const std::string& PATH = "accountDataBase.txt";
        int inputID;

        ccBank::readCpfData(PATH, myClient.getCpf());

        std::cout << "\n|\n| ( 0 ) Voltar | Digite o ID da conta: ";
        std::cin >> inputID;

        if (inputID == 0) return;

        int idNumber = ccBank::searchIdReturnInt(PATH, inputID);

        if (idNumber != -1)
        {
            std::vector<std::string> idInData = ccBank::storeDataInVector(PATH, 4);
            ccBank::Account myAccount(idInData.at(idNumber), myClient, 2);
            ccBank::accountMenu(myAccount);
        }
        else
        {
            printHead();
            std::cout << "| ERRO: Cliente inexistente!" << std::endl;
        }
    }

    void ccBank::SecondFlow()
	{
		// Criação dos clientes
		ccBank::Client client01("Ana", "111.111.111-11", 2);
		ccBank::Client client02("Bruno", "222.222.222-22", 2);
		ccBank::Client client03("Carla", "333.333.333-33", 2);

		// Criação das contas bancárias com saldos iniciais
		ccBank::Account conta01_client01("1001", client01, 1000.0, 2);
		ccBank::Account conta02_client02("1002", client02, 2);
		ccBank::Account conta03_client03("1003", client03, 2);

		conta01_client01.depositar(1000);
		conta01_client01.transferir(500, conta02_client02, conta03_client03);

		std::cout << conta01_client01.getInfo() << std::endl;
		std::cout << conta02_client02.getInfo() << std::endl;
		std::cout << conta03_client03.getInfo() << std::endl;
	}
	#include "dataFlow.h"
    
    void ccBank::FirstFlowAccessClient()
    {
        const std::string& PATH = "clientDataBase.txt";
        std::string inputCpf;

        std::cout << "\n|\n| Digite o seu CPF para acessar o cliente: ";
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
        const std::string& CLIENTPATH = "clientDataBase.txt";
        const std::string& ACCOUNTPATH = "accountDataBase.txt";

        std::vector <std::string> cpfData = ccBank::storeDataInVector(CLIENTPATH, 2);
        std::string inputCpf;
        int inputNumber;
        
        ccBank::readData(CLIENTPATH);
        
        std::cout << "\n|\n| ( 0 ) Voltar | Digite o CPF para excluir o cliente: ";
        std::cin >> inputCpf;   
        
        inputNumber = ccBank::searchCpfReturnInt(cpfData, inputCpf) + 1;
        
        if (inputCpf == "0")
        {
            return;
        }
        else if (inputNumber == 0)
        {
            ccBank::printHead();
            std::cout << "\n| Nenhum cliente encontrado com o CPF: " << inputCpf << std::endl;
            return;
        }
        else
        {
            ccBank::deleteData(inputNumber, CLIENTPATH, ccBank::returnAllLinesInVector(CLIENTPATH));
        }

    }

    void ccBank::ClientFlowDeleteAccount(const std::string& cpf)
    {
        const std::string& PATH = "accountDataBase.txt";
        std::string inputID;

        if(ccBank::readCpfData(PATH, cpf).empty()) 
        {
            std::cout << "| Nenhuma conta foi criada para esse CPF" << std::endl; 
            return;
        }

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

        std::vector<std::string> data = ccBank::readCpfData(PATH, myClient.getCpf());

        if(data.empty())
        {
            std::cout << "| Nenhuma conta foi criada para esse CPF" << std::endl; 
            return;
        }

        std::cout << "\n|\n| ( 0 ) Voltar | Digite o ID da conta: ";
        std::cin >> inputID;

        if (inputID == 0) return;

        int idNumber = ccBank::searchIdReturnInt(PATH, inputID) - 1;

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

    void ccBank::AccountFlowDepositar(ccBank::Account& myAccount)
    {
        const std::string& PATH = "accountDataBase.txt";
        double money;

        ccBank::printHead();
        std::cout << "| Digite a quantidade para Depositar: ";
        std::cin >> money;

        ccBank::updateAccountBalance(ccBank::searchIdReturnInt(PATH, std::stoi(myAccount.getID())), PATH, ccBank::returnAllLinesInVector(PATH), money, 1);
    }

    void ccBank::AccountFlowSacar(ccBank::Account& myAccount)
    {
        const std::string& PATH = "accountDataBase.txt";
        double money;

        ccBank::printHead();
        std::cout << "| Digite a quantidade para Sacar: ";
        std::cin >> money;

        int myMoney = ccBank::updateAccountBalance(ccBank::searchIdReturnInt(PATH, std::stoi(myAccount.getID())), PATH, ccBank::returnAllLinesInVector(PATH), money, 2);
        
        if (myMoney == -1)
        {
            std::cout << "| Dinheiro insuficiente!!!" << std::endl;
            return;
        }

    }

    void ccBank::AccountFlowTransferir(ccBank::Account& myAccount)
    {
        const std::string& PATH = "accountDataBase.txt";

        int firstAccountID;
        double money;

        std::vector<std::string> data = ccBank::readCpfData(PATH, myAccount.getCpf());

        if(data.empty())
        {
            std::cout << "| Nenhuma conta foi criada para esse CPF" << std::endl; 
            return;
        }

        ccBank::printHead();
        std::cout << "| Digite a quantidade para Transferir: ";
        std::cin >> money;
        std::cout << "| Digite O ID da primeira conta: ";
        std::cin >> firstAccountID;

        int myMoney = ccBank::updateAccountBalance(ccBank::searchIdReturnInt(PATH, std::stoi(myAccount.getID())), PATH, ccBank::returnAllLinesInVector(PATH), money, 2);
        
        if (myMoney == -1)
        {
            std::cout << "| Dinheiro insuficiente!!!" << std::endl;
            return;
        }
        else
        {
            ccBank::updateAccountBalance(ccBank::searchIdReturnInt(PATH, firstAccountID), PATH, ccBank::returnAllLinesInVector(PATH), money, 1);
        }
    }

    void ccBank::AccountFlowTransferirParaDuasContas(ccBank::Account& myAccount)
    {
        const std::string& PATH = "accountDataBase.txt";

        int firstAccountID;
        int seccondAccountID;
        double money;
        double halfMoney;

        std::vector<std::string> data = ccBank::readCpfData(PATH, myAccount.getCpf());

        if(data.empty())
        {
            std::cout << "| Nenhuma conta foi criada para esse CPF" << std::endl; 
            return;
        }

        ccBank::printHead();
        std::cout << "| Digite a quantidade para Transferir: ";
        std::cin >> money;
        std::cout << "| Digite O ID da primeira conta: ";
        std::cin >> firstAccountID;
        std::cout << "| Digite O ID da segunda conta: ";
        std::cin >> seccondAccountID;

        halfMoney = money / 2;

        int myMoney = ccBank::updateAccountBalance(ccBank::searchIdReturnInt(PATH, std::stoi(myAccount.getID())), PATH, ccBank::returnAllLinesInVector(PATH), money, 2);
        
        if (myMoney == -1)
        {
            std::cout << "| Dinheiro insuficiente!!!" << std::endl;
            return;
        }
        else
        {
        ccBank::updateAccountBalance(ccBank::searchIdReturnInt(PATH, firstAccountID), PATH, ccBank::returnAllLinesInVector(PATH), halfMoney, 1);
        ccBank::updateAccountBalance(ccBank::searchIdReturnInt(PATH, seccondAccountID), PATH, ccBank::returnAllLinesInVector(PATH), halfMoney, 1);
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
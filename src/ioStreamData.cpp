#include "ioStreamData.h"

std::vector<std::string> ccBank::storeDataInVector(const std::string& PATH, const int typeSearch)
{
    std::vector<std::string> lines;
    std::string line;

    std::ifstream arquivoEntrada(std::string(RESOURCES_PATH) + PATH);
    if (!arquivoEntrada.is_open()) {
        std::cerr << "| Erro ao abrir arquivo: " << PATH << "\n";
        return lines;
    }

    switch (typeSearch)
    {
    case 1: // Leitura linha por linha (para conteúdo completo)
        while (std::getline(arquivoEntrada, line)) {
            if (!line.empty()) {
                lines.push_back(line);
            }
        }
        break;
    case 2: // Leitura por campos separados por '|' (para CPFs)
        while (std::getline(arquivoEntrada, line)) {
            if (!line.empty()) {
                size_t pos = line.find(" | ");
                if (pos != std::string::npos) {
                    lines.push_back(line.substr(0, pos)); // Extrai apenas o CPF
                }
            }
        }
        break;
    default:
        std::cerr << "| Tipo de busca inválido!\n";
        break;
    }

    arquivoEntrada.close();
    return lines;
}

bool ccBank::writeClientData(const std::string& cpf, const std::string& name) 
{
    // Primeiro verifica se o CPF já existe
    std::vector<std::string> existingCpfs = storeDataInVector("clientDataBase.txt", 2);
    
    for (const auto& existingCpf : existingCpfs) {
        if (existingCpf == cpf) {
            printHead();
            std::cout << "| ERRO: CPF " << cpf << " já cadastrado no sistema!\n";
            return false;
        }
    }

    // Se o CPF não existe, procede com o cadastro
    std::ofstream arquivoSaida(std::string(RESOURCES_PATH) + "clientDataBase.txt", std::ios::app);
    if (!arquivoSaida.is_open()) {
        std::cerr << "| Erro ao abrir arquivo para escrita!\n";
        return false;
    }

    // Formata a saída consistentemente
    arquivoSaida << cpf << " | " << name << "\n";
    arquivoSaida.close();

    printHead();
    std::cout << "| Cliente " << name << " cadastrado com sucesso!\n";
    return true;
}

bool ccBank::writeAccountData(const std::string& id, ccBank::Client& client, const std::string& balance) 
{

    std::ofstream arquivoSaida(RESOURCES_PATH "accountDataBase.txt", std::ios::app);

    if (arquivoSaida.is_open()) {
        arquivoSaida << id << " | " << client.getName() << " | " << balance << std::endl; // Escreve no final do arquivo
        arquivoSaida.close();
        return true;
    } else {
        std::cerr << "| Erro ao abrir o arquivo!\n";
        return false;
    }
}

bool ccBank::readClientData()
{
    std::ifstream arquivoEntrada(RESOURCES_PATH "clientDataBase.txt");
    if (arquivoEntrada.is_open()) {
        int numberOfTheLine = 1;
        std::string linha;

        printHead();
        std::cout << "| CLIENTES:\n| " << std::endl;

        while (std::getline(arquivoEntrada, linha)) { 
            
            std::cout << "| " << "( " << numberOfTheLine << " ) | " << linha << '\n';
            numberOfTheLine++;
        }
        arquivoEntrada.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo para leitura!\n";
    }
}

void ccBank::deleteData(std::string number, const std::string PATH)
{
    // Converte o número da linha para inteiro
    int targetLine;
    try {
        targetLine = std::stoi(number);
    } catch (...) {
        std::cerr << "| Número de linha inválido!\n";
        return;
    }

    std::vector<std::string> lines = ccBank::storeDataInVector(PATH, 1);

    if (lines.empty())
    {
        printHead();
        std::cout << "| Nenhuma conta foi criada" << std::endl;
        return;
    }
        

    // Verifica se a linha existe
    if (targetLine < 1 || targetLine > lines.size()) {
        std::cerr << "| Linha " << targetLine << " não existe!\n";
        return;
    }

    // Remove a linha do vetor
    lines.erase(lines.begin() + targetLine - 1);

    // Reescreve o arquivo
    std::ofstream arquivoSaida(std::string(RESOURCES_PATH) + PATH);
    if (!arquivoSaida.is_open()) {
        std::cerr << "| Erro ao abrir arquivo para escrita!\n";
        return;
    }

    for (const auto& l : lines) {
        arquivoSaida << l << '\n';
    }

    printHead();
    std::cout << "| Cliente " << name << " deletado com sucesso!\n";

    arquivoSaida.close();

    return;
}
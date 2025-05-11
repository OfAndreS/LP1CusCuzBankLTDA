#include "ioStreamData.h"

bool ccBank::writeClientData(const std::string& cpf, const std::string& name) 
{

    std::ofstream arquivoSaida(RESOURCES_PATH "clientDataBase.txt", std::ios::app);

    if (arquivoSaida.is_open()) {
        arquivoSaida << cpf << " | " << name << std::endl; // Escreve no final do arquivo
        arquivoSaida.close();
        return true;
    } else {
        std::cerr << "| Erro ao abrir o arquivo!\n";
        return false;
    }
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

        while (std::getline(arquivoEntrada, linha)) { // Lê linha por linha
            if (linha != "Off")
            {
                std::cout << "| " << "( " << numberOfTheLine << " ) | " << linha << '\n'; // Exibe no console
            }
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

    // Abre arquivo para leitura
    std::ifstream arquivoEntrada(std::string(RESOURCES_PATH) + PATH);
    if (!arquivoEntrada.is_open()) {
        std::cerr << "| Erro ao abrir arquivo!\n";
        return;
    }

    // Lê todas as linhas
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(arquivoEntrada, line)) {
        lines.push_back(line);
    }
    arquivoEntrada.close();

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
    arquivoSaida.close();

    return;
}
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
    case 3: // Leitura por campos separados por '|' (para Nomes)
        while (std::getline(arquivoEntrada, line)) {
            if (!line.empty()) {
                size_t pos = line.find(" | ");
                if (pos != std::string::npos) {
                    // Extrai apenas o Nome (tudo após " | ")
                    lines.push_back(line.substr(pos + 3)); // +3 para pular o " | "
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

bool ccBank::searchCpf(const std::vector<std::string>& existingCpfs,const std::string& cpf) /// Proucura o CPF no vetor
{
    for (const auto& existingCpf : existingCpfs) {
        if (existingCpf == cpf) {
            return true;
        }
    }
}

int ccBank::searchCpfReturnInt(const std::vector<std::string>& existingCpfs, const std::string& cpf)
{
    for (size_t i = 0; i < existingCpfs.size(); ++i) {
        if (existingCpfs[i] == cpf) {
            return static_cast<int>(i); // Retorna o índice onde o CPF foi encontrado
        }
    }
    return -1; // Retorna -1 se o CPF não foi encontrado
}

bool ccBank::readData(const std::string PATH)
{
    std::ifstream arquivoEntrada(std::string(RESOURCES_PATH) + PATH);
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

bool ccBank::readCpfData(const std::string PATH, const std::string& cpfProcurado) {
    std::ifstream arquivoEntrada(std::string(RESOURCES_PATH) + PATH);
    if (!arquivoEntrada.is_open()) {
        std::cerr << "Erro ao abrir o arquivo para leitura!\n";
        return false;
    }

    bool encontrou = false;
    std::string linha;

    printHead();
    std::cout << "| BUSCA POR CPF: " << cpfProcurado << "\n| " << std::endl;

    while (std::getline(arquivoEntrada, linha)) {
        // Extrai o CPF da linha (formato: "CPF | Nome")
        size_t pos = linha.find(" | ");
        if (pos != std::string::npos) {
            std::string cpfNaLinha = linha.substr(0, pos);
            
            // Se o CPF for igual ao procurado, imprime a linha
            if (cpfNaLinha == cpfProcurado) {
                std::cout << "| " << linha << '\n';
                encontrou = true;
            }
        }
    }

    if (!encontrou) {
        std::cout << "| CPF não encontrado.\n";
    }

    arquivoEntrada.close();
    return encontrou;
}

bool ccBank::writeClientData(const std::string& cpf, const std::string& name) 
{
    // Primeiro verifica se o CPF já existe
    std::vector<std::string> existingCpfs = storeDataInVector("clientDataBase.txt", 2);
    
    if (ccBank::searchCpf(existingCpfs, cpf)) 
    {
        printHead();
        std::cout << "| ERRO: CPF " << cpf << " já cadastrado no sistema!\n";
        return false;
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
        arquivoSaida << client.getCpf() << " | " << id << " / " << balance << std::endl; // Escreve no final do arquivo
        arquivoSaida.close();
        return true;
    } else {
        std::cerr << "| Erro ao abrir o arquivo!\n";
        return false;
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
    std::cout << "| Cliente deletado com sucesso!\n";

    arquivoSaida.close();

    return;
}
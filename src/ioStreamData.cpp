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
    case 4: // Extrair apenas o ID (entre CPF e " / DinheiroNaConta")
        while (std::getline(arquivoEntrada, line)) {
            if (!line.empty()) {
                size_t posPipe = line.find('|');  // Encontra a posição do '|' (separador CPF/ID)
                size_t posSlash = line.find(" / "); // Encontra a posição do " / " (separador ID/Saldo)
                
                if (posPipe != std::string::npos && posSlash != std::string::npos && posPipe < posSlash) {
                    // Extrai o ID (entre '|' e " / ")
                    std::string id = line.substr(posPipe + 1, posSlash - posPipe - 1);
                    // Remove espaços em branco extras
                    id.erase(0, id.find_first_not_of(" \t"));
                    id.erase(id.find_last_not_of(" \t") + 1);
                    lines.push_back(id);
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


// Métodos para BUSCA no arquivo


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

int ccBank::searchIdReturnInt(const std::string& PATH, int idProcurado) {
    std::ifstream arquivoEntrada(std::string(RESOURCES_PATH) + PATH);
    
    if (!arquivoEntrada.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << PATH << "\n";
        return -1; // Retorna -1 se não abrir o arquivo
    }

    std::string linha;
    int numeroLinha = 0;
    bool encontrado = false;

    while (std::getline(arquivoEntrada, linha)) {
        numeroLinha++; // Incrementa o contador de linhas (começa em 1)
        
        // Extrai o ID da linha (formato: "CPF | ID / SALDO")
        size_t posPipe = linha.find(" | ");
        size_t posBarra = linha.find(" / ");
        
        if (posPipe != std::string::npos && posBarra != std::string::npos) {
            try {
                int idAtual = std::stoi(linha.substr(posPipe + 3, posBarra - posPipe - 3));
                
                if (idAtual == idProcurado) {
                    encontrado = true;
                    break; // Encontrou, pode sair do loop
                }
            } catch (...) {
                // Ignora linhas com formato inválido
                continue;
            }
        }
    }

    arquivoEntrada.close();

    if (!encontrado) {
        std::cout << "| ID " << idProcurado << " inexistente!\n";
        return -1;
    }

    return numeroLinha; // Retorna a posição da linha (1-based)
}


// Métodos para LEITURA no arquivo 


void ccBank::readData(const std::string PATH)
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

std::vector<std::string> ccBank::readCpfData(const std::string PATH, const std::string& cpfProcurado) {
    std::vector<std::string> cpfsEncontrados;
    std::ifstream arquivoEntrada(std::string(RESOURCES_PATH) + PATH);
    
    if (!arquivoEntrada.is_open()) {
        std::cerr << "Erro ao abrir o arquivo para leitura!\n";
        return cpfsEncontrados; // Retorna vetor vazio em caso de erro
    }

    int numberOfTheLine = 1;
    bool encontrou = false;
    std::string linha;

    printHead();
    std::cout << "| BUSCA POR TODAS AS CONTAS NO CPF: " << cpfProcurado << "\n| " << std::endl;
    std::cout << "| (   ) | CPF            | ID    / SALDO "<< std::endl;

    while (std::getline(arquivoEntrada, linha)) {
        size_t pos = linha.find(" | ");
        if (pos != std::string::npos) {
            std::string cpfNaLinha = linha.substr(0, pos);
            
            if (cpfNaLinha == cpfProcurado) {
                std::cout << "| " << "( " << numberOfTheLine << " ) | " << linha << '\n';
                cpfsEncontrados.push_back(cpfNaLinha); // Adiciona CPF ao vetor
                numberOfTheLine++;
                encontrou = true;
            }
        }
    }

    if (!encontrou) {
        return cpfsEncontrados = {};
    }

    arquivoEntrada.close();
    return cpfsEncontrados;
}


// Métodos para ESCREVER no arquivos 


bool ccBank::writeClientData(const std::string& cpf, const std::string& name) 
{
    // Verifica se o CPF já existe
    std::vector<std::string> existingCpfs = storeDataInVector("clientDataBase.txt", 2);
    if (ccBank::searchCpf(existingCpfs, cpf)) 
    {
        printHead();
        std::cout << "| ERRO: CPF " << cpf << " já cadastrado no sistema!\n";
        return false;
    }

    // Define o caminho completo do arquivo
    std::string filePath = std::string(RESOURCES_PATH) + "clientDataBase.txt";

    // Verifica se o arquivo está vazio
    std::ifstream checkFile(filePath);
    bool isEmpty = checkFile.peek() == std::ifstream::traits_type::eof();
    checkFile.close();

    // Abre o arquivo no modo apropriado (append ou trunc)
    std::ofstream arquivoSaida;
    if (isEmpty) {
        arquivoSaida.open(filePath, std::ios::trunc); // Sobrescreve se vazio
    } else {
        arquivoSaida.open(filePath, std::ios::app); // Append se não vazio
    }

    if (!arquivoSaida.is_open()) {
        std::cerr << "| Erro ao abrir arquivo para escrita!\n";
        return false;
    }

    // Escreve os dados formatados
    arquivoSaida << cpf << " | " << name << "\n";
    arquivoSaida.close();

    printHead();
    std::cout << "| Cliente " << name << " cadastrado com sucesso!\n";
    return true;
}

bool ccBank::writeAccountData(const std::string& id, ccBank::Client& client, const std::string& balance) 
{
    std::string filePath = RESOURCES_PATH "accountDataBase.txt";
    
    // Check if the file is empty
    std::ifstream checkFile(filePath);
    bool isEmpty = checkFile.peek() == std::ifstream::traits_type::eof();
    checkFile.close();

    // Open in append mode if not empty, truncate (overwrite) if empty
    std::ofstream arquivoSaida;
    if (isEmpty) {
        arquivoSaida.open(filePath, std::ios::trunc); // Overwrites if empty
    } else {
        arquivoSaida.open(filePath, std::ios::app); // Appends if not empty
    }

    if (arquivoSaida.is_open()) {
        arquivoSaida << client.getCpf() << " | " << id << " / " << balance << std::endl;
        arquivoSaida.close();
        return true;
    } else {
        std::cerr << "| Erro ao abrir o arquivo!\n";
        return false;
    }
}


// Métodos para ATUALIZAR o arquivo


int ccBank::updateAccountBalance(int number, const std::string PATH, std::vector<std::string> lines, double valueToAdd, const int TYPE) 
{
    int targetLine = number;

    if (targetLine == -1) return -2;

    if (lines.empty()) {
        printHead();
        std::cout << "| Nenhuma conta foi criada" << std::endl;
        return -2;
    }
        
    if (targetLine < 1 || targetLine > lines.size()) {
        std::cerr << "| Linha " << targetLine << " inexistente!\n";
        return -2;
    }

    std::string& lineToUpdate = lines[targetLine - 1];
    
    size_t balancePos = lineToUpdate.find_last_of('/');
    if (balancePos == std::string::npos) {
        std::cerr << "| Formato de linha inválido (não encontrado '/')!\n";
        return -2;
    }

    std::string balanceStr = lineToUpdate.substr(balancePos + 1);
    double currentBalance;
    try {
        currentBalance = std::stod(balanceStr);
    } catch (...) {
        std::cerr << "| Erro ao ler saldo atual!\n";
        return -2;
    }

    double newBalance = currentBalance; // Declare newBalance outside the switch

    switch (TYPE)
    {
    case 1:
        newBalance = currentBalance + valueToAdd;
        break;
    case 2:
        newBalance = currentBalance - valueToAdd;
        if (newBalance < 0) return -1;
        break;
    default:
        break;
    }

    lineToUpdate = lineToUpdate.substr(0, balancePos + 1) + " " + std::to_string(newBalance);

    size_t dotPos = lineToUpdate.find('.');
    if (dotPos != std::string::npos) {
        lineToUpdate.erase(lineToUpdate.find_last_not_of('0') + 1, std::string::npos);
        if (lineToUpdate.back() == '.') {
            lineToUpdate.push_back('0'); 
        }
    }

    std::ofstream arquivoSaida(std::string(RESOURCES_PATH) + PATH);
    if (!arquivoSaida.is_open()) {
        std::cerr << "| Erro ao abrir arquivo para escrita!\n";
        return -2;
    }

    for (const auto& l : lines) {
        arquivoSaida << l << '\n';
    }

    printHead();
    std::cout << "| Saldo atualizado De: " << currentBalance << " Para: " << newBalance << "\n";

    arquivoSaida.close();

    return newBalance;
}


// Métodos para DELETAR no arquivos 


std::vector<std::string> ccBank::returnAllLinesInVector(const std::string& PATH)
{
    std::vector<std::string> lines = ccBank::storeDataInVector(PATH, 1);
    return lines;
}

std::vector<std::string> ccBank::returnCpfLinesInVector(const std::string& PATH, const std::string& cpf)
{
    std::vector<std::string> lines = ccBank::readCpfData(PATH, cpf);
    return lines;
}

void ccBank::deleteData(int number, const std::string PATH, std::vector<std::string> lines)
{
    int targetLine = number;

    if (targetLine == -1) return;

    if (lines.empty())
    {
        printHead();
        std::cout << "| Nenhuma conta foi criada" << std::endl;
        return;
    }
        
    if (targetLine < 1 || targetLine > lines.size()) // Verifica se a linha existe
    {
        std::cerr << "| Linha " << targetLine << " inexistente!\n";
        return;
    }

    lines.erase(lines.begin() + targetLine - 1); // Remove a linha do vetor

    std::ofstream arquivoSaida(std::string(RESOURCES_PATH) + PATH); // Reescreve o arquivo
    if (!arquivoSaida.is_open()) {
        std::cerr << "| Erro ao abrir arquivo para escrita!\n";
        return;
    }

    for (const auto& l : lines) {
        arquivoSaida << l << '\n';
    }

    printHead();
    std::cout << "| Deletado com sucesso!\n";

    arquivoSaida.close();

    return;
}
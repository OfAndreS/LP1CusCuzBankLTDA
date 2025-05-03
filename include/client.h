#pragma once

#include <iostream>
#include <string>

#include "ioStreamData.h"
#include "utility.h"


namespace ccBank 
{

    class Client 
    {
        private:
            //Variáveis:
            const std::string CPF; 
            const std::string NAME;

        public:
            //Construtor:
            Client(std::string NAME, std::string CPF);

            //Métodos:
            std::string getName();
            std::string getCpf();
            std::string getNameAndCpf();
    };

    class ClientVerifyCpf
    {
        public:
            static bool verifyCPF(const std::string& CPF);
    };

}
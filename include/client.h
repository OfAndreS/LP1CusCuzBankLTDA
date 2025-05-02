#pragma once

#include <iostream>
#include <string>

namespace ccBank 
{

    class Client 
    {
        private:
            //Variáveis:
            std::string cpf; 
            std::string name;

        public:
            //Construtor:
            Client(std::string name, std::string cpf);

            //Métodos:
            std::string getName();
            std::string getCpf();
            std::string getNameAndCpf();
    };

}
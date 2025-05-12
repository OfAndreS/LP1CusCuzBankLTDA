#pragma once

#include <iostream>
#include <random>
#include <cstdlib>  
#include <ctime>   
#include <string>

#include "account.h"
#include "client.h"

namespace ccBank
{
    void printLogo();

    void printHead();

    int generateRandomNumber();

    bool verifyLetter(const std::string& word);
}
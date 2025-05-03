#pragma once

#include <iostream>
#include <string>

#include "account.h"
#include "client.h"

namespace ccBank
{
    void SecondFlow();

    void printLogo();

    void printHead();

    bool verifyLetter(const std::string& word);
}
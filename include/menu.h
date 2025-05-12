#pragma once

#include <iostream>
#include <string>

#include "client.h"
#include "dataFlow.h"

namespace ccBank
{
    class Client;

    void startMenu();

    void firstFlowMenu();

    void clientMenu(ccBank::Client& myClient);
}
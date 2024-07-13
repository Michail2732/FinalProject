#include <iostream>
#include <string>
#include "Chat.h"
#include "ChatConsoleHandler.h"

using namespace std;

int main()
{
    FinalProject::Chat* chat = new FinalProject::Chat();
    FinalProject::ChatConsoleHandler* chatHandler = new FinalProject::ChatConsoleHandler(chat);
    chatHandler->Start();
    return 0;
}


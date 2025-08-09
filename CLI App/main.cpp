#include <fstream>
#include <iostream>
#include "FileHandler.h"
#include <string>

#include "PasswordManager.h"

void needSetUp() {
    FileHandler fHandler;
    std::ifstream fileOpen("Data/Password_List.txt");
    bool fileExists = fileOpen.is_open();
    if (!fileExists) {
        try {
            fHandler.createFile("Password_List");

        }catch (const std::runtime_error& e) {
            std::cout << e.what() << std::endl;
        }
    }
    else {
        fileOpen.close();
    }
}

int main() {
    PasswordManager manager;
    needSetUp();
    std::cout << "Welcome to the Password Manager" << std::endl;
    manager.menu();
}
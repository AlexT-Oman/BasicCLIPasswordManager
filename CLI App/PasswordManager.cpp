//
// Created by alex on 7/22/25.
//

#include "PasswordManager.h"

#include <iostream>

#include "FileHandler.h"

PasswordManager::PasswordManager() {

}


void PasswordManager::menu() {
    int navChoice = 0;
    FileHandler fHandler;
    while (navChoice != 4) {
        std::cout << "Enter 1 to add a new password" << std::endl;
        std::cout << "Enter 2 to delete a new password" << std::endl;
        std::cout << "Enter 3 to get a password" << std::endl;
        std::cout << "Enter 4 to exit" << std::endl;
        std::cin >> navChoice;
        switch (navChoice) {
            case 1: {//TODO: Fix output format
                std::string serviceName;
                std::string serviceUsername;
                std::string servicePassword;
                std::cout << "What is the service name?" << std::endl;
                std::cin >> serviceName;
                std::cout << "What is the service username?" << std::endl;
                std::cin >> serviceUsername;
                std::cout << "What is the service password?" << std::endl;
                std::cin >> servicePassword;
                try{
                    fHandler.addPassword(serviceName, serviceUsername, servicePassword, "Password_List");
                }
                catch (const std::runtime_error& e) {
                    std::cout << e.what() << std::endl;
                }
                std::cout << "\n\n";
                break;
            }
            case 2: {
                //remove a password
                std::string serviceName;
                std::cin >> serviceName;
                fHandler.removePassword(serviceName, "Password_List");
                std::cout << "\n\n";
                break;
            }
            case 3: {
                //get password
                std::string serviceName;
                std::cin >> serviceName;
                fHandler.getPassword(serviceName, "Password_List");
                std::cout << "\n\n";
                break;
            }
                case 4: {
                std::cout << "Program exiting";

                break;
            }
            default: {
                std::cout << "\n\n";
                std::cout << "Incorrect input, please enter a valid option" << std::endl;
                std::cout << "Enter 1 to add a new password" << std::endl;
                std::cout << "Enter 2 to delete a new password" << std::endl;
                std::cout << "Enter 3 to get a password" << std::endl;
                std::cout << "Enter 4 to exit" << std::endl;
            }
        }
    }
}

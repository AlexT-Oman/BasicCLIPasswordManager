//
// Created by alex on 7/22/25.
//

#include "FileHandler.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>


void FileHandler::createFile(std::string fileName) {
    std::ofstream newFile("Data/" + fileName + ".txt");
    if (newFile.is_open()) {
        newFile.close();
    }
    else {
        throw std::runtime_error("File could not be opened");
    }

}

void FileHandler::addPassword(std::string serviceName, std::string serviceUsername, std::string servicePassword, std::string fileName) {
//TODO: Add a check to make sure the same info is not added
    std::ofstream passwordFileWrite("Data/" + fileName + ".txt", std::ios::app);
    if (passwordFileWrite.is_open()) {
       passwordFileWrite << serviceName + "," + serviceUsername + "," + servicePassword << std::endl;
       passwordFileWrite.close();
    }
    else {
        throw std::runtime_error("File failed to open and be written to");
    }
    std::ifstream passwordFileOpen("Data/" + fileName + ".txt");
    if (passwordFileOpen.is_open()) {
        std::string line;
        std::string lastLine;
        while (getline(passwordFileOpen, line)) {
            lastLine = line;
        }
        std::cout << lastLine << std::endl;
        passwordFileOpen.close();
    }
    else {
        throw std::runtime_error("File failed to open and be read from");
    }
}

void FileHandler::removePassword(std::string serviceName, std::string fileName) {
    std::fstream passwordFileWrite("Data/" + fileName + ".txt", std::ios::in | std::ios::out);

    if (passwordFileWrite.is_open()) {
        std::string serviceBuffer;
        std::vector<std::string> wholePasswordList;
        while (std::getline(passwordFileWrite, serviceBuffer)) {
            std::string bufferServiceName;
            int i = 0;
            while (serviceBuffer[i] != ',') {
                bufferServiceName += serviceBuffer[i];
                i += 1;
            }
            if (bufferServiceName != serviceName) {
                wholePasswordList.push_back(serviceBuffer);
            }
        }
        passwordFileWrite.close();
        rewriteFile(wholePasswordList, fileName);
        wholePasswordList.clear();
    }
    else {
        throw std::runtime_error("File failed to open and be used");
    }
}

void FileHandler::rewriteFile(std::vector<std::string>& passwords, std::string fileName){
    std::ofstream rewrittenFile("Data/" + fileName + ".txt");
    if(rewrittenFile.is_open()){
        for(auto it = passwords.begin(); it != passwords.end(); ++it){
            rewrittenFile << *it << std::endl;
        }
        rewrittenFile.close();

    }
    else {
        throw std::runtime_error("File failed to open and be written to");
    }
}

void FileHandler::getPassword(std::string serviceName, std::string fileName){
    std::fstream passwordFileWrite("Data/" + fileName + ".txt", std::ios::in);
    if (passwordFileWrite.is_open()) {
        std::string serviceBuffer;
        while (std::getline(passwordFileWrite, serviceBuffer)) {
            std::string bufferServiceName;
            int i = 0;
            while (serviceBuffer[i] != ',') {
                bufferServiceName += serviceBuffer[i];
                i += 1;
            }
            if (bufferServiceName == serviceName) {
                std::cout << serviceBuffer << std::endl;
            }
        }
    }
    else {
        throw std::runtime_error("File failed to open and be used");
    }
}


FileHandler::FileHandler() {

}

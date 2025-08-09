//
// Created by alex on 7/22/25.
//

#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include <vector>


class FileHandler {
    public:
    FileHandler();
    void createFile(std::string fileName);
    void addPassword(std::string serviceName, std::string serviceUsername, std::string servicePassword, std::string fileName);
    void removePassword(std::string serviceName, std::string fileName);
    void getPassword(std::string serviceName, std::string fileName);

    private:
    void rewriteFile(std::vector<std::string>& passwords, std::string fileName);

};



#endif //FILEHANDLER_H

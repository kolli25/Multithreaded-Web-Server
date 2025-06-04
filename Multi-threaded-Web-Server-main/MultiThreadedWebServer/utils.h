#ifndef UTILS_H
#define UTILS_H

#include <string>

std::string parseRequest(const std::string& request);
void sendErrorResponse(int clientSocket);
void sendFileResponse(int clientSocket, const std::string& filePath);

#endif

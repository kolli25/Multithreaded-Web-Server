#include "utils.h"
#include <fstream>
#include <sstream>
#include <unistd.h>

std::string parseRequest(const std::string& request) {
    std::istringstream requestStream(request);
    std::string method, path, protocol;
    requestStream >> method >> path >> protocol;
    
    if (method != "GET") return "";
    if (path == "/") path = "/index.html"; // Default to index.html

    return "www" + path;  // File path inside www folder
}

void sendErrorResponse(int clientSocket) {
    std::string response = "HTTP/1.1 404 NOT FOUND

";
    send(clientSocket, response.c_str(), response.size(), 0);
}

void sendFileResponse(int clientSocket, const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file) {
        sendErrorResponse(clientSocket);
        return;
    }

    std::string response = "HTTP/1.1 200 OK

";
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    response += content;

    send(clientSocket, response.c_str(), response.size(), 0);
}

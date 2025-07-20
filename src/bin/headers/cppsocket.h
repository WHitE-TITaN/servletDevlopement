#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>


class inputSocket{
  WSADATA winSetup;
  SOCKET Server, Client;
  struct sockaddr_in serverAddressList, clientAddressList;
  char buffer[1024];

  bool startServer();
  public:

  inputSocket() {
    startServer();
  }
};

// definations

bool inputSocket::startServer(){
  int setup = WSAStartup(MAKEWORD(2, 2), &winSetup);
    if(setup != 0){
      std::cout << "Socket Setup Failed \n";
      return false;
    }

    Server = socket(AF_INET, SOCK_STREAM, 0);
    if(Server == INVALID_SOCKET){
      std::cout << "Socket Creation Faild \n";
      WSACleanup();
      return false;
    }

    serverAddressList.sin_family = AF_INET;
    serverAddressList.sin_addr.s_addr = INADDR_ANY;
    serverAddressList.sin_port = htons(9000);

    
    if(bind(Server, (struct sockaddr*)&serverAddressList, sizeof(serverAddressList)) == SOCKET_ERROR){
      std::cout << "Socket Bining failed \n";
      closesocket(Server);
      WSACleanup();
      return false;
    }


    listen(Server, 3);
    std::cout << "Server is listening on port 9000 \n";




    int clientAddressLength = sizeof(clientAddressList);
    Client = accept(Server, (struct sockaddr*)& clientAddressList, &clientAddressLength);
    if(Client == INVALID_SOCKET){
      std::cout << "Client Connection Failed \n";
      closesocket(Server);
      WSACleanup();
      return false;
    }

    std::cout << "Client Connected \n"<<
    "Client IP: " << clientAddressList.sin_addr.s_addr << "\n" <<
    "client Port: " << ntohs(clientAddressList.sin_port) << "\n";



    ZeroMemory(buffer, sizeof(buffer)); // or memset(buffer, 0, sizeof(buffer));

    int recive = recv(Client, buffer, sizeof(buffer), 0);
    if(recive == -1){
      std::cout << "Error in Reciving Data \n";
      closesocket(Client);
      closesocket(Server); 
      WSACleanup();
      return false;
    }

    std::cout << "Recived Data: " << buffer << "\n";
    const char* response = "Hello from Server!";
    send(Client, response, strlen(response), 0);
    std::cout << "Response Sent to Client \n";

    closesocket(Client);
    closesocket(Server);
    WSACleanup();
    return true;
}
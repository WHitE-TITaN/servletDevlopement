#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>


class inputSocket{
  WSADATA winSetup;
  SOCKET Server, Client;
  struct sockaddr_in serverAddressList, clientAddressList;

  bool startServer(){
    int setup = WSAStartup(MAKEWORD(2, 2), &winSetup);
    if(setup != 0){
      std::cout << "Socket Setup Failed \n";
      return false;
    }
    Server = socket(AF_INET, SOCK_STREAM, 0);
    if(Server == INVALID)
  }
  public:

};
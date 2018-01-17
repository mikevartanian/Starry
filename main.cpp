#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>

int main()
{
  int socketfd, newsocketfd;
  sockaddr_in server;
  char buffer[256];
  char message[1024];

  socketfd  = socket(AF_INET, SOCK_STREAM,0);
  server.sin_family = AF_INET;
  server.sin_port = htons(8000);
  server.sin_addr.s_addr = INADDR_ANY;

  std::cout << bind(socketfd, (sockaddr *) &server, sizeof(server)) << std::endl;
  listen(socketfd, 5);
  newsocketfd = accept(socketfd, (sockaddr *) &server, (socklen_t *)&server);
  std::cout << newsocketfd << std::endl;
  recv(socketfd,message, 1024,0);
  std::cout << message << std::endl;
  char  *reply = "Hello from server\n";
  send(newsocketfd, reply, strlen(reply),0);
  exit(0);
  

  
}

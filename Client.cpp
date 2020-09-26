/**
 * @author Gabriel Solano
 * @date 25/9/2020
 * @title Cliente de socket
 */
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>

#include <arpa/inet.h>
#include <string.h>
#include <string>

using namespace std;
/**
 * crea el socket
 * @return
 */
int main()
{
    //	Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        return 1;
    }

    int port = 54000;
    string ipAddress = "127.0.0.1"; //direccion IP a utilizar

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

    //	Se conecta al servidor
    int connectRes = connect(sock, (sockaddr*)&hint, sizeof(hint));
    if (connectRes == -1)
    {
        return 1;
    }


    char buf[4096];
    string userInput;

    do {
        cout << "> ";
        getline(cin, userInput);


        int sendRes = send(sock, userInput.c_str(), userInput.size() + 1, 0);
        if (sendRes == -1)
        {
            cout << "No se pudo enviar. \r\n";
            continue;
        }

        //esperando respuesta
        memset(buf, 0, 4096);
        int bytesReceived = recv(sock, buf, 4096, 0);
        if (bytesReceived == -1)
        {
            cout << "Error al obtener respuesta \r\n";
        }
        else
        {
            cout << "SERVER> " << string(buf, bytesReceived) << "\r\n";
        }
    } while(true);
    close(sock);
    return 0;
}
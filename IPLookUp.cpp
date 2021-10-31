/*Simple c++ code to check IP Address of a URL/Website's..::*/

#include <iostream>
#include <winsock2.h>
#include <cstring>

#pragma comment(lib, "ws2_32.lib");

#define MAX 100

using namespace std;

void title(){
    cout << "``````````````````````````````````````````````````````````````````\n";
    cout << "``````````````````````````````````````````````````````````````````\n";
    cout << "```````````````````````````IPLookookUp````````````````````````````\n";
    cout << "``````````````````````````````````````````````````````````````````\n";
    cout << "``````````````````````````````````````````````````````````````````\n";
}

int main(){
title();
system("color 3");
    WSADATA wdata;
    cout << "Enter the URL/Website you want to check it's IP Address: ";
    char URL[MAX];
    cin >> URL;
    char *HostURL;
    strcpy(HostURL,URL);
    char ip[MAX];
    struct hostent *ht;
    struct in_addr **addr_list;
    double errorcode=WSAGetLastError();

        cout << "\n[*]Initializing WinSock.......\n";
            if(WSAStartup(MAKEWORD(2,2),&wdata)!=0){
                cerr << "[!]Failed to initialize WinSock!!! ERROR Code: " << errorcode << "\n\n";
                system("PAUSE");
                return 0;
            }
        cout << "[*]WinSock initialization successful!!!\n\n";

        cout << "[*]Initializing gethostbyname to get IP Address.......\n";
            if((ht=gethostbyname(HostURL))==NULL){
                cerr << "[!]Failed to initialize gethostbyname!!! ERROR Code: " << errorcode << "\n\n";
                system("PAUSE");
                return 0;
            }
        cout << "[*]gethostbyname initialization successful!!!\n\n";

        addr_list=(struct in_addr**)ht->h_addr_list;

        for(int i=0;addr_list[i]!=NULL;i++){
            strcpy(ip,inet_ntoa(*addr_list[i]));
        }

        cout << URL << "'s IP Address is " << ip << "\n\n";

        system("pause");

    return 0;
}

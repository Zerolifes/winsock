#define _WIN32_WINNT 0x0601
#include<winsock2.h>
#include<ws2tcpip.h>
#include<iostream>
#include<windows.h>
using std::cout;
using std::endl;
int main()
{
    WSAData wsaData;
    int initWSA = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (initWSA!=0)
    {
        cout<<"WSAStartup failed, error code is: "<<initWSA;
        WSACleanup();
        return 1;
    }

    unsigned long ipa = inet_addr("127.0.0.251");
    unsigned long ipt;
    int res = inet_pton(AF_INET, "127.0.0.251", &ipt);
    if (res!=1)
    {
        cout<<"inet_pton error, error code is: "<<res;
        WSACleanup();
        return 1;
    }

    cout<<"inet_addr unsigned long ip: "<<ipa<<endl;
    cout<<"inet_pton unsigned long ip: "<<ipt<<endl;

    WSACleanup();
    return 0;
}

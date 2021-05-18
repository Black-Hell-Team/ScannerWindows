#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <winsock2.h>
#include <windows.h>
int main()
{  WSADATA p;
int b =WSAStartup(MAKEWORD(2,2),&p);
if(b==0){
    printf("WSAStartup iniciada com sucesso\n");
}
else {
    printf("\ Falha ao iniciar WSAStartup\n");

}
char v[]=" BEM  VINDO AO SCANNER WINDOWS"
         " ESSE PORTA SCANNER ENUMERA SOMENTE UMA PORTA E IP";
printf("%s\n",v);
char IP[100],*z=&IP;
int k;
printf("Digite seu IP:\n");
scanf("%s",IP);
printf("Digite sua porta: \n");
scanf("%d",&k);
SOCKET s=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
struct sockaddr_in  cliente,*ptr;
ptr=&cliente;
cliente.sin_family=AF_INET;
cliente.sin_port=htons(k);
cliente.sin_addr.s_addr=inet_addr(IP);


int m=connect(s,ptr,sizeof(cliente));
if(m==0){
    printf("A porta se encontra aberta");
    closesocket(s);
    WSACleanup();
}
else{
    printf("A porta se encontra  fechada");
    closesocket(s);
    WSACleanup();
}
    return 0;
}

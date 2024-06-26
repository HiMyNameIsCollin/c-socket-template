#if defined(_WIN32)
#ifndef _WIN32_WINNT
#endif
#define _WIN32_WINNT 0X0600

#include <winsock2.h>
#include <ws2tcpip.h>

#else

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#endif

#include <stdio.h>

int main() {
#if defined(_WIN32)
    WSADATA d;
    if (WSAStartup(MAKEWORD(2, 2), &d)) {
        fprintf(stderr, "Failed to init. \n");
        return 1;
    }
#endif

    printf("REady to use socket API. \n");

#if defined(_WIN32)
    WSACleanup();
#endif

    return 0;
}

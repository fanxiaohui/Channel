#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include "trans_packet.h"

void on_packet_recv(char* from_ip, uint16_t from_port, char* payload, int size, unsigned int seq) {
    printf("Packet received from=%s:%d, seq=%d\n", from_ip, from_port, seq);
    char* message = (char*)malloc(size);
    memcpy(message, payload, size);
    printf(message);
    free(message);
    printf("\n");

}

int main (void) {
    init_packet();

    struct packet_info packetinfo;
    packetinfo.dest_ip = "108.0.0.1"; //填写服务器IP
    packetinfo.dest_port = 8888;
    packetinfo.source_ip = "192.168.1.100"; //本地IP
    packetinfo.source_port = 34567;
    packetinfo.on_packet_recv = on_packet_recv;

    char* text = "Hello World!";

    send_packet(&packetinfo, text, strlen(text) + 1, 1234);

    recv_packet_loop(&packetinfo);

    return 0;

}

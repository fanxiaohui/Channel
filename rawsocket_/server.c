#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include "trans_packet.h"

struct packet_info packetinfo;


void on_packet_recv(char* from_ip, uint16_t from_port, char* payload, int size, unsigned int seq) {
    printf("Packet received from=%s:%d, seq=%d\n", from_ip, from_port, seq);
    char* message = (char*)malloc(size);
    memcpy(message, payload, size);
    printf(message);
    free(message);
    printf("\n");

    packetinfo.dest_ip = from_ip;
    packetinfo.dest_port = from_port;

    char* text = "Response from server.";
    send_packet(&packetinfo, text, strlen(text) + 1, 5678);


}

int main (void) {
    init_packet();

    packetinfo.dest_ip = 0;
    packetinfo.dest_port = 0;
    packetinfo.source_ip = "108.0.0.1"; //填写服务器IP
    packetinfo.source_port = 8888;
    packetinfo.on_packet_recv = on_packet_recv;

    recv_packet_loop(&packetinfo);

    return 0;

}

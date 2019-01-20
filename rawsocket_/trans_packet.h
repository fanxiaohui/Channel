#define MTU 1440

struct packet_info {
    char* dest_ip;
    char* source_ip;
    uint16_t dest_port;
    uint16_t source_port;
    void (*on_packet_recv)(char*, uint16_t, char*, int, unsigned int);

};


void init_packet();
int send_packet(struct packet_info* packetinfo, char* payload, int payloadlen, unsigned int seq);
void recv_packet_loop(struct packet_info* packetinfo);

#include <stdio.h>

#include "pf_packet.h"

int main(void){
    int sock = nic_init("eno1",NIC_LOCAL_PORT);
    reader(sock);
    return 0;
}
#include <stdio.h>

#include "pf_packet.h"

int main(void){
    nic_init("eno1",NIC_LOCAL_PORT);
    return 0;
}
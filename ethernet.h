#ifndef ETHERNET_H
#define ETHERNET_H

#include <unistd.h>

#define ETHER_TYPE_IPV4         0x0800
#define ETHER_TYPE_IPV6         0x86dd
#define ETHER_TYPE_ARP          0x0806

#define TPID                    0x8100

#define MAC_LEN 6

#define ETHER_HDR_LEN_WITH_NOVLAN 14
#define ETHER_HDR_LEN_WITH_VLAN 18

typedef struct{
    __uint8_t dst[MAC_LEN];
    __uint8_t src[MAC_LEN];
    __uint16_t type;
}ether_hdr;

typedef struct{
    __uint8_t dst[MAC_LEN];
    __uint8_t src[MAC_LEN];
    __uint8_t pcp;            //フレーム優先度（3bit）
    __uint8_t dei;            //輻輳時設定 0/1（1bit）
    __uint16_t vid;           //VLAN ID（12bit）
    __uint16_t type;
}ether_hdr_v;

//フレーム優先度/輻輳時設定は無視します


void input_ethernet(__uint8_t *buf);

#endif //ETHERNET_H

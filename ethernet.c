#include "ethernet.h"
#include <stdio.h>
#include <unistd.h>

void input_ethernet(__uint8_t *buf)
{
    __uint16_t type = (buf[12] << 8) | buf[13];
    switch (type)
    {
    case 0x0800:
        break;
    case 0x86dd:
        break;
    case 0x0806:
        puts("ARP");
        break;
    case 0xeec3:
        //Yamaha APの制御用フレーム
        puts("Yamaha controll frame");
        break;
    default:
        //VLANパケット
        break;
    }
}

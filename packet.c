#include "packet.h"
#include "ethernet.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void reader(int sock){
    __uint8_t buf[2000];

    while (1)
    {
        if (read(sock,buf,sizeof(buf)) <= 0)
        {
            perror("read");
        }else
        {
            input_ethernet(&buf);
        }
    }
}

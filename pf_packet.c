
#include <stdio.h>
#include <unistd.h>

#include <sys/socket.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <netpacket/packet.h>
#include <net/if.h>
#include <netinet/if_ether.h>
#include <netinet/in.h>
#include <linux/if.h>
#include "pf_packet.h"

#include <string.h>

//デバイス名を指定してファイルディスクリプタを返す
//初期化するポートがLAN向けだったらtypeにはNIC_LOCAL_PORT、WAN向けならNIC_WAN_PORTを指定する
int nic_init(char *name,int type){
    struct ifreq ifr;
    struct sockaddr_ll addr;


    int sock = socket(PF_PACKET,SOCK_RAW,htons(ETH_P_ALL));
    if (sock < 0)
    {
        perror("Can't create socket.");
        return -1;
    }

    memset(&ifr,0,sizeof(struct ifreq));
    strncpy(ifr.ifr_name,name,sizeof(ifr.ifr_ifrn.ifrn_name) - 1);

    if (ioctl(sock,SIOGIFINDEX,&ifr) < 0)
    {
        perror("ioctl error");
        close(sock);
        return -1;
    }

    addr.sll_family = PF_PACKET;
    addr.sll_protocol = htons(ETH_P_ALL);
    addr.sll_ifindex = ifr.ifr_ifindex;

    if (bind(sock,(struct sockaddr *)&addr,sizeof(addr)) < 0)
    {
        perror("bind error");
        close(sock);
        return -1;
    }

    if (type == NIC_LOCAL_PORT)
    {
        if (ioctl(sock,SIOCGIFFLAGS,&ifr) < 0)
        {
            perror("ioctl error");
            close(sock);
            return -1;
        }
        ifr.ifr_flags = ifr.ifr_flags | IFF_PROMISC;
        if (ioctl(sock,SIOCSIFFLAGS,&ifr) < 0)
        {
            perror("ioctl error");
            close(sock);
            return -1;
        }
    }


    return sock;
}
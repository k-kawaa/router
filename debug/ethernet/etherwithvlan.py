from scapy.all import *

pkt = Ether(dst="a0:48:1c:84:55:ec") / Dot1Q(vlan=100) / IP(dst="192.168.50.49") / ICMP()

pkt.show()

sendp(pkt, iface="eno1", verbose=0) 

# Basic Network Note

## Addresses

### IP (Internet Protocol) address 



### MAC (Media Access Control) address

Each hardware has an invariant MAC address. A computer may have a unique MAC address for each network interface (WLAN, LAN, etc). MAC address is in the form of `b4:8c:9d:50:d0:79` (6 haxdecimal pair, 48 bit)

The mac address can be found by `ifconfig`, `ip addr`. Look for `ether`, `link/ether`, `HWaddr` in the output. 

For example

```
$ ip addr
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
    inet6 ::1/128 scope host noprefixroute
       valid_lft forever preferred_lft forever
2: enp46s0: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc fq_codel state DOWN group default qlen 1000
    #################################
    # MAC address is 50:eb:f6:e3:8d:f3 for LAN
    #################################
    link/ether 50:eb:f6:e3:8d:f3 brd ff:ff:ff:ff:ff:ff
3: wlp45s0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc noqueue state UP group default qlen 1000
    #################################
    # MAC address is b4:8c:9d:50:d0:79 for WLAN 
    #################################
    link/ether b4:8c:9d:50:d0:79 brd ff:ff:ff:ff:ff:ff
    inet 192.168.0.13/24 brd 192.168.0.255 scope global dynamic noprefixroute wlp45s0
       valid_lft 86398sec preferred_lft 86398sec
    inet6 fdd3:566a:ab8b:0:e156:bf39:46e4:d37b/64 scope global noprefixroute
       valid_lft forever preferred_lft forever
    inet6 2a02:c7c:caf6:d000:5710:db4b:3c86:db38/64 scope global dynamic noprefixroute
       valid_lft 2029sec preferred_lft 2027sec
    inet6 fe80::d7c:7062:c328:96f3/64 scope link noprefixroute
       valid_lft forever preferred_lft forever
```

Here, the MAC address of the wireless interface is `b4:8c:9d:50:d0:79`, and MAC of LAN is `50:eb:f6:e3:8d:f3`


## SSH 



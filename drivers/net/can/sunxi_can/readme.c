1£¬kernel_driver

/driver/net/sunxi_can/sun7i_can.c




a,  /driver/net/sunxi_can/Makefile

      #add by jiangdou
obj-$(CONFIG_CAN_SUN7I) += sun7i_can.o

b:   /driver/net/sunxi_can/Kconfig

 #add by jiangdou for sunxi_can

config CAN_SUN7I
        tristate "Sun7i CAN bus controller"
        default n
        help
        This is the Sun7i CAN BUS driver for android system by peter chen.

1:    /driver/net/can/Kconfig

#add by jiangdou for sunxi_can

source "drivers/net/can/sunxi_can/Kconfig"





2:  driver/net/can/Makefile

 #add by jiangdou for sunxi_can
obj-$(CONFIG_CAN_SUN7I) += sunxi_can/




B:  modify   sys_config.fex

[can_para]
can_used = 1
can_tx              = port:PH20<4><default><default><default>
can_rx              = port:PH21<4><default><default><default>





C:  test

 root@sunxi#  ifconfig can0 up

<3>can0: bit-timing not yet defined
can0: bit-timing not yet defined
SIOCSIFFLAGS: Invalid argument





root@sunxi#  ip link set can0 type can bitrate 125000 triple-sampling on       //first  run

root@sunxi#  ifconfig can0 up               //then run



root@sunxi#  ifconfig 



can0      Link encap:UNSPEC  HWaddr 00-00-00-00-00-00-00-00-00-00-00-00-00-00-00-00  
          UP RUNNING NOARP  MTU:16  Metric:1
          RX packets:0 errors:0 dropped:0 overruns:0 frame:0
          TX packets:0 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:10 
          RX bytes:0 (0.0 B)  TX bytes:0 (0.0 B)
          Interrupt:58 

eth0      Link encap:Ethernet  HWaddr 02:c8:0b:41:f5:73  
          UP BROADCAST MULTICAST  MTU:1500  Metric:1
          RX packets:0 errors:0 dropped:0 overruns:0 frame:0
          TX packets:0 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:1000 
          RX bytes:0 (0.0 B)  TX bytes:0 (0.0 B)
          Interrupt:87 Base address:0x2000 

lo        Link encap:Local Loopback  
          inet addr:127.0.0.1  Mask:255.0.0.0
          inet6 addr: ::1/128 Scope:Host
          UP LOOPBACK RUNNING  MTU:16436  Metric:1
          RX packets:384 errors:0 dropped:0 overruns:0 frame:0
          TX packets:384 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:0 
          RX bytes:25728 (25.1 KiB)  TX bytes:25728 (25.1 KiB)


		  
/*
please  to refer to 1: http://www.ridgerun.com/developer/wiki/index.php/How_to_configure_and_use_CAN_bus
                    2:https://github.com/poopgiggle/c-can-forwarding/blob/f11ec94f94f8ed9c3978861bbbab7428cce23ebc/fwd-can.c
*/
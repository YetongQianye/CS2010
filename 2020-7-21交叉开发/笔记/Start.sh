#!/bin/sh

ifconfig eth0 down
ifconfig eth0 hw ether 08:90:00:A0:35:88
ifconfig eth0 192.168.31.4 netmask 255.255.255.0 up
telnetd &

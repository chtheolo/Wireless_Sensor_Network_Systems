#!/usr/bin/env python

#import sys
#import tos
#import time
#
#def main():
#    tx_pkt = tos.Packet([('data', 'int', 1)], [])
#    AM_ID = 6
#
#    serial_port = tos.Serial("/dev/ttyUSB0", 115200)
#    am = tos.AM(serial_port)
#
#    while 1:
#        raw_input("Press enter to send serial packet")
#        tx_pkt.data = 100
#        print "Sending a serial packet..."
#        am.write(tx_pkt, AM_ID)
#        # time.sleep(10)
#
#if _name_ == '_main_':
#    main

import sys
import tos

#application defined messages

def main():
	tx_pckt = tos.Packet([('data',  'int', 2)],[])
	
	AM_ID=6
	
	serial_port = tos.Serial("/dev/ttyUSB0",115200)
	am = tos.AM(serial_port)
	
	#for i in xrange(10):
	while 1:
		raw_input("Press enter to send serial packet\n")
		am.write(tx_pckt,AM_ID)


	#pckt = am.read(timeout=0.5)
	#if pckt is not None:
	#	print pckt.type
	#	print pckt.destination
	#	print pckt.source
	#	print pckt.data

if _name_ == '_main_':
	main
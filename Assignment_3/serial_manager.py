#!/usr/bin/env python

from __future__ import print_function
import argparse
import sys
import tos
import threading
import Queue
#import time

AM_QUERY_MSG = 6

#application defined messages
class AppMsg(tos.Packet):
    def __init__(self, packet = None):
        tos.Packet.__init__(self, 
                                [('sampling_period', 'int', 2),
                                 ('query_lifetime','int', 2),
                                 ('propagation_mode', 'int', 1)], 
                                packet)

def receiver(rx_queue):
    while True:
        msg = rx_queue.get()
        print('TelosB -> PC: ', str(msg.sampling_period), str(msg.query_lifetime), str(msg.propagation_mode))

def transmitter(tx_queue):
    while True:
        try:
            var1 = int(raw_input(''))
            var2 = int(raw_input(''))
            var3 = int(raw_input(''))
            print('PC -> TelosB: ', var1, var2, var3)
            msg = AppMsg((var1, var2, var3, []))
            print (msg)
            tx_queue.put(msg)
            print('Sent')
        except ValueError:
            print('Wrong input')


class SerialManager(object):

    def __init__(self, port, baudrate, am_channel):
        self.rx_queue = Queue.Queue()
        self.tx_queue = Queue.Queue()
        self.port = port
        self.baudrate = baudrate
        self.am_channel = am_channel
        try:
            self.serial = tos.Serial(self.port, self.baudrate)
            self.am = tos.AM(self.serial)
        except:
            print('Error: ', sys.exc_info()[1])
            sys.exit(1)
        rcv_thread = threading.Thread(target=receiver, args=(self.rx_queue,))
        rcv_thread.setDaemon(True)
        rcv_thread.start()
    
        snd_thread = threading.Thread(target=transmitter, args=(self.tx_queue,))
        snd_thread.setDaemon(True)
        snd_thread.start()
        
    def control_loop(self):
        print('Serial Manager started')
        while True:
            try:
                pkt = self.am.read(timeout=0.5)
                #print(pkt)
                if pkt and pkt.type == AM_QUERY_MSG:
                    print(pkt)
                    msg = AppMsg(pkt.data)
                    self.rx_queue.put(msg)
                if not self.tx_queue.empty():
                    tx_pkt = self.tx_queue.get()
                    self.am.write(tx_pkt, self.am_channel)
            except KeyboardInterrupt:
                print('Exiting')
                sys.exit(0)


def main():
    parser = argparse.ArgumentParser(
        formatter_class=argparse.ArgumentDefaultsHelpFormatter,
        description='Serial Manager.')
    parser.add_argument('--port', '-p',
                        default='/dev/ttyUSB0',
                        help='Serial port device.')
    parser.add_argument('--baudrate', '-b',
                        type=int,
                        default=115200,
                        help='Serial device baudrate.')
    parser.add_argument('--am_channel', '-c',
                        type=int,
                        default=6,
                        help='AM channel.')
    args = parser.parse_args()
    
    manager = SerialManager(args.port, args.baudrate, args.am_channel)
    #manager = SerialManager('/dev/ttyUSB0', '115200', 6)
    manager.control_loop()


if __name__ == '__main__':
    main()
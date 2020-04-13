#!/usr/bin/env python

from __future__ import print_function
import argparse
import sys
import tos
import threading
import Queue

#import time

AM_QUERY_MSG = 6
AM_QYERY_CANCEL_MSG = 16
AM_SAMPLING_MSG = 36
AM_STATS_SAMPLING_MSG = 46
AM_BINARY_MSG = 76
AM_BINARY_RSP = 86


#application defined messages
class QueryCancelMsg(tos.Packet):
    def __init__(self, packet = None):
        tos.Packet.__init__(self, 
                                [('source_id','int', 1),
                                 ('sequence_number','int', 1),
                                 ('propagation_mode', 'int', 1),
                                 ('forwarder_id', 'int', 1)], 
                                packet)

class AppMsg(tos.Packet):
    def __init__(self, packet = None):
        tos.Packet.__init__(self, 
                                [('sampling_period', 'int', 2),
                                 # ('query_lifetime','int', 2),
                                 ('query_lifetime','int', 4),
                                 ('propagation_mode', 'int', 1)], 
                                packet)

class SamplingMsg(tos.Packet):
    def __init__(self, packet = None):
        tos.Packet.__init__(self, 
                                [('source_id', 'int', 1),
                                 ('sampling_id', 'int', 1),
                                 ('data_id', 'int', 1),
                                 ('forwarder_id', 'int', 1),
                                 ('sensor_data', 'int', 2),
                                 ('destination_id','int', 1),
                                 ('sequence_number', 'int', 1),
                                 ('mode', 'int', 1)],
                                 #('ContributedNodes', 'int', 20)], #'blob' 
                                packet)

class StatsSamplingMsg(tos.Packet):
    def __init__(self, packet = None):
        tos.Packet.__init__(self, 
                                [('source_id', 'int', 1),
                                 ('data_id', 'int', 1),
                                 ('forwarder_id', 'int', 1),
                                 ('hops', 'int', 1),
                                 ('min', 'int', 2),
                                 ('max', 'int', 2),
                                 ('average', 'int', 2),
                                 ('destination_id','int', 1),
                                 ('sequence_number', 'int',1),
                                 ('contributed_ids', 'blob', 5), #'blob' 
                                 ('mode', 'int', 1)],
                                packet)

class BinaryMsg(tos.Packet):
    def __init__(self, packet = None):
        tos.Packet.__init__(self, 
                                [('app_id', 'int', 1),
                                 ('BinaryMessage', 'blob', 25),
                                 ('mode', 'int', 1),
                                 ('state', 'int', 1)],
                                packet)

class ResponseBinaryMsg(tos.Packet):
    def __init__(self, packet = None):
        tos.Packet.__init__(self, 
                                [('IDs', 'blob', 2),
                                 ('mode', 'int', 1)],
                                packet)



def receiver(rx_queue):
    while True:

        sampling_msg = rx_queue.get()
        
        print('Mode: ', str(sampling_msg.mode))

        if sampling_msg.mode == 0:
            print('TelosB -> PC: ')

            print('Sampling_Source_Node: ', str(sampling_msg.source_id))
            print('Sampling Data_ID: ', str(sampling_msg.sampling_id))
            print('Summary Data_ID: ', str(sampling_msg.data_id))
            print('Forwarder_id: ', str(sampling_msg.forwarder_id))
            print('Sensor_data: ', str(sampling_msg.sensor_data))
            print('Destination_ID: ', str(sampling_msg.destination_id))
            print('Query_id: ', str(sampling_msg.sequence_number))

            print('\n')
            
        elif sampling_msg.mode == 1:
            print('TelosB -> PC: ')
            
            print('Sampling Data_ID: ', str(sampling_msg.data_id))
            print('Min: ', str(sampling_msg.min))
            print('Max: ', str(sampling_msg.max))
            print('Average: ', str(sampling_msg.average))
            print('Destination_ID: ', str(sampling_msg.destination_id))
            print('Query_id: ', str(sampling_msg.sequence_number))
            print('Contributed Nodes: ')
            print(sampling_msg.contributed_ids)
        
            print('\n')

        elif sampling_msg.mode == 5:
            print("Application start!!\n")

        elif sampling_msg.mode == 6:
            print("Not Allocated!!\n")


def transmitter(tx_queue):
    print('Send VM ? Yes(1) or No(0): ')
    sendVM = int(raw_input(''))
    if sendVM == 0:
        while True:
            try:
                print('Transmitter ready to take input\n')
                var1 = int(raw_input(''))
                var2 = int(raw_input(''))
                var3 = int(raw_input(''))

                print('PC -> TelosB: ', var1, var2, var3)
                if var3 == 2:
                    var4 = var1
                    msg = QueryCancelMsg((var1, var2, var3, var4, []))
                elif var3 == 0 or var3 == 1:
                    var1 = var1 * 1000  # seconds
                    var2 = var2 * 60000 # minutes
                    msg = AppMsg((var1, var2, var3, []))

                print (msg)
                tx_queue.put(msg)
                print('Sent')

            except ValueError:
                print('Wrong input')
    elif sendVM == 1:
        active_ids = []
        active_applications = []
        while True:
            try:
                binary_array = []
                state = 1;

                print('\nRemove Application (0) or Run Application (1):')
                mode = int(raw_input(''))

                while mode != 1 and mode != 0:
                    print('\nWrong Input! Please Select -> Remove Application (0) or Run Application (1):')
                    mode = int(raw_input(''))

                if mode == 0 and len(active_ids) > 0:
                    print('\n\nActive Applications | ID')
                    id = 0
                    for application in active_applications:
                        print(application + " | " + str(active_ids[id]))
                        id+=1
                    print('\nType the application\'s name you wish to remove:')
                    binary_filename = raw_input('')
                    print('\nType the application\'s  you wish to remove:')
                    app_id = int(raw_input(''))
                    count_char = 25
                    for i in range(count_char):
                        binary_array.append(int('00',16))

                    msg = BinaryMsg((app_id, binary_array, state, mode, []))

                    print(msg)
                    tx_queue.put(msg)
                    print('Sent')

                    active_ids.remove(app_id)
                    active_applications.remove(binary_filename)

                    print('\n\nActive Applications | ID')
                    id = 0
                    for application in active_applications:
                        print(application + " | " + str(active_ids[id]))
                        id+=1

                elif mode == 0 and len(active_ids) == 0:
                    print('\nNo running applications in the system!')
                elif mode == 1 and len(active_ids) >= 2:
                    print('\nNot enough memory for new application!')
                elif mode == 1 and len(active_ids) < 2:
                    print('\nType a Binary Application file:')
                    binary_filename = raw_input('')
                    with open('Binary_Files/' + binary_filename + '.txt','r') as b_file:
                        for line in b_file:
                            for binary_code in line.split():
                                binary_array.append(int(binary_code, 16))
                
                    count_char = len(binary_array)
                    count_char = 25 - count_char
                    for i in range(count_char):
                        binary_array.append(int('00',16))

                    print('\nGive a unique id for ' + binary_filename + ' application ')
                    app_id = int(raw_input(''))

                    while app_id in active_ids:
                        print('\nThis id is already in use! Try another one.')
                        app_id = int(raw_input(''))

                    active_ids.append(app_id) #insert new id
                
                    msg = BinaryMsg((app_id, binary_array, state, mode, []))

                    print(msg)
                    tx_queue.put(msg)
                    print('Sent\n\n')

                    print('Active Applications | ID')
                    id = 0
                    active_applications.append(binary_filename)
                    for application in active_applications:
                        print(application + " | " + str(active_ids[id]))
                        id+=1

                    print('\n')
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
                
                if pkt is not None and len(pkt.data) == 9:
                    print(pkt.data)
                    msg = SamplingMsg(pkt.data)
                    sampling_msg = SamplingMsg(pkt.data)
                    self.rx_queue.put(sampling_msg)
                elif pkt is not None and len(pkt.data) == 18:
                    print(pkt)
                    msg = StatsSamplingMsg(pkt.data)
                    sampling_msg = StatsSamplingMsg(pkt.data)
                    self.rx_queue.put(sampling_msg)
                elif pkt is not None and len(pkt.data) == 3:
                    print(pkt)
                    msg = ResponseBinaryMsg(pkt.data)
                    sampling_msg = ResponseBinaryMsg(pkt.data)
                    self.rx_queue.put(sampling_msg)
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
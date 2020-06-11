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

active_applications = []

#application defined messages
class QueryCancelMsg(tos.Packet):
    def __init__(self, packet = None):
        tos.Packet.__init__(self, 
                                [('source_id','int', 1),
                                 ('app_id', 'int', 1),
                                 ('sequence_number','int', 1),
                                 ('mode', 'int', 1),
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
                                 ('application_id', 'int', 1),
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
                                 ('application_id', 'int', 1),
                                 ('data_id', 'int', 1),
                                 ('forwarder_id', 'int', 1),
                                 ('hops', 'int', 1),
                                 ('data_1', 'int', 2),
                                 ('data_2', 'int', 2),
                                 # ('average', 'int', 2),
                                 ('destination_id','int', 1),
                                 ('sequence_number', 'int',1),
                                 # ('contributed_ids', 'blob', 5), #'blob' 
                                 ('mode', 'int', 1)],
                                packet)

class BinaryMsg(tos.Packet):
    def __init__(self, packet = None):
        tos.Packet.__init__(self, 
                                [('app_id', 'int', 1),
                                 ('BinaryMessage', 'blob', 30),
                                 ('action', 'int', 1),
                                 ('state', 'int', 1),
                                 # ('propagation_mode', 'int', 1),
                                 ('query_lifetime', 'int', 4),],
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
            print('Application_id: ', str(sampling_msg.application_id))
            print('Summary Data_ID: ', str(sampling_msg.data_id))
            print('Forwarder_id: ', str(sampling_msg.forwarder_id))
            print('Sensor_data: ', str(sampling_msg.sensor_data))
            print('Destination_ID: ', str(sampling_msg.destination_id))
            print('Query_id: ', str(sampling_msg.sequence_number))

            print('\n')
            
        elif sampling_msg.mode == 1:
            print('TelosB -> PC: ')
            print('Sampling_Source_Node: ', str(sampling_msg.source_id))
            print('Application_id: ', str(sampling_msg.application_id))
            print('Sampling Data_ID: ', str(sampling_msg.data_id))
            print('Data_1: ', str(sampling_msg.data_1))
            print('Data_2: ', str(sampling_msg.data_2))
            # print('Average: ', str(sampling_msg.average))
            print('Destination_ID: ', str(sampling_msg.destination_id))
            print('Query_id: ', str(sampling_msg.sequence_number))
            # print('Contributed Nodes: ')
            # print(sampling_msg.contributed_ids)
        
            print('\n')

        elif sampling_msg.mode == 2:
            print('TelosB -> PC: ')
            print('Sampling_Source_Node: ', str(sampling_msg.source_id))
            print('Application_id: ', str(sampling_msg.app_id))
            app_id = int(sampling_msg.app_id)
            
            for application in active_applications:
                if str(app_id) in application:
                    app = application
                    active_applications.remove(app)

            print('\n\nActive Applications | ID')
            for application in active_applications:
                print(application)

            print('\n\n')

        elif sampling_msg.mode == 6:
            print("Not Allocated!!\n")

def Id_Exists(app_id):
    for application in active_applications:
        if (app_id in application):
            return True
    return False

def transmitter(tx_queue):

    # file_size = int(30)
    # active_ids = []
    # active_applications = []
    print('Transmitter ready to take input\n')
    while True:
        try:
            binary_array = []
            state = 1;

            print('\nRemove Application (0) or Run Application (1):')
            action = int(raw_input(''))

            while action != 1 and action != 0:          #loop-cheking the correctness of the user's input.
                print('\nWrong Input! Please Select -> Remove Application (0) or Run Application (1):')
                action = int(raw_input(''))

            if action == 0 and len(active_applications) > 0:     #Delete application 
                print('\n\nActive Applications | ID')

                for application in active_applications:
                    print(application)

                print('\nType the application\'s name you wish to remove:')
                binary_filename = raw_input('')

                print('\nType the application\'s  you wish to remove:')
                app_id = int(raw_input(''))

                count_char = 30
                # count_char = file_size
                for i in range(count_char):
                    binary_array.append(int('00',16))

                msg = BinaryMsg((app_id, binary_array, state, action, query_lifetime, []))

                print(msg)
                tx_queue.put(msg)
                print('Sent')

            elif action == 0 and len(active_applications) == 0:          #Delete failure -No active applications.
                print('\nNo running applications in the system!')

            elif action == 1 and len(active_applications) >= 2:          #Memory failure -Not possible to enter new application.
                print('\nNot enough memory for new application!')

            elif action == 1 and len(active_applications) < 2:           #Enter a new application.

                print('Enter the app\'s lifetime (minutes): ')  #Choose the query lifetime (in minutes).
                query_lifetime = int(raw_input(''))
                query_lifetime = query_lifetime * 60000

                print('\nType a Binary Application file:')      #Enter binary application file.
                binary_filename = raw_input('')
                with open('Binary_Files/' + binary_filename + '.txt','r') as b_file:
                    for line in b_file:
                        for binary_code in line.split():
                            binary_array.append(int(binary_code, 16))
            
                count_char = len(binary_array)                  #Fill in the remaining file with '0x00'.
                # count_char = file_size - count_char
                count_char = 30 - count_char
                for i in range(count_char):
                    binary_array.append(int('00',16))
                                                                #Select a unique ID for each application.
                print('\nGive a unique id for ' + binary_filename + ' application ')
                app_id = int(raw_input(''))

                exist = Id_Exists(str(app_id))
                while exist == True:
                    print('\nThis id is already in use! Try another one.')
                    app_id = int(raw_input(''))
                    exist = Id_Exists(str(app_id))

            
                msg = BinaryMsg((app_id, binary_array, state, action, query_lifetime, []))    #Configure the message. ,propagation_mode?

                print(msg)
                tx_queue.put(msg)                               #Send the message to serial.
                print('Sent\n\n') 

                print('Active Applications | ID')               #Update with the active applications in the network.
                active_applications.append(binary_filename +" | " + str(app_id))
                for application in active_applications:
                    print(application)
                   

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
                
                if pkt is not None and len(pkt.data) == 9:          #Simple mode bfr(9)
                    print(pkt.data)
                    msg = SamplingMsg(pkt.data)
                    sampling_msg = SamplingMsg(pkt.data)
                    self.rx_queue.put(sampling_msg)
                elif pkt is not None and len(pkt.data) == 12:       #stats mode bfr(18)
                    print(pkt)
                    msg = StatsSamplingMsg(pkt.data)
                    sampling_msg = StatsSamplingMsg(pkt.data)
                    self.rx_queue.put(sampling_msg)
                elif pkt is not None and len(pkt.data) == 5:        #delete confirmation
                    print(pkt)
                    msg = QueryCancelMsg(pkt.data)
                    delete_msg = QueryCancelMsg(pkt.data)
                    self.rx_queue.put(delete_msg)
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
#! /usr/bin/python

import sys
import time

#init variables
count_nodes = 0
# count_contributed_nodes = 0
# measurement_message_received = 0;
total_packet_transmissions = 0

FILE_NAME = 'grid3x3_3.txt'

with open(FILE_NAME,'r') as f:
	for line in f:
		for nodes in line.split():
			if nodes == 'Creating':  #Reading every time 'Creating' means we create once, noise for every node. So we can find the nodes 
				count_nodes += 1

print "Number of Nodes in the topology: " + str(count_nodes) + "\n"

for node in range(1,count_nodes+1):
	unicast_count_tx = 0
	reunicast_count_tx = 0
	measurement_message_received = 0
	count_contributed_nodes = 0

	with open(FILE_NAME,'r') as f:
		for line in f:
			if line.startswith("DEBUG (" + str(node)+ ")"):
				for tx in line.split():
					if tx == "UNICAST":
						unicast_count_tx += 1
						total_packet_transmissions += 1
					elif tx == "RE-UNICAST":
						reunicast_count_tx += 1
						total_packet_transmissions += 1
					elif tx == "Measurement_Sampling":
						measurement_message_received += 1
					elif tx == "Contributed":
						count_contributed_nodes += 1

	print "Node: " + str(node) + ", Unicast Measurements: " + str(unicast_count_tx) +", Forward Unicast Measurements: " + str(reunicast_count_tx) + ", Measurement Messages Received: " + str(measurement_message_received)

print "Total Packet transmissions: " + str(total_packet_transmissions)

#print(count_tx)



	# with open(FILE_NAME,'r') as f:
		# for line in f:
			# if line.startswith("DEBUG (" + str(node)+ ")"):
				# for rx in line.split():
					# if rx == "Measurement_Sampling":
						# measurement_message_received += 1
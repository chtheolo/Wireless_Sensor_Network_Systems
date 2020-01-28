#! /usr/bin/python

import sys
import time

count_nodes = 0
count_tx = 0
#unicast_count_tx = 0
#reunicast_count_tx = 0

with open('chain9.txt','r') as f:
	for line in f:
		for nodes in line.split():
			if nodes == 'Creating':  #Reading every time 'Creating' means we create once, noise for every node. So we can find the nodes 
				count_nodes += 1

print "Number of Nodes in the topology: " + str(count_nodes)

for node in range(1,count_nodes+1):
	unicast_count_tx = 0
	reunicast_count_tx = 0

	with open('chain9.txt','r') as f:
		for line in f:
			if line.startswith("DEBUG (" + str(node)+ ")"):
				for tx in line.split():
					if tx == "UNICAST":
						unicast_count_tx += 1
					elif tx == "RE-UNICAST":
						reunicast_count_tx += 1

	print "Node: " + str(node) + ", Unicast Transmissions: " + str(unicast_count_tx) +", Re-Unicast Transmissions: " + str(reunicast_count_tx)

#print(count_tx)

#! /usr/bin/python
from TOSSIM import *
from tinyos.tossim.TossimApp import *
import sys


n = NescApp()
t = Tossim(n.variables.variables())
r = t.radio()
f = open("chain.txt", "r")

for line in f:
  s = line.split()
  if s:
    print " ", s[0], " ", s[1], " ", s[2];
    r.add(int(s[0]), int(s[1]), float(s[2]))

print "\nthe last node is ",s[1] 
last_node = int(s[1]) +1

t.addChannel("BroadcastingC", sys.stdout)
t.addChannel("Re-BroadcastingC", sys.stdout)
t.addChannel("RadioC", sys.stdout)
t.addChannel("TimeC", sys.stdout)
t.addChannel("ReceiveC", sys.stdout)
t.addChannel("RoutingTableC", sys.stdout)

noise = open("/opt/tinyos-2.1.2/tos/lib/tossim/noise/meyer-heavy.txt", "r")
for line in noise:
  str1 = line.strip()
  if str1:
    val = int(str1)
    for i in range(1, last_node): #6,8,10
      t.getNode(i).addNoiseTraceReading(val)

for i in range(1, last_node): #6,8,10
  print "Creating noise model for ",i;
  t.getNode(i).createNoiseModel()
  
for i in range(1, last_node): #6,8,10
	t.getNode(i).bootAtTime(i* 100001)


for i in range(9000): 
  t.runNextEvent()
  
for i in range(1, last_node): #6,8,10
	m=t.getNode(i)
	v=m.getVariable("RadioFloodingC.seq_num")
	seq_num = v.getData()
	print "\nThe node_" + str(i) + " has seq_num = " + str(seq_num) + "\n"
	
	v=m.getVariable("RadioFloodingC.transmissions")
	transmissions = v.getData()
	print "The node[" + str(i) + "]" + " transmitted " + str(transmissions) + " packets.\n"
	
	v=m.getVariable("RadioFloodingC.receivedMsgs")
	receivedMsgs = v.getData()
	print "The node[" + str(i) + "]" + " received " + " " + str(receivedMsgs) + " packets.\n"
	
	v=m.getVariable("RadioFloodingC.newMessageReceived")
	newMessageReceived = v.getData()
	print "The node[" + str(i) + "]" + " received  " + " " + str(newMessageReceived) + " new packets.\n"
	
	v=m.getVariable("RadioFloodingC.diffTime")
	diffTime = v.getData()
	print "The node[" + str(i) + "]" + " latency of message[1] = " + " " + str(diffTime) + " s .\n"
	
	v=m.getVariable("RadioFloodingC.RoutingArray")
	RoutingArray = v.getData()
	print "\nThe Routing Table of node_" + str(i)
	for j in range(10):
		print "node[" + str(RoutingArray[j]) + "]"
	
	print "\n"
  
	





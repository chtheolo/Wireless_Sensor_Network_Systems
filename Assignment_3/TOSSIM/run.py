#! /usr/bin/python
import sys
import time

from tinyos.tossim.TossimApp import *

from TOSSIM import *
from QueryPacketMsg import *
#import numpy as np


n = NescApp()
t = Tossim(n.variables.variables())
m = t.mac()
r = t.radio()
sf = SerialForwarder(9001)
#throttle = Throttle(t, 10)
f = open("Topologies/grid3x3.txt", "r")

for line in f:
  s = line.split()
  if s:
    print " ", s[0], " ", s[1], " ", s[2];
    r.add(int(s[0]), int(s[1]), float(s[2]))

last_node = int(s[0]) + 1

t.addChannel("BlinkC", sys.stdout)
t.addChannel("BroadcastingC", sys.stdout)
t.addChannel("Re-BroadcastingC", sys.stdout)
t.addChannel("RadioC", sys.stdout)
t.addChannel("ReceiveC", sys.stdout)
t.addChannel("QueryC", sys.stdout)

noise = open("Noise/noNoise.txt", "r")
for line in noise:
  str1 = line.strip()
  if str1:
    val = int(str1)
    for i in range(1, last_node): #6,8,10
      t.getNode(i).addNoiseTraceReading(val)

for i in range(1, last_node): #6,8,10
  print "Creating noise model for ",i;
  t.getNode(i).createNoiseModel()

for i in range(1, last_node):
  m = t.getNode(i)
  m.bootAtTime(i* 100001)
  #m.bootAtTime((31 + t.ticksPerSecond() / 10) * i + 1);

#for i in range(1, last_node): #6,8,10
#  t.getNode(i).bootAtTime(i* 100001)

sf.process();
# throttle.initialize();

for i in range(0, 60):
  # throttle.checkThrottle();
  t.runNextEvent();
  sf.process();

msg = QueryPacketMsg()
msg.set_sampling_period(5000);
msg.set_query_lifetime(15000);
msg.set_propagation_mode(0);


serialpkt = t.newSerialPacket();
serialpkt.setData(msg.data)
serialpkt.setType(msg.get_amType())
serialpkt.setDestination(1)
serialpkt.deliver(1, t.time() + 3)

msg2 = QueryPacketMsg()
msg2.set_sampling_period(4000);
msg2.set_query_lifetime(20000);
msg2.set_propagation_mode(0);

serialpkt2 = t.newSerialPacket();
serialpkt2.setData(msg2.data)
serialpkt2.setType(msg2.get_amType())
serialpkt2.setDestination(1)
serialpkt2.deliver(1, t.time() + 400000000000)

msg3 = QueryPacketMsg()
msg3.set_sampling_period(6000);
msg3.set_query_lifetime(18000);
msg3.set_propagation_mode(0);

serialpkt3 = t.newSerialPacket();
serialpkt3.setData(msg3.data)
serialpkt3.setType(msg3.get_amType())
serialpkt3.setDestination(1)
serialpkt3.deliver(1, t.time() + 600000000000)

for i in range(300000): #(0, 20):
  t.runNextEvent();
  

  
#for i in range(1, last_node): #6,8,10
#	t.getNode(i).bootAtTime(i* 100001)
#
#
#for i in range(1000000): 
#  t.runNextEvent()
  
#for i in range(1, last_node): #6,8,10
#  m=t.getNode(i)
#  v=m.getVariable("RadioFloodingC.NeighborsArray")
#  NeighborsArray = v.getData()
#
#  #print(np.matrix(NeighborsArray))
#  print "\nThe Routing Table of node_" + str(i)
#  for j in range(10):
#    print str(NeighborsArray)
#  
#  print "\n"


#	v=m.getVariable("RadioFloodingC.seq_num")
#	seq_num = v.getData()
#	print "The node_" + str(i) + " has seq_num = " + str(seq_num) + "\n"
#	
#	v=m.getVariable("RadioFloodingC.transmissions")
#	transmissions = v.getData()
#	print "The node[" + str(i) + "]" + " transmitted " + str(transmissions) + " packets.\n"
#	
#	v=m.getVariable("RadioFloodingC.receivedMsgs")
#	receivedMsgs = v.getData()
#	print "The node[" + str(i) + "]" + " received " + " " + str(receivedMsgs) + " packets.\n"
#	

#for i in range(1, 6): #6,8,10
#	m=t.getNode(i)
	





#! /usr/bin/python
from TOSSIM import *
from tinyos.tossim.TossimApp import *
import sys
#import numpy as np


n = NescApp()
t = Tossim(n.variables.variables())
r = t.radio()
f = open("../Topologies/wheel.txt", "r")

for line in f:
  s = line.split()
  if s:
    print " ", s[0], " ", s[1], " ", s[2];
    r.add(int(s[0]), int(s[1]), float(s[2]))

last_node = int(s[1]) +1

t.addChannel("BlinkC", sys.stdout)
t.addChannel("BroadcastingC", sys.stdout)
t.addChannel("Re-BroadcastingC", sys.stdout)
t.addChannel("RadioC", sys.stdout)
t.addChannel("ReceiveC", sys.stdout)
t.addChannel("RoutingTableC", sys.stdout)

noise = open("../Noise/simple-noise.txt", "r")
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


for i in range(1000000): 
  t.runNextEvent()
  
for i in range(1, last_node): #6,8,10
  m=t.getNode(i)
  v=m.getVariable("RadioFloodingC.transmissions")
  transmissions = v.getData()

  print "\n    NODE_" + str(i) + "\nTransmisions : " + str(transmissions) + "\n"

  m=t.getNode(i)
  v=m.getVariable("RadioFloodingC.receivings")
  receivings = v.getData()

  print "\nReceivings : " + str(receivings) + "\n"

  m=t.getNode(i)
  v=m.getVariable("RadioFloodingC.new_receivings")
  new_receivings = v.getData()

  print "\nNew Receivings : " + str(new_receivings) + "\n"
  
  print "\n"
	





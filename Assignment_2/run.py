#! usr/bin/python
from TOSSIM import *
import sys
from SerialFloodingMsg import *

t = Tossim([])
r = t.radio()
f = open("topology.txt","r")
print "Select your master node"
master_node = input()
print "You select the node_",master_node;

num_nodes=1
for line in f:
	s = line.split()
	if s:
		num_nodes+=1
		print " ", s[0], " ", s[1], " ", s[2]
		r.add(int(s[0]), int(s[1]), float(s[2]))

t.addChannel("BlinkC", sys.stdout)

noise = open("/opt/tinyos-2.1.2/tos/lib/tossim/noise/meyer-heavy.txt", "r")
for line in noise:
	str1 = line.strip()
	if str1:
		val = int(str1)
		for i in range(1,5):
			t.getNode(i).addNoiseTraceReading(val)

for i in range(1, 5):
	print "Creating noise model for ",i;
	t.getNode(i).createNoiseModel()
	
for i in range (1,5):
  t.getNode(i).createNoiseModel()
  t.getNode(i).bootAtTime(i * 2351217 + 23542399)
	

	
msg = SerialFloodingMsg()
msg.set_period(3)
pkt = t.newPacket()
pkt.setData(msg.data)
pkt.setType(msg.get_amType())
pkt.setDestination(master_node)

print "Delivering " + str(msg) + " to " + str(master_node) + " at " + str(t.time() + 3);
pkt.deliver(master_node, t.time() + 3)

for i in range(1000000):
  t.runNextEvent() 

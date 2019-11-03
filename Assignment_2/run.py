#! usr/bin/python
from TOSSIM import *
import sys

t = Tossim([])
r = t.radio()
f = open("topology.txt","r")

for line in f:
	s = line.split()
	if s:
		print " ", s[0], " ", s[1], " ", s[2]
		r.add(int(s[0]), int(s[1]), float(s[2]))

t.addChannel("BlinkC", sys.stdout)

noise = open("/opt/tinyos-2.1.2/tos/lib/tossim/noise/meyer-heavy.txt", "r")
for line in noise:
	str1 = line.strip()
	if str1:
		val = int(str1)
		for i in range(1,4):
			t.getNode(i).addNoiseTraceReading(val)

for i in range(1, 4):
	print "Creating noise model for ",i;
	t.getNode(i).createNoiseModel()
	
t.getNode(1).bootAtTime(100001);
t.getNode(2).bootAtTime(800008);
t.getNode(3).bootAtTime(1800009);

for i in range(100):
  t.runNextEvent() 

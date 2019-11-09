#! /usr/bin/python
from TOSSIM import *
import sys

t = Tossim([])
r = t.radio()
f = open("chain.txt", "r")

for line in f:
  s = line.split()
  if s:
    print " ", s[0], " ", s[1], " ", s[2];
    r.add(int(s[0]), int(s[1]), float(s[2]))

t.addChannel("BroadcastingC", sys.stdout)
t.addChannel("Re-BroadcastingC", sys.stdout)
t.addChannel("RadioC", sys.stdout)
t.addChannel("ReceiveC", sys.stdout)

noise = open("/opt/tinyos-2.1.2/tos/lib/tossim/noise/meyer-heavy.txt", "r")
for line in noise:
  str1 = line.strip()
  if str1:
    val = int(str1)
    for i in range(1, 6):
      t.getNode(i).addNoiseTraceReading(val)

for i in range(1, 6):
  print "Creating noise model for ",i;
  t.getNode(i).createNoiseModel()
  
for i in range(1,6):
	t.getNode(i).bootAtTime(i* 100001)

for i in range(10000):
  t.runNextEvent()

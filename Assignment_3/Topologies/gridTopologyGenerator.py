#! /usr/bin/python
import sys


f = open(str(sys.argv[1]), "w")
N = int(sys.argv[2])

for i in range(N):
	for j in range (1,N+1):
		if i == 0:
			if j == 1: #first line
				f.write(' ' + str(i*N + j) + '  ' + str(i*N + j+1) + "  -40.0\n")
				#f.write(' ' + str(i*N + j) + '  ' + str(i*N + j+N) + "  -40.0\n")
			elif j == N:
				f.write(' ' + str(i*N + j) + '  ' + str(i*N + j-1) + "  -40.0\n")
				#f.write(' ' + str(i*N + j) + '  ' + str(i*N + j+N) + "  -40.0\n")
			else:
				f.write(' ' + str(i*N + j) + '  ' + str(i*N + j+1) + "  -40.0\n")
				f.write(' ' + str(i*N + j) + '  ' + str(i*N + j-1) + "  -40.0\n")
			f.write(' ' + str(i*N + j) + '  ' + str(i*N + j+N) + "  -40.0\n")
		elif i == N-1: # last line
			if j == 1:
				f.write(' ' + str(i*N + j) + '  ' + str(i*N + j+1) + "  -40.0\n")
				#f.write(' ' + str(i*N + j) + '  ' + str(i*N - N) + "  -40.0\n")
			elif j == N:
				f.write(' ' + str(i*N + j) + '  ' + str(i*N + j-1) + "  -40.0\n")
				#f.write(' ' + str(i*N + j) + '  ' + str(i*N - N) + "  -40.0\n")
			else:
				f.write(' ' + str(i*N + j) + '  ' + str(i*N + j+1) + "  -40.0\n")
				f.write(' ' + str(i*N + j) + '  ' + str(i*N + j-1) + "  -40.0\n")
			f.write(' ' + str(i*N + j) + '  ' + str(i*N +j-N) + "  -40.0\n")
		else: #indoor lines
			if j == 1:
				f.write(' ' + str(i*N + j) + '  ' + str(i*N + j+1) + "  -40.0\n")
				#f.write(' ' + str(i*N + j) + '  ' + str(i*N + j-1) + "  -40.0\n")
			elif j == N:
				f.write(' ' + str(i*N + j) + '  ' + str(i*N + j-1) + "  -40.0\n")
			else:
				f.write(' ' + str(i*N + j) + '  ' + str(i*N + j+1) + "  -40.0\n")
				f.write(' ' + str(i*N + j) + '  ' + str(i*N + j-1) + "  -40.0\n")
			f.write(' ' + str(i*N + j) + '  ' + str(i*N + j+N) + "  -40.0\n")
			f.write(' ' + str(i*N + j) + '  ' + str(i*N + j-N) + "  -40.0\n")

f.close()
all : cluster
CFLAGS = -g

cluster.o : cluster.c cluster.h
	cc -c $(CFLAGS) cluster.c

cluster : cluster.o
	cc -o cluster cluster.o

print :
	listing cluster.c cluster.h

clean :
	rm cluster.o cluster


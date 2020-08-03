all : back
CFLAGS = -g

probeer.o : probeer.c back.h
	cc -c $(CFLAGS) probeer.c

back.o : back.c back.h
	cc -c $(CFLAGS) back.c

back : back.o probeer.o
	cc -o back back.o probeer.o

print :
	listing back.c probeer.c back.h

clean :
	rm back.o probeer.o back


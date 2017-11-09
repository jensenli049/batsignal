all: batsignal.o
	gcc -o batsig batsignal.o

batsignal.o: batsignal.c batsignal.h
	gcc -c batsignal.c batsignal.h

clean:
	rm *.o
	rm *~
run:
	./batsig

all: sem_control.c
	gcc -o sem sem_control.c
run: all
	./sem
clean:
	rm sem
	rm *.o
	rm *~

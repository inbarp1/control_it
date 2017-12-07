all: sem_control.c
	gcc -o sem sem_control.c
run: all
	./sem -c 4
	./sem -v
	./sem -c 3
	./sem -v
	./sem -r
clean:
	rm sem -
	rm *.o
	rm *~

make: main.c readerwriter.c
	gcc -pthread main.c readerwriter.c -o rwmain
clean:
	rm ./rwmain

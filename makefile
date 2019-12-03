#Makefile for myArray project
default: main.o
	g++ -g build/main.o

main.o: src/main.cpp
	g++ -c -g src/main.cpp -o build/main.o

clean: 
	rm -f a.out build/*.o

backup:
	tar -cvf backup.tar src/*cpp include/*h makefile build README.md
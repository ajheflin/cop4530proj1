main: main.o
	g++ -o main.x main.o
	./main.x testfile
	rm main.x main.o
main.o: main.cpp
	g++ -c main.cpp
clean:
	rm main.x main.o

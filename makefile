main: main.o
	g++ -std=c++11 -o proj1.x main.o
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
clean:
	rm main.x main.o

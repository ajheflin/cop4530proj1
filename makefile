main: proj1.o
	g++ -std=c++11 -o proj1.x proj1.o
proj1.o: proj1.cpp
	g++ -std=c++11 -c proj1.cpp
clean:
	rm proj1.x proj1.o

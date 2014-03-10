all:
	g++ example/date-example.cpp -o date-example.o
	g++ example/example.cpp -o example.o
	g++ example/logging-example.cpp -o logging-example.o
	g++ example/map-example.cpp -o map-example.o
	g++ main.cpp lang/exception/throwable.cpp -o hello

test:
	
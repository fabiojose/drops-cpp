CXXFLAGS=-c -Wall
all:
	$(CXX) $(CXXFLAGS) example/example.cpp
	$(CXX) $(CXXFLAGS) example/date-example.cpp
	$(CXX) $(CXXFLAGS) example/logging-example.cpp
	$(CXX) $(CXXFLAGS) example/map-example.cpp
	
	g++ main.cpp lang/exception/throwable.cpp -o hello

test:
	
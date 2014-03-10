CXXFLAGS=-c -Wall -Wwrite-strings -Wreturn-type -Wsign-compare
all:
	#  example
	$(CXX) $(CXXFLAGS) example/example.cpp
	$(CXX) $(CXXFLAGS) example/date-example.cpp
	$(CXX) $(CXXFLAGS) example/logging-example.cpp
	$(CXX) $(CXXFLAGS) example/map-example.cpp
	$(CXX) $(CXXFLAGS) example/multicast-example.cpp
	$(CXX) $(CXXFLAGS) example/properties-example.cpp
	$(CXX) $(CXXFLAGS) example/tcpsock-example.cpp
	$(CXX) $(CXXFLAGS) example/thread-example.cpp
	
	#  io
	$(CXX) $(CXXFLAGS) io/input-stream.cpp
	$(CXX) $(CXXFLAGS) io/output-stream.cpp
	
	#  exception
	$(CXX) $(CXXFLAGS) lang/exception/exception-util.cpp
	$(CXX) $(CXXFLAGS) lang/exception/exceptions.cpp
	$(CXX) $(CXXFLAGS) lang/exception/throwable.cpp
	
	#  lang
	$(CXX) $(CXXFLAGS) lang/runnable.cpp
	$(CXX) $(CXXFLAGS) lang/string-util.cpp
	$(CXX) $(CXXFLAGS) lang/thread-util.cpp
	$(CXX) $(CXXFLAGS) lang/thread.cpp
	
	# main
	$(CXX) $(CXXFLAGS) main.cpp
	
	#  net
	$(CXX) $(CXXFLAGS) net/dpacket.cpp
	$(CXX) $(CXXFLAGS) net/dsocket.cpp
	$(CXX) $(CXXFLAGS) net/iaddress.cpp
	$(CXX) $(CXXFLAGS) net/msocket.cpp
	$(CXX) $(CXXFLAGS) net/socket-istream.cpp
	$(CXX) $(CXXFLAGS) net/socket-ostream.cpp
	$(CXX) $(CXXFLAGS) net/socket.cpp
	$(CXX) $(CXXFLAGS) net/tsocket.cpp
	
	#  text
	$(CXX) $(CXXFLAGS) text/data-format.cpp
	$(CXX) $(CXXFLAGS) text/format.cpp
	$(CXX) $(CXXFLAGS) text/level-format.cpp
	
	$(CXX) $(CXXFLAGS) util/date.cpp
	
	#  logging
	$(CXX) $(CXXFLAGS) util/logging/appender-factory.cpp
	$(CXX) $(CXXFLAGS) util/logging/appender.cpp
	$(CXX) $(CXXFLAGS) util/logging/console-appender.cpp
	$(CXX) $(CXXFLAGS) util/logging/file-appender.cpp
	$(CXX) $(CXXFLAGS) util/logging/formatter-factory.cpp
	$(CXX) $(CXXFLAGS) util/logging/formatter.cpp
	$(CXX) $(CXXFLAGS) util/logging/logger-factory.cpp
	$(CXX) $(CXXFLAGS) util/logging/logger.cpp
	$(CXX) $(CXXFLAGS) util/logging/simple-formatter.cpp
	
	$(CXX) $(CXXFLAGS) util/properties.cpp
	
	#g++ main.cpp lang/exception/throwable.cpp -o hello

test:
	
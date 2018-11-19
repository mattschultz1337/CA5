#
# Specifiy the target
all:	FlightDiscoverySystem

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
FlightDiscoverySystem:	FlightDiscoverySystem.o
	g++ FlightDiscoverySystem.o -o FlightDiscoverySystem

# Specify how the object files should be created from source files
FlightDiscoverySystem.o:	Date.cpp
	g++ -c Date.cpp FlightDiscoverySystem.cpp


# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o Date.exe

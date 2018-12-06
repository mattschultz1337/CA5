
#
# Specifiy the target
all:	FDS

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
FDS:	FlightDiscoverySystem.o
	g++ FlightDiscoverySystem.o -o FDS

# Specify how the object files should be created from source files
FlightDiscoverySystem.o:	Date.cpp
	g++ -c -g Date.cpp Flight.cpp FlightDiscoverySystem.cpp


# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o Date.exe

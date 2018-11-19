#
# Specifiy the target
all:	Date

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
Date:	Date.o
	g++ Date.o -o Date

# Specify how the object files should be created from source files
Date.o:	Date.cpp
	g++ -c Date.cpp


# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o Date.exe

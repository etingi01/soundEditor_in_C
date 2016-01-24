###############################################
# Makefile for compiling the program skeleton
# 'make'           build executable file 'PROJ'
# 'make doxy'   build project manual in doxygen
# 'make all'       build project + manual
# 'make clean'  removes all .o, executable and doxy log
###############################################
PROJ = as5   	 # the name of the project
CC   = gcc           	 # name of compiler 
DOXYGEN = doxygen        # name of doxygen binary

# define any compile-time flags
CFLAGS = -std=c99 -Wall -O -Wuninitialized -Wunreachable-code -pedantic #-DDEBUG=1
LFLAGS = -lm                                            

###############################################
# You don't need to edit anything below this line
###############################################

# list of object files 
# The following includes all of them!
C_FILES := $(wildcard *.c)
OBJS := $(patsubst %.c, %.o, $(C_FILES)) 

# To create the executable file  we need the individual
# object files 
$(PROJ): $(OBJS)
	$(CC) $(LFLAGS) -o $(PROJ) $(OBJS)

# To create each individual object file we need to 
# compile these files using the following general
# purpose macro
.c.o:
	$(CC) $(CFLAGS)  -c $< 
 
# To make all (program + manual) "make all"      
all : 	
	make
	make doxy

# To make all (program + manual) "make doxy"      
doxy:
	$(DOXYGEN) as3_1.conf
	
# To clean .o files: "make clean"
clean:
	rm -rf *.o html

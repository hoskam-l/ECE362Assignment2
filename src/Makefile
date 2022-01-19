# ECE362
# Assignment 2 Problem 2
# Dr. Schubert
# by luke hoskam
# Makefile for Assignment 2

##Required Targest for Assignment 2
# log:  compile the log program
# logtest: test the log program
# header: compile the header program
# headertest: test the header program
# all: compile and test both programs

# Compiler settings
CC = gcc 
CXXFLAGS = -std=c99 -Wall
TESTFLAGS = output.log -3
VPATH = SRC INCLUDE 
#    .---------- constant part!
#    vvvv vvvv-- the code from above
RED='\033[0;31m'
NC='\033[0m' # No Color
CYAN='\033[0;36m'



APPNAME1 = log
APPNAME2 = header

log: log.o
	$(CC) $(CXXFLAGS) -o $@ $^ 

log.o: log.c
	$(CC) $(CXXFLAGS) -c $<

logtest: log
	./log < loginput1.txt
	./log < loginput2.txt
	./log < loginput3.txt
	cat output.log

header: header.o
	$(CC) $(CXXFLAGS) -o $@ $^ 

header.o: header.c 
	$(CC) $(CXXFLAGS) -c $<

headertest: header
	./header < headerinput1.txt
	./header -12 < headerinput2.txt
	./header -10 < headerinput3.txt
	./header -15 headerinput3.txt

all : clean clearscr help logtest headertest 

help: 
	@echo 
	@echo
	@echo -e ${CYAN}Usage: log 
	@echo text 
	@echo -e ctrl+d${NC}
	@echo
	@echo When using log, input text and then press enter, 
	@echo the text will echo on the screen after each line.
	@echo When done, use ctrl+d to end the input.
	@echo
	@echo
	@echo -e ${CYAN}Usage: header filename -n ${NC}
	@echo -e where ${RED}filename${NC} is the name of the file
	@echo -e and ${RED}-n${NC}is the number of lines to read.
	@echo
	@echo -e When using header, use the two arguments ${RED}filename${NC} and ${RED}n${NC}
	@echo -e where and ${RED}n${NC} is the number of lines to read from the file
	@echo
	@echo -e If no ${RED}filename${NC} is entered the program will take input
	@echo -e from STDIN for ${RED}n${NC} lines.
	@echo
	@echo -e If ${RED}n${NC} is not entered, the program will read just 1 line.
	@echo


clean: 
	rm -f *.o *.exe log output.log header 

clearscr: 
	clear


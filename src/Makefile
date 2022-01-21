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
TESTLOG1 = < loginput1.txt
TESTLOG2 = < loginput2.txt
TESTLOG3 = < loginput3.txt
TESTHEADER1 = < headerinput1.txt
TESTHEADER2 = -12 < headerinput2.txt
TESTHEADER3 = -10 < headerinput3.txt
TESTHEADER4 = -16 headerinput3.txt
VPATH = SRC INCLUDE 

RED='\033[0;31m'
NC='\033[0m' # No Color
CYAN='\033[0;36m'



APPNAME1 = log
APPNAME2 = header

$(APPNAME1): log.o
	$(CC) $(CXXFLAGS) -o $@ $^ 

log.o: log.c
	$(CC) $(CXXFLAGS) -c $<

logtest: log
	@echo -e                        ${RED}added three empty lines for clarity${NC}
	@echo 
	@echo 
	./log $(TESTLOG1)
	./log $(TESTLOG2)
	./log $(TESTLOG3)
	@echo -e                        ${RED}added three empty lines for clarity${NC}
	@echo 
	@echo 
	cat output.log
	@echo -e                        ${RED}added three empty lines for clarity${NC}
	@echo 
	@echo 

$(APPNAME2): header.o
	$(CC) $(CXXFLAGS) -o $@ $^ 

header.o: header.c 
	$(CC) $(CXXFLAGS) -c $<

headertest: header
	@echo -e                        ${RED}added three empty lines for clarity${NC}
	@echo 
	@echo 
	./header $(TESTHEADER1)
	./header $(TESTHEADER2)
	./header $(TESTHEADER3)
	./header $(TESTHEADER4)
	@echo -e                        ${RED}added three empty lines for clarity${NC}
	@echo 
	@echo 

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


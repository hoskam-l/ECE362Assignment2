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
	./header -5 < headerinput2.txt
	./header -10 < headerinput3.txt
	./header -15 headerinput3.txt

all : clean clearscr logtest headertest 

clean: 
	rm -f *.o *.exe log output.log header 

clearscr: 
	clear


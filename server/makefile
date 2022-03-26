# Makefile for raysecur websocket++ assignment

#############################################
# Variables to control MakeFile operation

CC = g++
CVERSION = -std=c++11
WEBSOCKETPP = -I ../websocketpp
ASIO = -I ../asio-1.22.1/include
CFLAGS = $(CVERSION) $(WEBSOCKETPP) $(ASIO)

#############################################
# Targets

server.exe: serverMain.o
	$(CC) $(CFLAGS) -o server.exe serverMain.o

serverMain.o: serverMain.cpp
	$(CC) $(CFLAGS) -c serverMain.cpp

clean:
	rm server.exe serverMain.o


# Makefile for raysecur websocket++ assignment

#############################################
# Variables to control MakeFile operation

CC = g++
CVERSION = -std=c++11
WEBSOCKETPP = -I ../websocketpp
ASIO = -I ../asio-1.22.1/include
JSON = -I ../json/include
CFLAGS = $(CVERSION) $(WEBSOCKETPP) $(ASIO) $(JSON) -pthread

#############################################
# Targets

server.exe: ServerMain.o AddSubServer.o
	$(CC) $(CFLAGS) -o server.exe ServerMain.o AddSubServer.o

ServerMain.o: ServerMain.cpp CommonTypes.hpp
	$(CC) $(CFLAGS) -c ServerMain.cpp

AddSubServer.o: AddSubServer.cpp AddSubServer.hpp CommonTypes.hpp
	$(CC) $(CFLAGS) -c AddSubServer.cpp

clean:
	rm server.exe ServerMain.o AddSubServer.o


all: server

server: server.o
		c++ -o server server.o SynchronizationImpl.o Synchronization.o -lIce -lIceUtil -lpthread 
server.o: server.cpp
		c++ -I. -c server.cpp SynchronizationImpl.cpp Synchronization.cpp
clean:
		rm server *.o

all: server

server: server.o
		c++ -o server server.o SynchronizationImpl.o Synchronization.o Tree.o -lIce -lIceUtil -lpthread 
server.o: server.cpp
		c++ -I. -c server.cpp SynchronizationImpl.cpp Synchronization.cpp Tree.cpp
clean:
		rm server *.o

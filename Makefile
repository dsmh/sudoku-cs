CC=g++
ZMQ=/home/utp/zmq
ZMQ_LIB=$(ZMQ)/lib
ZMQ_HDR=$(ZMQ)/include

all: sudoku-server sudoku-client

sudoku-server: servidorSudoku.cc
	$(CC) -I$(ZMQ_HDR) -L$(ZMQ_LIB) -std=c++11 -o sudoku-server servidorSudoku.cc -lzmq -fpermissive

sudoku-client: sudoku_client.cc
	$(CC) -I$(ZMQ_HDR) -L$(ZMQ_LIB) -std=c++11 -o sudoku-client sudoku_client.cc -lzmq -fpermissive

clean:
	rm -f sudoku-server sudoku-client *~

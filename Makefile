CC=g++
ZMQ=/home/utp/zmq
ZMQ_LIB=$(ZMQ)/lib
ZMQ_HDR=$(ZMQ)/include

all: sudokuServer sudokuClient

sudokuServer: servidorSudoku.cc
	$(CC) -I$(ZMQ_HDR) -L$(ZMQ_LIB) -o sudokuServer servidorSudoku.cc -lzmq
	
sudokuClient: sudoku_client.cc
	$(CC) -I$(ZMQ_HDR) -L$(ZMQ_LIB) -o sudokuClient sudoku_client.cc -lzmq
	
clean:
	rm -f sudokuServer sudokuClient *~

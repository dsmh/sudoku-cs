CC=g++
ZMQ=/home/utp/zmq
ZMQ_LIB=$(ZMQ)/lib
ZMQ_HDR=$(ZMQ)/include
all: sudoku-server sudoku-client

sudoku-server: servidorSudoku.cc
	$(CC) -I$(ZMQ_HDR) -L$(ZMQ_LIB) -o sudoku-server servidorSudoku.cc -lzmq

sudoku-client: sudoku_client.cc
	$(CC) -I$(ZMQ_HDR) -L$(ZMQ_LIB) -o sudoku-client sudoku_client.cc -lzmq

clean:
	rm -f sudoku-server sudoku-client *~
=======
all: sudokuServer sudokuClient

sudokuServer: servidorSudoku.cc
	$(CC) -I$(ZMQ_HDR) -L$(ZMQ_LIB) -o sudokuServer servidorSudoku.cc -lzmq
	
sudokuClient: sudoku_client.cc
	$(CC) -I$(ZMQ_HDR) -L$(ZMQ_LIB) -o sudokuClient sudoku_client.cc -lzmq
	
clean:
	rm -f sudokuServer sudokuClient *~

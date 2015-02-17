#!/bin/bash
g++ -I/home/dsm/zmq/include -L/home/dsm/zmq/lib -o servidor servidorSudoku.cc -lzmq
g++ -I/home/dsm/zmq/include -L/home/dsm/zmq/lib -o cliente sudoku_client.cc -lzmq


//  Hacer un Servidor para jugar sudoku "Fil;Col;val;id"
//TO DO: Validar, Hashtable for id score. 
// Linea de compilación: g++ -I/home/utp/zmq/include -L/home/utp/zmq/lib -o server servidorSudoku.cc -lzmq


#include <zmq.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <iostream>


using namespace std;

/** Check whether grid[i][j] is valid in the grid */
bool isValid(int grid[][9])
{
	cout << "epa";
	int i, j;
	bool status;
	status = true;
	
	for (int column = 0; column < 9; column++)
		if (column != j && grid[i] [column] == grid[i] [j])
			status = false;
	for (int row = 0; row < 9; row++)
		if (row != i && grid[row] [j] == grid[i] [j])
			status = false;
	
	for (int row = (i / 3) * 3; row < (i / 3) * 3 + 3; row++)
		for (int col = (j / 3) * 3; col < (j / 3) * 3 + 3; col++)
			if (row != i && col != j && grid[row] [col] == grid[i] [j])
				status = false;
	
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (grid[i][j] != 0)
				status = false;
	
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if ((grid[i][j] < 0) || (grid[i][j] > 9))
				status = false;
	return status;
}



void inicializarSudoku(int matrix[9][9])
{
	int i,j;
	for (i=0; i<9; i++)
	{
		for(j=0;j<9;j++)
		{
			matrix[i][j]=0;
		}
	}
	matrix[0][2]=4;
	matrix[0][3]=3;
	matrix[0][8]=6;
	matrix[1][0]=6;
	matrix[1][3]=1;
	matrix[1][5]=9;
	matrix[2][0]=7;
	matrix[2][7]=4;
	matrix[2][8]=9;
	matrix[3][2]=1;
	matrix[3][4]=8;
	matrix[3][5]=5;
	matrix[3][6]=4;
	matrix[3][7]=6;
	matrix[4][2]=6;
	matrix[4][3]=2;
	matrix[4][4]=9;
	matrix[4][5]=3;
	matrix[4][6]=7;
	matrix[5][1]=7;
	matrix[5][2]=5;
	matrix[5][3]=4;
	matrix[5][4]=1;
	matrix[5][6]=9;
	matrix[6][0]=4;
	matrix[6][1]=6;
	matrix[6][8]=7;
	matrix[7][3]=9;
	matrix[7][5]=4;
	matrix[7][8]=1;
	matrix[8][0]=2;
	matrix[8][5]=7;
	matrix[8][6]=8;	
}

void burn_play(int matrix[9][9],int row, int column,int value)
	{
		matrix[row][column] = value;
	}



//Se debe devolver un String con la matriz impresa y enviar ese String al cliente.
void mostrar_sudoku(int matrix[9][9])
	{
		int i;
		int j;
		printf("                            ---------------------\n");
		for (i = 0; i < 9; i++)
		{
			printf("                            | ");
			for (j = 0; j < 9; j++)
			{
				printf("%d ",matrix[i][j]);
			}
			printf("|\n");
			/* code */
		}
		printf("                            ---------------------\n\n");
	}


///matriz[fila][col]
///


int main (void)
{
	int matriz[9][9];
	inicializarSudoku(matriz);
	//cout << matriz[0][0] << endl;
	
	
    //  Socket to talk to clients
    void *context = zmq_ctx_new ();
    void *responder = zmq_socket (context, ZMQ_REP); //LA CONSTANTE ES PARA RESPONDER SOLICITUDES
    int rc = zmq_bind (responder, "tcp://*:5555"); //*-> INTERFAZ DE RED POR DEFECTO
    assert (rc == 0);
    
	char id[50] = "";
	int fila=0;
	int col=0;
	int valor;
	int score=0;
	int temp= 0;
    while (1) {
		
        char buffer [100];
        printf(".............:::::::::::::::SUDOKU SERVER ONLINE:::::::::::::::............. \n");
		mostrar_sudoku(matriz);
        zmq_recv (responder, buffer, 100, 0);
        //printf ("%s\n",buffer);
      
        ///printf ("%s\n",op);
     
        ////JUGADA
		sscanf(buffer,"%d;%d;%d;%s", &fila,&col,&valor,&id);
		printf("fila: %d\n",fila);
		printf("columna: %d\n",col);
		printf("valor: %d\n",valor);
		//Se Almacena el valor que tiene la celda, antes de ser asignada. Para retroceder movimientos invalidos.
		//temp=(long)matriz[fila,col]; ////C se complica
		burn_play(matriz,fila,col,valor);
		if  (!isValid(matriz)) 
			{
				cout << "Invalid input" << endl;
				burn_play(matriz,fila,col,0);
			}
		//cout << isValid(matriz);
		//sleep (5);          //  Do some 'work'
		mostrar_sudoku(matriz);
        zmq_send (responder, "done", 100, 0);
		//cout << fila << endl;
		//cout << col << endl;
		//cout << valor << endl;
		
    }
        
    return 0;
}

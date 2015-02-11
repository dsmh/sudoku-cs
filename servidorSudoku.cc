//  Hacer un Servidor que procese operaciones aritmeticas en el formato "OP;n1;n2"

#include <zmq.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>



/** Check whether grid[i][j] is valid in the grid */
bool isValid(int grid[] [9])
{
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















int main (void)
{
    //  Socket to talk to clients
    void *context = zmq_ctx_new ();
    void *responder = zmq_socket (context, ZMQ_REP); //LA CONSTANTE ES PARA RESPONDER SOLICITUDES
    int rc = zmq_bind (responder, "tcp://*:5555"); //*-> INTERFAZ DE RED POR DEFECTO
    assert (rc == 0);
    
	char n1[50] = "";
	char n2[50]= "";
	char op[1]="";
	int num1=0;
	int num2=0;
	int R=0;
	float re=0.0;
	char resultado[100]="";	
    while (1) {
        char buffer [101];
        printf("True \n");
        zmq_recv (responder, buffer, 101, 0);
        printf ("%s\n",buffer);
        /////////////
        op[0]=buffer[0];
        printf ("%s\n",op);
     
        ////OPERACION SUMA
		sscanf(buffer,"%c;%d;%d", &op,&num1,&num2);
		if(op[0] == '+')
		{
			R=num1+num2;
			sprintf(resultado,"%d",R);
		}
		////OPERACION RESTA
		if(op[0] == '-')
		{
			R=num1-num2;
			sprintf(resultado,"%d",R);
		}
		
		////OPERACION MULTIPLICACION
		if(op[0] == '*')
		{
			R=num1*num2;
			sprintf(resultado,"%d",R);
		}
		
		////OPERACION DIVISION
		if(op[0] == '/')
		{
			re=num1/(float)num2;
			sprintf(resultado,"%f",re);
			printf("%f\n",re);
		}
			
        //printf ("Received Hello\n");
        //sleep (5);          //  Do some 'work'
        
        zmq_send (responder, resultado, 100, 0);
    }
    return 0;
}

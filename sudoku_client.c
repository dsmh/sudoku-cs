
#include <zmq.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main (void)
{
    printf ("Connecting to hello world server...\n");
    //crea un nuevo contexto permitiendo un espacio para establecer 
    //diferetnes tipos de comportamientos q se pueden modificar utilizadno.
    //la funcion context_set y obtener por medio de context_get.
    void *context = zmq_ctx_new(); 

    //inicializa un nuevo socket otorgando un roll y usando el contexto debido a este tiene la informacion de los puertos y la configuracion 
    void *requester = zmq_socket (context, ZMQ_REQ);
    //soliita la conexion a la direccion esta puede ser ipv6 o ipv4 si se configura el contexto para esto.
    zmq_connect (requester, "tcp://localhost:5555");

    //char *s; 
    //scanf("ingrese mensaje: %s",s); 
    


    char *s = "0;0;gabriel;1";
    //char s[] = "11s";    
    int tam = strlen(s);
    char buffer [20];
    //int i = 0;
    
    /*for (i = 0; i<tam; i++)
        {
            printf ("Sending: %c",s[i]); 
        }*/
    
    //envia un mensaje a el servidor por medio de nuestro socket
    zmq_send (requester, s, tam, 0);
    //recibe un mensaje del servidor 
    zmq_recv (requester, buffer, 10, 0);
    printf ("Received: %s\n",buffer);
    
    //cierra la conexion de un puerto  y hace q todas la operaciones devuelvan ERRONO. 
    zmq_close (requester);
    //// por destroy y no term destrulle el contexto y libera recursos.
    zmq_ctx_destroy(context);
    return 0;
}

/*
Escriba un programa que cree un proceso hijo y entonces en el proceso hijo cierre
la salida estandar (STDOUT FILENO). 
¿Qué pasa si el hijo llama printf() para imprimir alguna salida después de cerrar el descriptor?
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main() {

     if (fork()== 0){ 
        close(STDOUT_FILENO);
        printf("Soy el pela'o ");
        
   }else{ 
        printf("Soy el papu \n"); 
    } 
    return 0;
}
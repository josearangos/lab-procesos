/*
 *  Escriba ahora un programa que use wait() para esperar que el proceso hijo finalice su ejecución.
 *  ¿Cuál es el valor de retorno de la función wait()?, ¿Qué pasa si usted usa la función wait en el hijo?
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {


   if (fork()== 0){ 
        for (int i = 0; i < 5; i++){ 
            sleep(1);
            printf("Ejecutando el hijo => %d",i);
            printf("\n");
        }
   }else
    { 
        printf("llego el Papa \n"); 
        wait(NULL); 
        printf("El pela'o termino\n"); 
    } 
  
    printf("Chao\n"); 
    return 0; 
}
#include <stdio.h>
#include <unistd.h>

/*
gcc -Wall example1.c -o example1.out

-> sleep
-> getpid

*/


int main (void){

  int x = 100;

  char rol;
  printf("Empezando proceso %d\n", getpid());  

  if(fork() == 0) {
     // Codigo hijo
     rol = 'H';
     printf("Empezando proceso Hijo %d\n", getpid()); 
     x  = x +1;
     sleep(1);
     printf("%c -> x = %d\n",rol ,x);
     
   }
   else {
     // Codigo padre
    rol = 'P';
    printf("Empezando proceso Padre %d\n", getpid()); 
    x =x +1;
    sleep(1);
    printf("%c -> x = %d\n",rol ,x);
     
   }


  return 0;
}


/*

* ¿Cuál es el valor de la variable en el proceso hijo?

Carga el valor original de la variable ya que es el primero en ser ejecutado, para este caso la variable X es igual a 100.

 ¿Qué sucede con la variable cuando el proceso hijo y el padre cambian el valor de ```x```?

Ambos tiene el mismo valor dado que al cargarse en memoria ambos conservan el mismo valor de la variables x, lo unico que difiere es el orden de ejecución de los procesos, padre e hijo


*/

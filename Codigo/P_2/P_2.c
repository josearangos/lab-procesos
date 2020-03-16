#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>


int main (void){
  int fd= open("archivo.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
  int sz;
  char rol;
  printf("Empezando proceso %d\n", getpid());  
  if(fork() == 0) {
     // Codigo hijo
     rol = 'H';
     printf("Empezando proceso %d\n", getpid()); 
       sleep(1);
       sz =write(fd,"Hijo escribe\n", strlen("Hijo escribe\n"));
       printf("%c\n",rol );

   }
   else {
     // Codigo padre
     rol = 'P';
       sleep(1);
       sz =write(fd,"Padre escribe\n", strlen("Padre escribe\n"));
       printf("%c\n",rol );
 
   }
   // Codijo ejecutado por ambos (para el caso)
   printf("%d\n",sz);
   close(fd);
   return 0;
}
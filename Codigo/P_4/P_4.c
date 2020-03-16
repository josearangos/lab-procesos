#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


int main (void){
  char rol;
  printf("Empezando proceso %d\n", getpid());  
  if(fork() == 0) {
     // Codigo hijo
     rol = 'H';
     printf("Empezando proceso %d\n", getpid()); 
     sleep(1);
     printf("%c\n",rol );
     execlp("/bin/sh","/bin/sh", "-c", "ls -l /bin/??", (char *)NULL);
	 printf ("Si ves esto, no se pudo ejecutar programa\n");
	 exit(1);
 
     

   }
   else {
     // Codigo padre
     rol = 'P';
       sleep(1);
       printf("%c\n",rol );
       int tonta;
	   wait(&tonta);     
 
   }
   // Codijo ejecutado por ambos (para el caso)
   return 0;
}
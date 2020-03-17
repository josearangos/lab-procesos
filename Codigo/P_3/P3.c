/*
Escriba un programa usando fork(). El proceso hijo imprimirá "Hello"; 
el proceso padre imprimirá "goodbye". Usted deberá asegurar que el proceso 
hijo imprima en primer lugar; ¿usted podría hacer esto sin llamar wait() en el padre?

*/

#include <stdio.h>
#include <unistd.h>

int main()
{
    int estado;

    if (fork() == 0){
        printf("Hijo: Hello %d\n", getpid());
    }
    else{
        sleep(1);
        printf("Padre: Goodbye %d\n", getpid()); 
    }

    return 0;
}

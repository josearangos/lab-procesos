# PRÁCTICA 1 - PROCESOS #

## 1. Objetivos ##
1. Familiarizarse con las diferentes estructuras y funciones relacionadas con el manejo de procesos en linux.
2. Codificar programas que hagan uso del API de procesos.

## 2. Actividades en el laboratorio ##

Realizar los siguientes ejercicios:

1. Escriba un programa que llame un ```fork()```. Antes del llamado del ```fork()```, declare una variable de acceso (por ejemplo, ```x```) y asígnele un valor (por ejemplo, ```100```). Responda las siguientes preguntas:
  * ¿Cuál es el valor de la variable en el proceso hijo?
  * ¿Qué sucede con la variable cuando el proceso hijo y el padre cambian el valor de ```x```?
2. Escriba un programa que abra un archivo (con la llamada ```open()```) y entonces llame a ```fork()```. **Nota**: El siguiente [enlace](https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/) puede ser de utilidad para entender la llamada ```open()```.
  * ¿Pueden el padre y el hijo acceder al file descriptor retornado por ```open()```? 

    Si, ambos padre he hijo pueden acceder al descriptor obtenido por el Open() la archivo, y el open por su parte verifica si el archivo esta creado, si no el mismo lo crea.

  * ¿Qué pasa si ellos empiezan a escribir el archivo de manera concurrente, es decir, a la misma vez?

    Teoricamente esto no pasa, ya que padre e hijo son dos procesos, los cuales existen en contextos diferentes si se ejecutan en momentos diferentes. Aunque parescan ejecutarsen al mimo tiempo, esto se  debe a la ilusion de tiempo compartido en el que  parece que los dos se esten ejecutando al mismo tiempo. En conclusión no pueden acceder al archivo de forma concurrente, si no que se turnan segun su ejecución para acceder a el.
    

3. Escriba un programa usando ```fork()```. El proceso hijo imprimirá ```"Hello"```; el proceso padre imprimirá ```"goodbye"```. Usted deberá asegurar que el proceso hijo imprima en primer lugar; ¿usted podría hacer esto sin llamar ```wait()``` en el padre? 
4. Escriba un programa que llame ```fork()``` y entonces llame alguna forma de ```exec()``` para correr el programa ```/bin/ls```. Intente probar todas las variaciones de la familia de funciones ```exec()``` incluyendo (en linux) ```execl()```, ```execle()```, ```execlp()```, ```execv()```, ```execvp()``` y ```execvpe()```. 

¿Por qué piensa usted que existen tantas variaciones para la misma llamada básica?

Por que cada una permite omitir o especificar los parametros de forma distinta como lo son: el nombre del fichero a ser ejecutado, puntero al vector de argumentos y puntero al vector de ambiente.

* int execl(char const *path, char const *arg0, ...);
* int execle(char const *path, char const *arg0, ..., char const *envp[]);
* int execlp(char const *file, char const *arg0, ...);
* int execv(char const *path, char const *argv[]);
* int execve(char const *path, char const *argv[], char const *envp[]);
* int execvp(char const *file, char const *argv[]);

l - Los argumentos de la línea de comandos se pasan individualmente (una lista) a la función.
v - Los argumentos de la línea de comandos se pasan a la función como una matriz (vector) de punteros.
e - Se pasa explícitamente una matriz de punteros a variables de entorno a la nueva imagen de proceso.
p: utiliza la variable de entorno PATH para buscar el archivo nombrado en el argumento de ruta a ejecutar.


5. Escriba ahora un programa que use ```wait()``` para esperar que el proceso hijo finalice su ejecución. ¿Cuál es el valor de retorno de la función ```wait()```?, ¿Qué pasa si usted usa la función ```wait``` en el hijo?
6. Haga un programa, como el del ejercicio anterior, con una breve modificación, la cual consiste en usar ```waitpid()``` en lugar de ```wait()```.

 ¿Cuándo podría ser ```waitpid()``` útil?

 El proceso waitpid() permite verificar el estado de los procesos hijos y a diferencia del proceso wait este puede verificar el estado del proceso y tomar una desición a partir de este, la descripcion literal de este proceso es similar a la del wait:

       La  función  waitpid  suspende  la  ejecución  del  proceso  en  curso  hasta  que un hijo
       especificado por el argumento pid ha terminado, o hasta que  se  produce  una  señal  cuya
       acción es finalizar el proceso actual o llamar a la función manejadora de la señal.

Lo unico diferente, es que este puede tomar decisiones sin tener que esperar la finalización del proceso hijo.

7. Escriba un programa que cree un proceso hijo y entonces en el proceso hijo cierre la salida estandar (```STDOUT FILENO```). ¿Qué pasa si el hijo llama ```printf()``` para imprimir alguna salida después de cerrar el descriptor?
8. Escriba un programa que cree dos hijos y conecte la salida estándar de un hijo a la entrada estándar del otro usando la llamada a sistema ```pipe()```

## 3. Entregable ##

Los entregables para esta practica incluiran:
1. Codigo de los ejercicos propuestos.
2. Solución a las preguntas planteadas. apoyar la explicación con graficas donde lo vea necesario.

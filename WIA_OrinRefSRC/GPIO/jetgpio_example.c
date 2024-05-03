/* Usage example of the JETGPIO library
 * Compile with: gcc -Wall -o jetgpio_example jetgpio_example.c -ljetgpio
 * Execute with: sudo ./jetgpio_example
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <jetgpio.h>

int main(int argc, char *argv[])
{
int Init;

Init = gpioInitialise();
if (Init < 0)
{
   /* jetgpio initialisation failed */
   printf("Jetgpio initialisation failed. Error code:  %d\n", Init);
   exit(Init);
}
else
{
   /* jetgpio initialised okay*/
   printf("Jetgpio initialisation OK. Return code:  %d\n", Init);
}	

// Setting up pin 3 as OUTPUT and 7 as INPUT

int stat1 = gpioSetMode(3, JET_OUTPUT);
if (stat1 < 0)
{
   /* gpio setting up failed */
   printf("gpio setting up failed. Error code:  %d\n", stat1);
   exit(Init);
}
else
{
   /* gpio setting up okay*/
   printf("gpio setting up okay. Return code:  %d\n", stat1);
}

stat1 = gpioSetMode(15, JET_OUTPUT);
if (stat1 < 0)
{
   /* gpio setting up failed */
   printf("gpio setting up failed. Error code:  %d\n", stat1);
   exit(Init);
}
else
{
   /* gpio setting up okay*/
   printf("gpio setting up okay. Return code:  %d\n", stat1);
}

int stat2 = gpioSetMode(7, JET_INPUT);
if (stat2 < 0)
{
   /* gpio setting up failed */
   printf("gpio setting up failed. Error code:  %d\n", stat2);
   exit(Init);
}
else
{
   /* gpio setting up okay*/
   printf("gpio setting up okay. Return code:  %d\n", stat2);
}

// Writing 1 and 0 to pin 3 a 1 second intervals while reading pin 7
 
int x =0;
int level = 0;
    while (x<50000) {
        gpioWrite(3, 1);
        gpioWrite(15, 1);
        usleep(100);
        level = gpioRead(7);
        printf("level[1]: %d\n",level);
        usleep(10000);
        gpioWrite(3, 0);
        gpioWrite(15, 0);
        usleep(100);
        level = gpioRead(7);
        printf("level[0]: %d\n",level);
        usleep(10000);
		x++;
    }

// Terminating library 
gpioTerminate();

exit(0);
	
}

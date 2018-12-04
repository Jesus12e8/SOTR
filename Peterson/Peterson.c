#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define N  2 

int FALSE = 0;
int TRUE = 1;

int turn;
int interested[N];

void enter_region(int process){
	int other;
	other=1-process;
	interested[process]=TRUE;
	turn=process;
	while((turn==process)&&(interested[other]==TRUE));
}

void leave_region(int process){
	interested[process]==FALSE;
}

void ProcesoA (){
	while (1){
		printf ("Proceso A en la secion no critica\n");
		enter_region(0);
		printf ("Proceso A en la secion critica\n");
		leave_region(0);
}
}

void ProcesoB (){
	while (1){
		printf ("Proceso B en la secion no critica\n");
		enter_region(1);
		printf ("Proceso B en la secion critica\n");
		leave_region(1);
}
}

int main (void){
	int i = 0;
	pthread_t ProsA, ProsB;
	pthread_create( &ProsA,NULL,(void*)ProcesoA,NULL);
	pthread_create( &ProsB,NULL,(void*)ProcesoB,NULL);
	while (1)
		i=i;

	return EXIT_SUCCESS;
}

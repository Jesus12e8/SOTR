#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define N  2 

int FALSE = 0;
int TRUE = 1;
int G=0;

int turn;
int interested[N];

int sA = 0;
int sB = 0;

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

void ProcesoA (int *G){
	int i=0;
	while (i<10){
		i=i+1;
		printf ("Proceso A en la secion no critica\n");
		sleep(1);
		enter_region(0);
		printf ("Proceso A en la secion critica\n");
		*G=*G+1;
		sleep(1);
		leave_region(0);
}
	sA=1;
}

void ProcesoB (int *G){
	int i=0;
	while (i<10){
		i=i+1;
		printf ("Proceso B en la secion no critica\n");
		sleep(1);
		enter_region(1);
		printf ("Proceso B en la secion critica\n");
		*G=*G+1;
		sleep(1);
		leave_region(1);
}
	sB=1;
}

int main (void){
	pthread_t ProsA, ProsB;
	pthread_create( &ProsA,NULL,(void*)ProcesoA,(void*)&G);
	pthread_create( &ProsB,NULL,(void*)ProcesoB,(void*)&G);
	while (1){
		if (sA && sB){
			printf ("el valor de G = %d\n",G);
			break;}}

	return EXIT_SUCCESS;
}


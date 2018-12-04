#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int wantA = 0;
int wantB = 0;
int turno = 1;
int Comp = 0;
int sA = 0;
int sB = 0;

void ProcesoA (int *Compa){
	int i = 0;
	while (i<10){
		printf ("Proceso A en la secion no critica\n");
		i++;
		sleep (1);
		wantA=1;
		while (wantB){
			if (turno == 2){
				wantA=0;
				while (!(turno==1));
				wantA=1;
}
}
	printf ("Proceso A en la secion critica\n");
	*Compa = *Compa + 1;
	sleep (1);
	turno = 2;
	wantA=0;
}
	sA = 1;
}

void ProcesoB (int *Compa){
	int i = 0;
	while (i<10){
		printf ("Proceso B en la secion no critica\n");
		i++;
		sleep (1);
		wantB=1;
		while (wantA){
			if (turno == 1){
				wantB=0;
				while (!(turno==2));
				wantB=1;
}
}
	printf ("Proceso B en la secion critica\n");
	*Compa = *Compa + 1;
	sleep (1);
	turno = 1;
	wantB=0;
}
	sB = 1;
}

int main (void){
	pthread_t ProsA, ProsB;
	pthread_create( &ProsA,NULL,(void*)ProcesoA,(void*)&Comp);
	pthread_create( &ProsB,NULL,(void*)ProcesoB,(void*)&Comp);
	while (1){
		if (sA && sB){
			printf ("el valor de N = %d\n",Comp);
			break;}}

	return EXIT_SUCCESS;
}

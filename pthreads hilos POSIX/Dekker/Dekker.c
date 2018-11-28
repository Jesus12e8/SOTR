#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int wantA = 0;
int wantB = 0;
int turno = 1;

void ProcesoA (){
	while (1){
		printf ("Proceso A en la secion no critica\n");
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
	sleep (1);
	turno = 2;
	wantA=0;
}
}

void ProcesoB (){
	while (1){
		printf ("Proceso B en la secion no critica\n");
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
	sleep (1);
	turno = 1;
	wantB=0;
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
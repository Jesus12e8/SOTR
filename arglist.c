#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
  printf("El nombre de este programa es '%s'.\n",argv[0]);
  printf("Este programa fue invocado con %d argumentos.\n",argc);

  if(argc>1){
    int i;
    i=atoi (argv[1]);
    printf ("i=%d\n",i);
    printf("Los argumentos son:\n");
    for(i=1;i<argc;++i){
      printf(" %s\n",argv[i]);
    }
  }
  
  return 0;
}

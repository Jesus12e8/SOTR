#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define R 0
#define W 1

#define TRUE	1
#define FALSE	0
#define PERIOD	'.'


int main( )
{

	int pid;
	int p[2], q[2];

	FILE *fdopen (), *fp;
	
	int c;
	int newline = TRUE;

	int total;

		pipe(p);
		pipe(q);

	switch (pid = fork()) {

		case 0:
			close(p[W]);

			close(R); dup(p[R]); close(p[R]);
			close(q[R]);
			close(W); dup(q[W]); close(q[W]);
				
			execl("/a1/nhg/acb/count","count", 0);
			printf("textcount: exec failed");
			exit(1);
		case -1:
			printf("textcount: cannot fork a process");
			exit(1);
		default:
			close(p[R]); close(q[W]);
			fp = fdopen(p[W],"w");

		}
	while ((c = getchar())!= EOF) {
		switch (newline) {
			case TRUE:
				if (c == '\n')
					putc(c, fp);
				else if (c == PERIOD)
					while ((c=getchar())!=EOF&&c!='\n')
						;
				else {
					putc(c, fp);
					newline = FALSE;
				}
				break;
			default:
				putc(c, fp);
				if (c == '\n')
					newline = TRUE;
		}
	}	

	fclose(fp);
	close(R); dup(q[R]); close(q[R]);

	scanf("%d", &total);
	printf("Total number of characters %d\n" , total);
	
	exit (0);
}

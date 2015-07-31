#include <stdio.h>
#include <CSTsurveying.h>

void CSTbyteOrderSwapWord (void *data) {
	char ch;
	ch =  ((char *) data) [0];		((char *) data) [0] =  ((char *) data) [3];  ((char *) data) [3] = ch;
	ch =  ((char *) data) [1]; 	((char *) data) [1] =  ((char *) data) [2];  ((char *) data) [2] = ch;
}

void CSTbyteOrderSwapLongWord (void *data) {
	char ch;

	ch = ((char *) data) [0]; ((char *) data) [0] = ((char *) data) [7]; ((char *) data) [7] = ch;
	ch = ((char *) data) [1]; ((char *) data) [1] = ((char *) data) [6]; ((char *) data) [6] = ch;
	ch = ((char *) data) [2]; ((char *) data) [2] = ((char *) data) [5]; ((char *) data) [5] = ch;
	ch = ((char *) data) [3]; ((char *) data) [3] = ((char *) data) [4]; ((char *) data) [4] = ch;
}

int main (int argv, char *argc []) {
	int i;
	CSTsurvPoint_t survPoint;

	printf ("%d\n",(int) sizeof (CSTsurvPoint_t));
	while (fread (&survPoint,sizeof (CSTsurvPoint_t),1,stdin) == 1) {
		for (i = 0;i < 10; ++i) survPoint.Name  [i] = survPoint.Name  [i + 1];
		survPoint.Name  [i] = '\0';
		for (i = 0;i < 10; ++i) survPoint.Pcode [i] = survPoint.Pcode [i + 1];
		survPoint.Pcode [i] = '\0';
		printf ("P#: %s X: %lf Y: %lf Z: %lf Pcode: %s\n", survPoint.Name, (double) survPoint.X, (double) survPoint.Y, (double) survPoint.Z, survPoint.Pcode);
	}
	return (0);
}

#include <stdio.h>
#include <string.h>
#include <CSTsurveying.h>

int main(int argv, char *argc[]) {
    int i;
    char buffer[64];
    CSTsurvPoint_t survPoint;

    printf("\"PCode\"\t\"Name\"\t\"Xcoord\"\t\"Ycoord\"\t\"Elevation\"\n");
    while (fread(buffer, 64, 1, stdin) == 1) {
        for (i = 0; i < 10 && buffer[i + 1] != ' '; ++i) survPoint.Name[i] = buffer[i + 1];
        survPoint.Name[i] = '\0';
        for (i = 0; i < 10 && buffer[i + 36] != ' '; ++i) survPoint.Pcode[i] = buffer[i + 36];
        survPoint.Pcode[i] = '\0';
        memcpy(&(survPoint.Y),buffer + 11,sizeof(double));
        memcpy(&(survPoint.X),buffer + 19,sizeof(double));
        memcpy(&(survPoint.Z),buffer + 27,sizeof(double));
        printf("\"%s\"\t\"%s\"\t%lf\t%lf\t%lf\n", survPoint.Pcode,survPoint.Name,survPoint.X,survPoint.Y,survPoint.Z);
    }
    return (0);
}

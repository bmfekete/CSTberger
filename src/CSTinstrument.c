#include <stdio.h>
#include <string.h>
#include <CSTsurveying.h>

int main(int argv, char *argc[]) {
    int i, ret;
    char buffer[256];
    CSTsurvPoint_t survPoint;

    if (fgets(buffer,sizeof(buffer) - 1,stdin) != buffer)  { fprintf (stderr,"Error\n"); return 1; }
    while ((ret = fscanf(stdin,"%s\t%lf\t%lf\t%lf\t%s\t%s",survPoint.Name, &(survPoint.X), &(survPoint.Y), &(survPoint.Z), survPoint.Unit, survPoint.Pcode)) > 0) {
//        if (ret == 6) printf("%d Field 1: %s\tFiled 2: %lf\tField 3: %lf\tField 4 %lf\tFiel 5 %s\tField 6 %s\n",ret, survPoint.Name, survPoint.X, survPoint.Y, survPoint.Z, survPoint.Unit, survPoint.Pcode);
//        continue;
        if (ret != 6) { fprintf (stderr,"Error %d\n",ret); continue; } 
        for (i = 0; i < sizeof (buffer); ++i) buffer[i] = '\0';
        buffer[0]='~';
        strncpy(buffer + 1,  survPoint.Name + 1, strlen(survPoint.Name)   - 2);
        for (i = strlen(survPoint.Name)  - 2; i < sizeof (survPoint.Name) - 2;  ++i) buffer [i + 1] = ' ';
        buffer [35] = survPoint.Unit[1];
        strncpy(buffer + 36, survPoint.Pcode + 1, strlen(survPoint.Pcode) - 2); 
        for (i = strlen(survPoint.Pcode) - 2; i < sizeof (survPoint.Name) - 2; ++i) buffer [i + 36] = ' ';
        memcpy(buffer + 11,&(survPoint.Y),sizeof(double));
        memcpy(buffer + 19,&(survPoint.X),sizeof(double));
        memcpy(buffer + 27,&(survPoint.Z),sizeof(double));
        fwrite (buffer,CSTrecordLEN,1,stdout);
    }
    return (0);
}

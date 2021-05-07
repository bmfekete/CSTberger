
#define CSTrecordLEN 64

typedef struct CSTsurvPoint_s {
    char Name[12];
    char Unit[3];
    double X, Y, Z;
    char Pcode[29];
} CSTsurvPoint_t;
#include <stdio.h>

#pragma pack(1);

typedef struct Registro Registro;

struct Registro{
    char chave[8];
    char nome[40];
    char email[40];
    char telefone[12];
};

int main(){

    Registro r;
    FILE *x;
    FILE *y;
    int a, i = 0;

    y = fopen("arq2.dat","w");
    x = fopen("arq1.dat","r");
    fseek(x,0,SEEK_END);
    a = ftell(x);
    a = (a/sizeof(Registro));
    fseek(x,-100,SEEK_END);

    while(i != a){

        fread(&r,sizeof(Registro),1,x);
        fwrite(&r,sizeof(Registro),1,y);
        fseek(x,-200,SEEK_CUR);
        i++;
    }

    fclose(x);
    fclose(y);
    return 0;
}

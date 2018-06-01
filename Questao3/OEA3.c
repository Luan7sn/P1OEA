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
    FILE *z;
    int a, b, c, d, inicio, meio, fim, i = 0, j = 0;
    x = fopen("arq1.dat","r");
    y = fopen("arq2.dat","r");
    z = fopen("arq3.dat","w");

    fseek(x,0,SEEK_END);
    a = ftell(x);
    rewind(x);
    a = a/sizeof(Registro);
    fseek(y,0,SEEK_END);
    b = ftell(x);
    rewind(y);
    inicio = 0;
    fim = b/sizeof(Registro);
    meio = (inicio+fim)/2;

    while(j != a){

        c = fread(&r,8,1,x);
        fseek(y,meio*sizeof(Registro)+1,SEEK_SET);
        d = fread(&r,8,1,y);

        while(c != d || inicio != meio || meio != fim){

            if(c < d){

                fim = meio-1;
                meio = (inicio+fim)/2;
                fseek(y,meio*sizeof(Registro)+1,SEEK_SET);
            }
            else{

                inicio = meio + 1;
                meio = (inicio+fim)/2;
                fseek(y,meio*sizeof(Registro)+1,SEEK_SET);
            }
        }

        if(c == d){

            fseek(x,-8,SEEK_CUR);
            fread(&r,sizeof(Registro),1,x);
            fwrite(&r,sizeof(Registro),1,z);
        }
        j++;

    }

    fclose(x);
    fclose(y);
    fclose(z);
    return 0;
}

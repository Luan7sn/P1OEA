#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#pragma pack(1);

typedef struct Registro Registro;

struct Registro{
    char chave[8];
    char nome[40];
    char email[40];
    char telefone[12];
};

bool terminaCom(char *email, char *termina){

    char *teste = strrchr(email,'@');
    if(teste != NULL && strncmp(teste,termina,10) == 0){
        return true;
    }
    return false;
}

int main(){

    Registro r;
    FILE *x;
    FILE *y;
    int a, i = 0;
    char c;
    x = fopen("arq1.dat","r");
    y = fopen("arq2.dat","w");

    fseek(x,0,SEEK_END);
    a = ftell(x);
    rewind(x);
    a = a/sizeof(Registro);
    char d[] = "@gmail.com";

    while(i != a){

        fread(&r,sizeof(Registro),1,x);

        if(terminaCom(r.email,d) == true){

            fseek(x,-100,SEEK_CUR);
            fwrite(&r,sizeof(Registro),1,y);
            fseek(x,100,SEEK_CUR);
        }
        i++;
    }

    fclose(x);
    fclose(y);
    return 0;
}

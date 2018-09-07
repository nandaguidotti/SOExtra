#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
/*
Fernanda Pereira Guidotti
 7003361
 TRABALHO EXTRA DE SISTEMAS OPERACIONAIS
 MANIPULAÇÃO DE ARQUIVOS
 */

clock_t t;
FILE *arq;
FILE *result;

double tempo_open, tempo_write, tempo_read, tempo_close;

int main(void) {
    int i;
    char nome[12] = { };
    result = fopen("Resultados.txt", "r+");
    fprintf(result, "    OPEN     |       WRITE     |       READ      |      CLOSE\n");
    
    
    for(i=1; i<11; i++){
        sprintf(nome, "%d", i);
        puts(nome);
        strcat(nome, ".txt");
        
        
        
        //OPEN
        t = clock();
        arq = fopen(nome, "r+");
        t = clock() - t;
        tempo_open = ((double)t)/CLOCKS_PER_SEC; //transformando pra segundos
        
        //WRITE
        t = clock();
        fprintf(arq, "%d", i);
        t = clock() - t;
        tempo_write = ((double)t)/CLOCKS_PER_SEC; //transformando pra segundos
        
        //READ
        t = clock();
        fscanf(arq, "%d"); 
        t = clock() - t;
        tempo_read = ((double)t)/CLOCKS_PER_SEC; //transformando pra segundos
        
        //CLOSE
        t = clock();
        fclose(arq);
        t = clock() - t;
        tempo_open = ((double)t)/CLOCKS_PER_SEC; //transformando pra segundos
        
        
        fprintf(result, "%f     |   %f      |   %f      |      %f\n", tempo_open, tempo_write, tempo_read, tempo_close);
        
    }
    
    fclose(result);
    
    
    return 0;
}

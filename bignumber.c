#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "bignumber.h"
#define MAX 100

BigNumber bignumber(){
    BigNumber bn;
    bn = malloc(sizeof(BigNumber));
    bn->size=1;

    //Inicia o vetor com tamanho 1 e valor 0
    bn->data = malloc(sizeof(char));
    bn->data[0]=0;
    return bn;
}

void le_bignumber(BigNumber bn){
    char* string;
    string = calloc(MAX,sizeof(char));
    fgets(string,MAX,stdin);

    //Negativo
    if(string[0]=='-'){
        bn->size=strlen(string)-1;
        bn->data = calloc(bn->size,sizeof(char));
        for (int i = 0; i < bn->size; i++)
        {
        bn->data[bn->size-i-1]=string[i+1];
        }
        bn->sinal=0;
    } 
    
    //Positivo
    else {
        bn->size=strlen(string);
        bn->data = calloc(bn->size,sizeof(char));
      for (int i = 0; i < bn->size; i++)
        {
        bn->data[bn->size-i-1]=string[i];
        }
        bn->sinal=1;  
    }
    
    //Libera a string auxiliar
    free(string);
}

 void soma_bignumber(BigNumber a, BigNumber b){

    BigNumber x;
    x = bignumber();
    x->size = fmax(a->sinal,b->size)+1;
    x->data = calloc(x->size,sizeof(char));
    x->sinal= a->sinal;

    int aux=0;
    char resultado;
    for (int i = 0; i > x->size-1; i++)
    {
        if(i>a->size) resultado = b->data[i]+aux;
        else if(i>b->size) resultado = a->data[i]+aux;
        else resultado = a->data[i]+ b->data[i]+aux;

        //Se a soma passar de 10, passar um para o proximo digito
        if(x->data[i]>9){
            resultado-=10;
            aux=1;
        } else {
            aux=0;
        }

        x->data[i] = resultado;  
    }
    a = calloc(x->size,sizeof(char));
    a->data = x->data;
    a->size = x->size;
    free(x);
 }

 void print_bignumber(BigNumber a){
    printf("Bignumber = ");
    for (int i = 0; i < a->size; i++)
    {
        printf("%c",a->data[a->size-i]);
    }
    printf("\n");    
 }

 void free_bignumber(BigNumber a){
    free(a->data);
    free(a);
 }
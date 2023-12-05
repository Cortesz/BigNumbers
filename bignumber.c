#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "bignumber.h"
#define MAX 1000
#define ASCII_INT 48 

BigNumber bignumber(){
    BigNumber bn;
    bn = malloc(sizeof(struct bignumber));
    bn->size=1;

    //Inicia o vetor com tamanho 1 e valor 0
    bn->data = malloc(sizeof(char));
    bn->data[0]=0;
    return bn;
}

void le_bignumber(BigNumber bn){
    char* string;
    string = calloc(MAX,sizeof(char));
    scanf("%s",string);

    //Negativo
    if(string[0]=='-'){
        bn->size=strlen(string)-1;
        bn->data = calloc(bn->size,sizeof(char));
        for (int i = 0; i < bn->size; i++)
        {
        bn->data[bn->size-i-1]=string[i+1];
        }
        bn->sinal=1;
    } 
    
    //Positivo
    else {
        bn->size=strlen(string);
        bn->data = calloc(bn->size,sizeof(char));
      for (int i = 0; i < bn->size; i++)
        {
        bn->data[bn->size-i-1]=string[i];
        }
        bn->sinal=0;  
    }
    
    //Libera a string auxiliar
    free(string);
}

 BigNumber soma_bignumber(BigNumber a, BigNumber b){
    BigNumber x;
    x = bignumber();
    x->sinal = a->sinal;

    //Tamanho do vetor da Soma
    if (a->size > b->size) x->size = a->size+1; else x->size = b->size+1;
    x->data = calloc(x->size,sizeof(char));

    int aux=0, resultado;
    for (int i = 0; i < x->size-1; i++)
    {
        int ai = a->data[i] - ASCII_INT;
        int bi = b->data[i] - ASCII_INT;

        if(i>=a->size) ai=0;
        if(i>=b->size) bi=0;
        resultado = ai + bi +aux;

        //Se a soma passar de 10, passar um para o proximo digito
        if(resultado>9){
            resultado = resultado - 10;
            aux=1;
        } else {
            aux=0;
        }
        x->data[i] = resultado + ASCII_INT;
    }

    return x;
 }

 void print_bignumber(BigNumber a){
    printf("Bignumber = ");
    if (a->sinal) printf("-");
    for (int i = a->size-1; i >=0; i--) printf("%c",a->data[i]);
    printf("\n");    
 }

 void free_bignumber(BigNumber a){
    free(a->data);
    free(a);
 }
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
    bn->size=strlen(string);
    bn->sinal=1;
    
    for (int i = 0; i < bn->size; i++)
    {
        bn->data[i]=string[i];
    }
    
}

 void soma_bignumber(BigNumber a, BigNumber b){

 }

 void print_bignumber(BigNumber a){
    for (int i = 0; i < a->size; i++)
    {
        printf("%c",a->data[i]);
    }
    
 }
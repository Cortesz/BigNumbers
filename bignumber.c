#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "bignumber.h"
#define MAX 100

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

 void soma_bignumber(BigNumber *pointer_a, BigNumber *pointer_b){

    BigNumber x,a = *pointer_a, b = *pointer_b;
    x = bignumber();

    if (a->size > b->size) x->size = a->size+1;
    else x->size = b->size+1;
    x->data = calloc(x->size,sizeof(char));

    int aux=0, resultado;
    for (int i = 0; i < x->size-1; i++)
    {
        int ai = a->data[i] - 48;
        int bi = b->data[i] - 48;

        if(a->size<i) resultado = bi + aux;
        else if(b->size<i) resultado = ai + aux;
        else resultado = ai + bi +aux;

        //Se a soma passar de 10, passar um para o proximo digito
        if(resultado>9){
            resultado = resultado - 10;
            aux=1;
        } else {
            aux=0;
        }


        x->data[i] = resultado + 48;
    }

    print_bignumber(x);
 }

 void print_bignumber(BigNumber a){
    printf("Bignumber = ");
    for (int i = 0; i <= a->size; i++)
    {
        printf("%c",a->data[a->size-i-1]);
    }
    printf("\n");    
 }

 void free_bignumber(BigNumber a){
    free(a->data);
    free(a);
 }
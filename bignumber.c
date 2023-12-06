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
        bn->data = realloc(bn->data,bn->size*sizeof(char));
        for (int i = 0; i < bn->size; i++)
        {
        bn->data[bn->size-i-1]=string[i+1];
        }
        bn->sinal=1;
    } 
    
    //Positivo
    else {
        bn->size=strlen(string);
        bn->data = realloc(bn->data,bn->size*sizeof(char));
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

    //Tamanho do vetor da Soma
    if (a->size > b->size) x->size = a->size+1; else x->size = b->size+1;
    x->data = realloc(x->data,x->size*sizeof(char));

    int aux=0, resultado;
    for (int i = 0; i < x->size; i++)
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
    
    //Remove o zero da frente
    while (x->data[x->size-1]=='0')
    {
        x->size-=1;
    }
    
    return x;
 }

 BigNumber mult_bignumber(BigNumber a, BigNumber b){
    BigNumber x;
    x = bignumber();
    x->size = a->size+b->size;
    x->data = realloc(x->data,x->size*sizeof(char));

    //Multiplica
    int* resultado;
    resultado = calloc(x->size,sizeof(int));
    for (int i = 0; i < a->size; i++) 
    {
        for (int j = 0; j < b->size; j++){
            int ai = a->data[i] - ASCII_INT;
            int bj = b->data[j] - ASCII_INT;
            resultado[i+j] += ai * bj;
        }
    }

    //Transforma os numeros para 1 digito, soma o excedente em i+1 e converte para char
    int aux = 0;
    for (int i = 0; i < x->size; i++)
    {
        if (resultado[i]>9)
        {
            aux = resultado[i]/10;
            resultado[i] = resultado[i]%10;
            resultado[i+1]+=aux; 
        } else aux=0;
        x->data[i]= resultado[i] + ASCII_INT;
    }
    free(resultado);

    //Remove o zero da frente
    while (x->data[x->size-1]=='0')
    {
        x->size-=1;
    }

    return x;
 }

 void print_bignumber(BigNumber a){
    if (a->sinal) printf("-");
    for (int i = a->size-1; i >=0; i--) printf("%c",a->data[i]);
    printf("\n");    
 }

 void free_bignumber(BigNumber a){
    free(a->data);
    free(a);
 }
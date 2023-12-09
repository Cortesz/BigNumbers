#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "bignumber.h"
#define MAX 2000
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

void operacao(){
    BigNumber a,b,x;
    a = bignumber();
    b = bignumber();
    int aux=1;
    do
    {    
    aux = le_bignumber(a);
    le_bignumber(b);
    
    if (aux==EOF) break;
    

    //Operador +(Soma) -(Subtracao) *(Multiplicacao)
    getchar();
    char operador;
    scanf("%c",&operador);
    
    switch (operador)
    {
    case '+':
        if (a->sinal== 1 && b->sinal == 0) {
                a->sinal=0;
                b->sinal=0;
                x = sub_bignumber(b,a);
            } else if (a->sinal== 0 && b->sinal == 1) {
                a->sinal=0;
                b->sinal=0;
                x = sub_bignumber(a,b);
            } else {
                x = soma_bignumber(a,b);
            }
    
        print_bignumber(x);
        break;

    case '*':
        x = mult_bignumber(a,b);
        if (a->sinal!=b->sinal) x->sinal = 1; else x->sinal=0;
        print_bignumber(x);
        break;

    case '-':
        if (b->sinal == 1) 
            {
                b->sinal = 0;
                x = soma_bignumber(a, b);
            }

        else if (a->sinal == 1 && b->sinal == 0)
            {
                b->sinal = 1;
                x = soma_bignumber(a,b);
            } else {
                x = sub_bignumber(a,b);
            }
        print_bignumber(x);
        break;
        
    
    default:
        break;
    }
   
    free_bignumber(x);
}while(aux!=EOF);

    free_bignumber(a);
    free_bignumber(b); 
}

int le_bignumber(BigNumber bn){
    char* string;
    string = calloc(MAX,sizeof(char));
    scanf("%s",string);
    if (*string=='\0'){
        free(string);
        return EOF;
    } 

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
    return 1;
}

BigNumber soma_bignumber(BigNumber a, BigNumber b){
    BigNumber x;
    x = bignumber();

    //Tamanho do vetor da Soma
    if (a->size > b->size) x->size = a->size+1; else x->size = b->size+1;
    x->data = realloc(x->data,x->size*sizeof(char));
    x->sinal=a->sinal;

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
    while (x->data[x->size-1]=='0' && x->size>1)
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
    while (x->data[x->size-1]=='0' && x->size>1)
    {
        x->size-=1;
    }

    return x;
 }

BigNumber sub_bignumber(BigNumber a, BigNumber b)
{
    BigNumber x;
    x = bignumber();

    //Compara o modulo de A com o modulo de B
    if (a->size<b->size)
    {
        BigNumber temp;
        temp = a;
        a = b;
        b = temp;
        x->sinal=1;
    } else if (a->size==b->size)
    {
        for (int i = a->size-1; i >= 0; i--)
        {
            if (a->data[i]<b->data[i])
            {
                x->sinal=1;
                BigNumber temp;
                temp = a;
                a = b;
                b = temp;
                break;
            }
        }
    }
    
    //Tamanho do vetor da Subtração
    if (a->size > b->size) x->size = a->size+1; else x->size = b->size+1;
    x->data = realloc(x->data,x->size*sizeof(char));

    int aux=0, resultado;
    for (int i = 0; i < x->size; i++)
    {
        int ai = a->data[i] - ASCII_INT;
        int bi = b->data[i] - ASCII_INT;

        if(i>=a->size) ai=0;
        if(i>=b->size) bi=0;

        resultado = ai - bi - aux;
        if (resultado<0)
        {
            resultado+=10;
            aux=1;
        } else aux=0;
        
        x->data[i] = resultado + ASCII_INT;
    }

    //Remove o zero da frente
    while (x->data[x->size-1]=='0' && x->size>1)
    {
        x->size-=1;
    }
    
    return x;
}

 void print_bignumber(BigNumber a){
    if (a->size==1 && a->data[0]=='0') a->sinal=0;
    if (a->sinal) printf("-");
    for (int i = a->size-1; i >=0; i--) printf("%c",a->data[i]);
    printf("\n");    
 }

 void free_bignumber(BigNumber a){
    free(a->data);
    free(a);
 }
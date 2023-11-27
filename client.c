#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bignumber.h"

int main(){
    BigNumber a,b;
    a = bignumber();
    le_bignumber(a);

    b = bignumber();
    le_bignumber(b);

    printf("Soma \n"); 
    soma_bignumber(&a,&b);
    

    free_bignumber(a);
    free_bignumber(b);
    return 0;
}
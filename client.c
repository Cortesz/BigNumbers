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
    soma_bignumber(a,b);
    print_bignumber(a);
    

    free_bignumber(a);
    return 0;
}
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
    BigNumber x = soma_bignumber(a,b);
    print_bignumber(x);

    printf("Multiplicacao \n"); 
    BigNumber y = mult_bignumber(a,b);
    print_bignumber(y);

    printf("Subtracao\n");
    BigNumber z = sub_bignumer(a,b);
    print_bignumber(z);

    free_bignumber(a);
    free_bignumber(b);
    free_bignumber(x);
    free_bignumber(y);
    return 0;
}
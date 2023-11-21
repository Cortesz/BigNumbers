#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bignumber.h"

int main(){
    BigNumber a;
    a = bignumber();
    le_bignumber(a);
    print_bignumber(a);

    return 0;
}
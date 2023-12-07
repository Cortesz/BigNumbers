typedef struct bignumber *BigNumber;
 
struct bignumber { char *data; int size; int sinal;};

typedef struct bignumber *BigNumber;

//Cria um BigNumber
BigNumber bignumber();

//Atribui valor ao BigNumber
void le_bignumber(BigNumber bn);

//Soma
BigNumber soma_bignumber(BigNumber a, BigNumber b);

//Multiplicacao
BigNumber mult_bignumber(BigNumber a, BigNumber b);

//Subtracao
BigNumber sub_bignumer(BigNumber a, BigNumber b);

//Print (Inverte a ordem)
void print_bignumber(BigNumber a);

//Libera a memoria
void free_bignumber(BigNumber a);
typedef struct bignumber *BigNumber;
 
struct bignumber { char *data; int size; int sinal;};

typedef struct bignumber *BigNumber;

//Cria um BigNumber
BigNumber bignumber();

//Atribui valor ao BigNumber
void le_bignumber();

BigNumber soma_bignumber(BigNumber a, BigNumber b);

BigNumber mult_bignumber(BigNumber a, BigNumber b);

void print_bignumber(BigNumber a);

void free_bignumber(BigNumber a);
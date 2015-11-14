


typedef struct

{

	unsigned long movimentacoes;



	unsigned long comparacoes;



	double tempo;



} Estatisticas;


void Selecao(unsigned long *v, unsigned long n, unsigned long *mov, unsigned long *comp);

void Insercao(unsigned long *v, unsigned long n, unsigned long *mov, unsigned long *comp);


void QuickSort(unsigned long *v, unsigned long n, unsigned long *mov, unsigned long *comp);


void HeapSort(unsigned long *v, unsigned long n, unsigned long *mov, unsigned long *comp);




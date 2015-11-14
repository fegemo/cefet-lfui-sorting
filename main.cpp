#include <stdlib.h>

#include <stdio.h>

#include <time.h>

#include "ordenacao.h"


//-------------------------------------------------------------------------

// Gera vetor aleatoriamente com tamanho n

//-------------------------------------------------------------------------

void GerarVetorAleatorio(unsigned long *v, unsigned long n)

{

	unsigned long i;




    for(i = 0; i < n; i++) {

        v[i] = (rand() % n);

    }
}





Estatisticas Ordenar(unsigned long *v, unsigned long n)

{



	Estatisticas estatisticas;



	estatisticas.movimentacoes = 0;
	estatisticas.comparacoes = 0;



	clock_t tempo1, tempo2;


	tempo1 = clock();





	//ordena o vetor

	// pode ser: Selecao, Insercao, QuickSort ou HeapSort
    void (*algoritmoEscolhido)(unsigned long *, unsigned long, unsigned long *, unsigned long *) = Selecao;

    algoritmoEscolhido(v, n, &estatisticas.movimentacoes, &estatisticas.comparacoes);




	tempo2 = clock();



	estatisticas.tempo =  (double)(tempo2 - tempo1) / CLOCKS_PER_SEC;





	return estatisticas;



}



//-------------------------------------------------------------------------

// Funcao principal

//-------------------------------------------------------------------------

int main(int argc, char **argv)

{

    printf("|                                                    |\n");


    //pergunta tamanho do vetor
    int tamanho = 100000;
    printf("| Tamanho do vetor: %d                           |\n", tamanho);
    printf("| Gerando vetor aleatorio...                         |\n");

	//cria o vetor de acordo com o tipo de conjunto escolhido
    unsigned long* v = (unsigned long*)malloc(sizeof(unsigned long)*tamanho);
    GerarVetorAleatorio(v, tamanho);

    printf("| Vetor gerado                                       |\n");

    //estatisticas de acordo com o algoritmo escolhido

    printf("| Comecando a ordenar:                               |\n");

    Estatisticas estatisticas = Ordenar(v, tamanho);






    //Depois da ordenação


    printf("| Resultados:                                        |\n");



    printf("   Tempo gasto (em seg.): %f                         \n", estatisticas.tempo);



    printf("   Movimentacoes: %lu                                \n", estatisticas.movimentacoes);



    printf("   Comparacoes: %lu                                  \n", estatisticas.comparacoes);



    printf("|                                                    |\n\n\n");



	return 0;
}


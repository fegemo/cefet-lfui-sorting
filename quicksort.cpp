#include "ordenacao.h"



// Recebe vetor v[p..r] com p < r. Rearranja os

// elementos do vetor e devolve j em p..r tal que

// v[p..j-1] <= v[j] < v[j+1..r].



long Particao(unsigned long *v, long p, long r, unsigned long *mov, unsigned long *comp)
{

	//c = v[p]
	(*mov)++;

   	unsigned long c = v[p], i = p, j = r, t;



   	while (1) {


  		//(v[i] <= c)
      	(*comp)++;

       	while (i <= r && v[i] <= c)
       	{
       		//(v[i] <= c)
       		(*comp)++;
	       	++i;

    	}


		//(c < v[j])
		(*comp)++;

      	while (c < v[j])
       	{
        	//(c < v[j])
         	(*comp)++;
          	--j;
        }


      	if (i >= j) break;


      	//mov+3
      	(*mov)++; (*mov)++; (*mov)++;
       	t = v[i]; v[i] = v[j]; v[j] = t;

      	++i; --j;

   	}

   	//mov+3
  	(*mov)++; (*mov)++; (*mov)++;
   	t = v[p]; v[p] = v[j]; v[j] = t;


   	return j;
}






// A função rearranja o vetor v[p..r], com p <= r+1,
// de modo que ele fique em ordem crescente.

void QuickSortRecursivo(unsigned long *v, long p, long r, unsigned long *mov, unsigned long *comp)

{

   long j;

   while (p < r) {

      j = Particao (v, p, r, mov, comp);

      if (j - p < r - j) {

         QuickSortRecursivo (v, p, j-1, mov, comp);

         p = j + 1;

      } else {

         QuickSortRecursivo (v, j+1, r, mov, comp);

         r = j - 1;

      }

   }

}



void QuickSort(unsigned long *v, unsigned long n, unsigned long *mov, unsigned long *comp) {
    QuickSortRecursivo(v, 0, n-1, mov, comp);
}

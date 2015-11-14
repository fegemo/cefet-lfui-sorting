#include "ordenacao.h"


void Selecao(unsigned long *v, unsigned long n, unsigned long *mov, unsigned long *comp)

{

	int i, j, min;



	unsigned long x;







   	for (i = 0; i < n-1; ++i)

   	{

      	min = i;



      	for (j = i+1; j < n; ++j)
        {



      		//v[j] < v[min]
      		(*comp)++;

         	if (v[j] < v[min])

         		min = j;

        }

     	//mov+3
     	(*mov)++;
      	x = v[i];

     	(*mov)++;
      	v[i] = v[min];

     	(*mov)++;
      	v[min] = x;



   	}



}



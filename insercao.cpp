#include "ordenacao.h"


void Insercao(unsigned long *v, unsigned long n, unsigned long *mov, unsigned long *comp)

{

     long i, j, value;



     for(i = 1; i < n; ++i)

     {

 		 (*mov)++;

         value = v[i];



         for (j = i - 1; j >= 0 && v[j] > value; --j)

         {

         	 (*mov)++;

             v[j + 1] = v[j];



             //(v[j] > value)

             (*comp)++;

         }

         //(v[j] > value)

         (*comp)++;



         (*mov)++;

         v[j + 1] = value;



     }

 }

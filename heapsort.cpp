#include "ordenacao.h"



void Heap(unsigned long *v, long root, long bottom, unsigned long *mov, unsigned long *comp)

{

  	unsigned long done, maxChild, temp;



  	done = 0;



	//primeira comparação do while, comp++

	(*comp)++;

  	while ((root*2 <= bottom) && (!done))

  	{

    	//(root*2 == bottom) é comparação entre chaves, portanto não conta
     	if (root*2 == bottom)
     	{
       		maxChild = root * 2;
   		}

		else if (v[root * 2] > v[root * 2 + 1])
		{
			//(v[root * 2] > v[root * 2 + 1])
			(*comp)++;

      		maxChild = root * 2;

  		}

    	else
		{
			//(v[root * 2] > v[root * 2 + 1])
			(*comp)++;

      		maxChild = root * 2 + 1;

		}



  		(*comp)++;

    	if (v[root] < v[maxChild])

    	{
    		//mov+3

			(*mov)++;
      		temp = v[root];

			(*mov)++;
      		v[root] = v[maxChild];

			(*mov)++;
      		v[maxChild] = temp;

      		root = maxChild;

    	}

    	else

      		done = 1;



		//comparação do while, comp++
		(*comp)++;

  	}

}





void HeapSort(unsigned long *v, unsigned long n, unsigned long *mov, unsigned long *comp)
{

	long i, temp;



	for (i = (n / 2)-1; i >= 0; i--)

    	Heap(v, i, n, mov, comp);



  	for (i = n-1; i >= 1; i--)

  	{

  		//mov+3

		(*mov)++;
    	temp = v[0];

		(*mov)++;
    	v[0] = v[i];

		(*mov)++;
    	v[i] = temp;

    	Heap(v, 0, i-1, mov, comp);

  	}

}



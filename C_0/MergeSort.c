#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* merge function */
void merge(int arr[], int lo, int mid, int hi)
{
    int l, k;
	int i, j;

    /* allocate for aux array */
    int * aux = (int*)malloc((hi-lo)*sizeof(int));
	
	/* copy to aux */
    for (l = lo; l <= hi; l++)
	{
        aux[l] = arr[lo + l];
		printf("%d\n", arr[l]);
	}
	
    /* do the merge now */
	i = lo; j = mid + 1;
	for (k = lo; k <= hi; k++)
    {	
	if (i > mid) 
	{
	    arr[k] = aux[j];
		j++;
	}
	else if (j > hi) 
	{
	    arr[k] = aux[i];
		i++;
	}
	else if (aux[j] < aux[i])
	{
	    arr[k] = aux[j];
		j++;
    }
	else 
	{
	    arr[k] = aux[i];
		i++;
	}
	}
	free(aux);
	
for (i = 0; i <= 11; i++)
	{
	    printf("%d\n", arr[i]);
	}
}

int main(int argc, char * argv[])
{
    int i;
	
    /* Merge sort client */
	int arrt [] = {1, 3, 13, 44, 68, 93, 2, 4, 40, 67, 87, 99};
	merge(arrt, 0, 5, 11);
	for (i = 0; i <= 11; i++)
	{
	   // printf("%d\n", arrt[i]);
	}
    return 0;
}
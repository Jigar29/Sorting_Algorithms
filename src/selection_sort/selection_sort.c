/*
 * selection_sort.c
 *
 *  Created on: Jul 28, 2018
 *      Author: Jigar
 */

#include "selection_sort.h"
#include "stdlib.h"
#include <string.h>

int* selectionSort(const int *data, int size)
{
	int temp = 0;
	int *array= (int *)calloc(size, sizeof(int));
	memcpy(array, data, size * sizeof(int));
	for(int i=0; i<(size-1); i++)
	{
		for(int j=i; j<(size-1);j++)
		{
			if(array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	return array;
}

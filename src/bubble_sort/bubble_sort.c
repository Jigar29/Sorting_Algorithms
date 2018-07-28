/*
 * bubble_sort.c
 *
 *  Created on: Jul 28, 2018
 *      Author: Jigar
 */

#include "bubble_sort.h"
#include "stdlib.h"
#include <string.h>

int* bubbleSort(const int *data, int size)
{
	int temp = 0;
	int *array= (int *)calloc(size, sizeof(int));
	memcpy(array, data, size * sizeof(int));

	for(int i=0; i<(size -1); i++)
	{
		for(int j=0; j<(size-1-i);j++)
		{
			if(array[j] > array[j+1])
			{
				temp = array[j];
				array[j] = array[j+1];
				array[j+1]= temp;
			}
		}
	}
	return array;
}

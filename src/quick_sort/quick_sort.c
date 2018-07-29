/*
 * quick_sort.c
 *
 *  Created on: Jul 29, 2018
 *      Author: Jigar
 */

#include "quick_sort.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static int partition(int *array, int size)
{
	int pivot = array[size-1];
	int start_index= 0;
	int temp =0;

	for(int i=0; i<(size-1); i++)
	{
		if(array[i] < pivot)
		{
			temp = array[start_index];
			array[start_index] = array[i];
			array[i] = temp;

			start_index++;
		}
	}

	temp = array[size -1];
	array[size -1] = array[start_index];
	array[start_index] = temp;
	return start_index;
}

static void performQuickSort(int *array, int size)
{
	int index = partition(array, size);

	//Base condition
	if(size <= 1)
		return;

	if(index != 0)
	{
		performQuickSort(array, index);
	}
	if(index < (size -1))
	{
		performQuickSort(array+index+1, size-index-1);
	}
}

int * quickSort(const int *data, int size)
{
	int *array= (int *)calloc(size, sizeof(int));
	memcpy(array, data, size * sizeof(int));

	performQuickSort(array, size);

	return array;
}

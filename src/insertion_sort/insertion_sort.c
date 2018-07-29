/*
 * insertion_sort.c
 *
 *  Created on: Jul 28, 2018
 *      Author: Jigar
 */
#include <stdlib.h>
#include "insertion_sort.h"
#include <stdio.h>
#include <string.h>

int* insertionSort(const int *data, int size)
{
	int temp = 0;
	int *array= (int *)calloc(size, sizeof(int));
	memcpy(array, data, size * sizeof(int));

	for(int i=1; i<size; i++)
	{
		temp = array[i];
		for(int j=i-1; j>=0; j--)
		{
			if(array[j] > temp)
			{
				 array[j+1]= array[j];
				 array[j] = temp;
			}
		}
	}

	return array;
}


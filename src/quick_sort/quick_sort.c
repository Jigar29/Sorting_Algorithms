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

void performQuickSort(int *a, int size)
{
	// already sorted array
	// zero element
	// one element
	// 4 0 3 5 2 -1
	// 0 3 5 2 -1 4

	// base condition
	if(size<=1)
		return;

	int pivot_pos = size-1, left_pos = -1;
	//sorting
	for(int i =0; i<pivot_pos; i++)
	{
		if((a[i] <= a[pivot_pos]) && (left_pos >= 0))
		{
			a[i] ^= a[left_pos];
			a[left_pos] ^= a[i];
			a[i] ^= a[left_pos];

			left_pos++;
		}
		else if((a[i] > a[pivot_pos]) && (left_pos < 0)){
			left_pos = i;
		}
	}
	if(left_pos>=0)
	{
		a[left_pos] ^= a[pivot_pos];
		a[pivot_pos]^= a[left_pos];
		a[left_pos] ^= a[pivot_pos];

		pivot_pos = left_pos;
	}
	// function calls
	if(pivot_pos > 0)
		performQuickSort(a, pivot_pos);
	if(pivot_pos < (size -1))
		performQuickSort(a + pivot_pos + 1, size - pivot_pos - 1);

}

int * quickSort(const int *data, int size)
{
	int *array= (int *)calloc(size, sizeof(int));
	memcpy(array, data, size * sizeof(int));

	performQuickSort(array, size);

	return array;
}

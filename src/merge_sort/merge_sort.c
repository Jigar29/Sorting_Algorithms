/*
 * merge_sort.c
 *
 *  Created on: Jul 28, 2018
 *      Author: Jigar
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "merge_sort.h"

#define MAX_SIZE 20
int left[MAX_SIZE] = {0}, right[MAX_SIZE] = {0};

void performSort(int *data, int size)
{
	//base condition
	if(size <= 1)
		return;

	int mid = size/2;
	performSort(data, mid);
	performSort(data+mid, size-mid);

	for(int i=0; i<size-mid; i++)
	{
		if(i<mid)
			left[i] = data[i];
		right[i] = data[i+mid];
	}

	int left_pos = 0, right_pos = 0;
	for(int i=0; i<size; i++)
	{
		if((left_pos < mid) && (right_pos < (size -mid)))
		{
			if(left[left_pos] > right[right_pos])
			{
				data[i] = right[right_pos];
				right_pos++;
			}
			else
			{
				data[i] = left[left_pos];
				left_pos++;
			}
		}
		else if(left_pos >= mid)
		{
			data[i] = right[right_pos];
			right_pos++;
		}
		else if(right_pos >= (size -mid))
		{
			data[i] = left[left_pos];
			left_pos++;
		}
	}

}

int *mergeSort(const int *data, int size)
{
	int *array= (int *)calloc(size, sizeof(int));
	memcpy(array, data, size * sizeof(int));
	performSort(array, size);
	return array;
}

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

int* performSort(int *data, int size)
{
	//Base Condition
	if(size == 1)
		return data;

	int *left  = mergeSort(data, size/2);
	int *right = mergeSort(data+ (size/2), size/2);

	int right_count = 0, left_count = 0;

	for(int i=0; i<size; i++)
	{
		if((right_count <(size/2)) && (left_count <(size/2)))
		{
			if(*left > *right)
			{
				data[i] = *right;
				right++;
				right_count++;
			}
			else
			{
				data[i] = *left;
				left++;
				left_count++;
			}
		}
		else if(left_count >=(size/2))
		{
			data[i] = *right;
			right++;
			right_count++;
		}
		else if(right_count >=(size/2))
		{
			data[i] = *left;
			left++;
			left_count++;
		}
		else
		{
			printf("Something Bad Happened");
		}
	}
	return data;
}

int *mergeSort(const int *data, int size)
{
	int *array= (int *)calloc(size, sizeof(int));
	memcpy(array, data, size * sizeof(int));
	performSort(array, size);
	return array;
}

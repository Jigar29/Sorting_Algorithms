/*
 * counting_sort.c
 *
 *  Created on: Jul 29, 2018
 *      Author: Jigar
 */


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "counting_sort.h"

int * countingSort(const int *data, int size, int max_no)
{
	int *list= (int *)calloc(max_no + 1, sizeof(int));
	int *array = (int *)calloc(size, sizeof(int));

	for(int i=0; i<size; i++)
	{
		list[*(data+i)]+= 1;
	}

	for(int i=1; i<=max_no; i++)
	{
		list[i]+= list[i-1];
	}

	for(int i=0; i<size; i++)
	{
		array[(list[*(data+i)]--)-1]= *(data+i);
	}
	return array;
}

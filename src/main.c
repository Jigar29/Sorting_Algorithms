#include <stdio.h>
#include <stdlib.h>
#include "selection_sort.h"

void printArray(const int *array, int size)
{
	if(size <= 0)
	{
		printf("\n");
		return;
	}
	printf("%d, ", *array);
	printArray(array+1, size-1);
}

int main(void) {
	const int data[6] = {5, 8, 3, 2, 1, 10};
	int *sorted_array = 0;
	printf("Unsorted Array \n");
	printArray(&data[0], 6);

	/* Selection Sort */
	printf("Performing the Selection Sort:- \n");
	printf("Output From Selection Sort:- \n");
	sorted_array = selectionSort(&data[0], 6);
	printArray(sorted_array, 6);
	free(sorted_array);

	/* Bubble Sort */
	printf("Performing the Bubble Sort:- \n");
	printf("Output From Bubble Sort:- \n");
	sorted_array = bubbleSort(&data[0], 6);
	printArray(sorted_array, 6);
	free(sorted_array);

	return 0;
}

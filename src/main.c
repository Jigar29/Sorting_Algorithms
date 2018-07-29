#include <stdio.h>
#include <stdlib.h>
#include "selection_sort.h"
#include "bubble_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"

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
	const int data[8] = {5, 8, 3, 2, 1, 10, 0, 7};
	int *sorted_array = 0;
	printf("Unsorted Array \n");
	printArray(&data[0], 8);

	/* Selection Sort */
	printf("Performing the Selection Sort:- \n");
	printf("Output From Selection Sort:- \n");
	sorted_array = selectionSort(&data[0], 8);
	printArray(sorted_array, 8);
	free(sorted_array);

	/* Bubble Sort */
	printf("Performing the Bubble Sort:- \n");
	printf("Output From Bubble Sort:- \n");
	sorted_array = bubbleSort(&data[0], 8);
	printArray(sorted_array, 8);
	free(sorted_array);

	/* Insertion Sort */
	printf("Performing the Insertion Sort:- \n");
	printf("Output From Insertion Sort:- \n");
	sorted_array = insertionSort(&data[0], 8);
	printArray(sorted_array, 8);
	free(sorted_array);

	/* Merge Sort */
	printf("Performing the Merge Sort:- \n");
	printf("Output From Merge Sort:- \n");
	sorted_array = mergeSort(&data[0], 8);
	printArray(sorted_array, 8);
	free(sorted_array);


	return 0;
}

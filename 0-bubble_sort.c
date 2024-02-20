#include "sort.h"
/**
 * swap - swaps the values of two variables.
 * @var1: The variable whose value is to be swapped (with var2).
 * @var2: The variable whose value is to be swapped (with var1).
 * Return: None
 */
void swap(int *var1, int *var2)
{
    int temp = *var1;
    *var1 = *var2;
    *var2 = temp;
}

/**
 * bubble_sort - sorts an array of integers in ascending order using the
 * Bubble sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array to be sorted.
 * Return: None
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, j;

    for (i = 0; i < size - 1; i++)
        for (j = 0; j < size - i - 1; j++)
            if (array[j] > array[j + 1])
	    {
                swap(&array[j], &array[j + 1]);
                print_array(array, size);
	    }
}

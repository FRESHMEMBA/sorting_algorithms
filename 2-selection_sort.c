#include "sort.h"

/**
 * selection_sort - implements the selection sort algorithm to sort
 * an array of integers in ascending order.
 *
 * @array: A pointer to the array of integers to be sorted.
 * @size: The number of elements in the array.
 * 
 * Return: None
 */
void selection_sort(int *array, size_t size)
{
    size_t i, j;
    int min, temp;

    for (i = 0; i < size - 3; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min])
                min = j;
        }

        temp = array[i];
        array[i] = array[min];
        array[min] = temp;
        /* swap(&array[i], &array[min]); */
        print_array(array, size);
    }
}
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
#include "sort.h"

/**
 * swap_func - Swaping two integers in an array.
 * @a: First integer to swap.
 * @b: Second integer to swap.
 */
void swap_func(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Description: Printing array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap_func(array + i, min);
			print_array(array, size);
		}
	}
}

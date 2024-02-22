#include "sort.h"

/** 
 * insertion_sort_list - Sorts  doubly linked list of integers in ascending
 * order using the inserton sort algorithm.
 * @list: The list to be sorted.
 * Return: None
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current_node, *insertion_node, *next_node;

    if (list == NULL || *list == NULL)
        return;

    current_node = (*list)->next;

    while (current_node != NULL)
    {
        insertion_node = current_node->prev;

        while (insertion_node != NULL)
        {
            if (current_node->n < insertion_node->n)
            {
                next_node = current_node->next;
                current_node->next = insertion_node;
                current_node->prev = insertion_node->prev;
                insertion_node->prev = current_node;

                if (current_node->prev != NULL)
                {
                    current_node->prev->next = current_node;
                }
                if (next_node != NULL)
                {
                    next_node->prev = insertion_node;
                }
                insertion_node->next = next_node;
                if (current_node->prev == NULL)
                {
                    *list = current_node;
                }
                print_list(*list);
            }
            insertion_node = insertion_node->prev;
        }
        current_node = current_node->next;
    }
}
#include "sort.h"

/** 
 * insertion_sort_list - Sorts  doubly linked list of integers in ascending
 * order using the inserton sort algorithm.
 * @list: The list to be sorted.
 * Return: None
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *sorted = NULL;

    listint_t *current = *list;

    while (current != NULL)
    {
        listint_t *next = current->next;

        if (sorted == NULL || current->n <= sorted->n)
        {
            current->next = sorted;
            current->prev = NULL;
            if (sorted != NULL)
                sorted->prev = current;
            sorted = current;
        }
        else
        {
            listint_t *temp = sorted;
            while (temp->next != NULL && temp->next->n < current->n)
                temp = temp->next;

            current->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = current;
            temp->next = current;
            current->prev = temp;
        }

        current = next;
        print_list(sorted);
    }

    *list = sorted;
}

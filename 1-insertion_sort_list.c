#include "sort.h"

/** 
 * insertion_sort_list - Sorts  doubly linked list of integers in ascending
 * order using the inserton sort algorithm.
 * @list: The list to be sorted.
 * Return: None
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *print_ptr, *next, *temp;
    listint_t *current = *list;

    while (current != NULL)
    {
        next = current->next;
        temp = *list;

        while (temp != NULL && temp->n < current->n)
            temp = temp->next;

        if (temp == NULL)
        {
            current->next = NULL;
            current->prev = NULL;
            *list = current;
        }
        else if (temp == *list)
        {
            current->next = temp;
            current->prev = NULL;
            temp->prev = current;
            *list = current;
        }
        else
        {
            current->next = temp;
            current->prev = temp->prev;
            temp->prev->next = current;
            temp->prev = current;
        }

        print_ptr = *list;
        while (print_ptr != NULL)
        {
            printf("%d", print_ptr->n);
            if (print_ptr->next != NULL)
                printf(", ");
            print_ptr = print_ptr->next;
        }

        current = next;
<<<<<<< HEAD
        print_list(sorted);
=======
>>>>>>> ff9526f971657fec7053bbd926f1ba81191a287d
    }
}
#include "sort.h"

/**
 * sorted_insert - inserts a new node in a sorted list.
 * @list: The list in which a new node is to be inserted.
 * @new_node: The new node to be inserted in the list.
 * Return: None
 */
void sorted_insert(listint_t **list, listint_t *new_node)
{
    listint_t *current;

    if (*list == NULL || (*list)->n >= new_node->n)
    {
        new_node->next = *list;
        new_node->prev = NULL;
        if (*list != NULL)
            (*list)->prev = new_node;
        *list = new_node;
    }
    else
    {
        current = *list;
        while (current->next != NULL && current->next->n < new_node->n)
            current = current->next;

        new_node->next = current->next;
        if (current->next != NULL)
            current->next->prev = new_node;
        current->next = new_node;
        new_node->prev = current;
    }

    print_list(*list);
}

/** 
 * insertion_sort_list - Sorts  doubly linked list of integers in ascending
 * order using the inserton sort algorithm.
 * @list: The list to be sorted.
 * Return: None
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *print_ptr;
    listint_t *current = *list;

    while (current != NULL)
    {
        listint_t *next = current->next;

        listint_t *temp = *list;
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
    }
}

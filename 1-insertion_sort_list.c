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
}

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

        sorted_insert(&sorted, current);
        print_list(list);
        current = next;
    }

    *list = sorted;
}

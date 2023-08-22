#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes a node at a specific index from a list.
 * @head: A pointer to the first element of a list.
 * @index: The index of the node to delete.
 *
 * Return: 1 on success, -1 on failure.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current;
    unsigned int i;

    /* Check if the list is empty */
    if (*head == NULL)
        return (-1);

    current = *head;

    /* Special case: Delete the head node */
    if (index == 0)
    {
        *head = current->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(current);
        return (1);
    }

    /* Traverse to the node to delete */
    for (i = 0; current != NULL && i < index; i++)
        current = current->next;

    /* If the node was not found at the given index */
    if (current == NULL)
        return (-1);

    /* Update the previous and next pointers of neighboring nodes */
    if (current->prev != NULL)
        current->prev->next = current->next;
    if (current->next != NULL)
        current->next->prev = current->prev;

    /* Delete the current node */
    free(current);
    return (1);
}


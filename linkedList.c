#include <stdio.h>
#include <stdlib.h>

/**
 * Linked list interface
 * - getLen
 * - printList
 * - push
 */

struct Node
{
    int value;
    struct Node *next;
};

struct Node *head = NULL;

int getLen(struct Node *head)
{
    int len = 0;

    if (head == NULL)
    {
        return len;
    }

    while (head->next != NULL)
    {
        head = head->next;
        len++;
    };

    len++;

    return len;
}

void push(struct Node **headRef, int value)
{
    struct Node *current = *headRef;

    printf("Adding new node with value: %d\n", value);

    if (current == NULL)
    {
        (*headRef) = malloc(sizeof(struct Node));
        (*headRef)->value = value;
        (*headRef)->next = NULL;
        return;
    }

    while (current->next != NULL)
    {
        current = current->next;
    }

    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;

    current->next = newNode;
}

void printList(struct Node *headRef)
{
    struct Node *current = headRef;

    if (current == NULL)
    {
        puts("The list is empty");
        return;
    }

    while (current != NULL)
    {
        printf("Value is %d\n", current->value);
        current = current->next;
    }
}

int main()
{
    printList(head);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);

    printf("Length is %d\n", getLen(head));
    printList(head);

    return 0;
}

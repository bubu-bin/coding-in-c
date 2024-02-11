#include <stdio.h>
#include <stdlib.h>

/**
 * Linked list interface
 * - getLen
 * - printList
 * - push
 * - getNth
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

void printList(struct Node *head)
{
    struct Node *current = head;

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

int getNth(int index, struct Node *head)
{
    int len = getLen(head);

    if (index >= len)
    {
        printf("The index is greater than the length. Skipping execution");
        return -1;
    }

    struct Node *current = head;
    int currentIndex = 0;

    while (currentIndex != index)
    {
        currentIndex++;
        current = current->next;
    }

    printf("Node found at index: %d with value: %d\n", index, current->value);
    return current->value;
}

int main()
{
    push(&head, 122);
    push(&head, 12);
    push(&head, 42);

    getNth(3, head);

    return 0;
}

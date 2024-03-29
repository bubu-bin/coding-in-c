#include <stdio.h>
#include <stdlib.h>

/**
 * Linked list interface
 * - getLen
 * - printList
 * - push
 * - getNth
 * - clear
 * - set
 * - indexOf
 * - unshift
 * - removeByIndex
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

struct Node *getNth(struct Node *head, int index)
{
    struct Node *current = head;
    int currentIndex = 0;

    while (current != NULL && currentIndex != index)
    {
        current = current->next;
        currentIndex++;
    }

    if (current == NULL)
    {
        printf("Node with index: %d not found\n", index);
        return NULL;
    }

    printf("Node found at index: %d with value: %d\n", index, current->value);
    return current;
}

void clear(struct Node **head)
{
    struct Node *current = *head;

    while (current != NULL)
    {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }

    *head = NULL;
    puts("cleared");
}

void set(struct Node *head, int index, int value)
{
    struct Node *node = getNth(head, index);

    if (node != NULL)
    {
        printf("Updated node at index: %d with value: %d\n", index, value);
        node->value = value;
    }
}

int indexOf(struct Node *head, int value)
{
    struct Node *current = head;
    int currentIndex = 0;

    while (current != NULL)
    {
        if (current->value == value)
        {
            printf("Node with value %d found at index %d", value, currentIndex);
            return currentIndex;
        }

        currentIndex++;
        current = current->next;
    }

    printf("Node with value: %d not found\n", value);
    return -1;
}

void unshift(struct Node **head, int value)
{
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->value = value;
    newNode->next = *head;
    *head = newNode;
}

void removeByIndex(struct Node **head, int index)
{
    if (*head == NULL)
    {
        printf("List is empty, nothing to remove.\n");
        return;
    }

    if (index == 0)
    {
        struct Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    struct Node *current = *head;
    struct Node *prev = NULL;
    int currentIndex = 0;

    while (current != NULL && index != currentIndex)
    {
        prev = current;
        current = current->next;
        currentIndex++;
    }

    if (current == NULL)
    {
        printf("Node at index: %d not found\n", index);
        return;
    }

    prev->next = current->next;
    free(current);
    printf("Node found at index: %d\n", index);
}

int main()
{
    push(&head, 29);
    push(&head, 21);
    push(&head, 24);
    push(&head, 22);

    removeByIndex(&head, 1);
    printList(head);

    return 0;
}

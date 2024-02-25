#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Hash table interface
 * - add
 * - get
 * - set
 * - delete
 */

/**
 * @todo
 * - update hash table to allow for chaining in case of collisions
 * - implement get
 * - implement set
 * - implement delete
 */

struct Entry
{
    char *key;
    int value;
};

struct HashTable
{
    unsigned int size;
    struct Entry *entries;
};

unsigned long hashFunction(char *str)
{
    unsigned long hash = 0;

    while (*str)
    {
        hash += (unsigned char)(*str);
        str++;
    }

    return hash;
}

struct HashTable *createHashTable(int size)
{
    struct HashTable *table = malloc(sizeof(struct HashTable));

    table->size = size;

    table->entries = malloc(sizeof(struct Entry) * size);
    for (int i = 0; i < size; i++)
    {
        table->entries[i].key = NULL;
    }

    return table;
}

void add(struct HashTable *table, char *key, int value)
{
    if (table = NULL)
    {
        return;
    }

    unsigned long hash = hashFunction(key);
    unsigned int index = hash % table->size;

    /** @note temp until hash table will use the collisiong handling */
    free(table->entries[index].key);

    table->entries[index].key = strdup(key);
    table->entries[index].value = value;
}

void print(struct HashTable *table)
{
    for (int i = 0; i < table->size; i++)
    {
        struct Entry entry = table->entries[i];
        printf("[I]: %d [K] %s [V] %d\n", i, entry.key, entry.value);
    }
}

int main()
{
    struct HashTable *table = createHashTable(11);

    add(table, "key1", 100);
    print(table);

    return 0;
}

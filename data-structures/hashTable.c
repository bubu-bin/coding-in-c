#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Entry
{
    char *key;
    int value;
    struct Entry *next;
};

struct HashTable
{
    unsigned int size;
    struct Entry *entries;
};

unsigned int hashFunction(char *str)
{
    unsigned int hash = 0;

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
        table->entries[i].next = NULL;
    }

    return table;
}

void add(struct HashTable *table, char *key, int value)
{
    if (table == NULL)
    {
        return;
    }

    unsigned int hash = hashFunction(key);
    unsigned int index = hash % table->size;

    struct Entry *entry = &table->entries[index];

    if (entry->key == NULL)
    {
        entry->key = strdup(key);
        entry->value = value;
        return;
    }

    while (entry != NULL)
    {
        if (strcmp(entry->key, key) == 0)
        {
            // Key already exists, update the value
            entry->value = value;
            return;
        }

        if (entry->next == NULL)
        {
            break;
        }

        entry = entry->next;
    }

    struct Entry *newEntry = malloc(sizeof(struct Entry));
    newEntry->key = strdup(key);
    newEntry->value = value;
    newEntry->next = NULL;

    entry->next = newEntry;
}

void printTable(struct HashTable *table)
{
    if (table == NULL)
    {
        return;
    }

    for (int i = 0; i < table->size; i++)
    {
        struct Entry *entry = &table->entries[i];

        if (entry->key == NULL)
        {
            printf("[Index %d]: <empty>\n", i);
            continue;
        }

        int listPos = 0;

        while (entry != NULL)
        {
            printf("[Index %d]: [ListPos]: %d [Key]: %s [Value]: %d\n", i, listPos, entry->key, entry->value);
            entry = entry->next;
            listPos++;
        }
    }
}

int main()
{
    struct HashTable *table = createHashTable(11);

    add(table, "key1", 100);
    add(table, "key1", 102);

    add(table, "key2", 123);
    add(table, "key5", 1241);
    add(table, "key10", 241);

    add(table, "2yek", 1231);
    printTable(table);

    return 0;
}

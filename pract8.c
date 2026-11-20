//library book indexing using hashing
#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

void insert(int id)
{
    int index = id % SIZE;
    int start = index;

    while (hashTable[index] != -1)
    {
        index = (index + 1) % SIZE;

        if (index == start)
        {
            printf("Hash table is full!\n");
            return;
        }
    }

    hashTable[index] = id;
    printf("Book ID %d inserted at index %d\n", id, index);
}

void search(int id)
{
    int index = id % SIZE;
    int start = index;

    while (hashTable[index] != -1)
    {
        if (hashTable[index] == id)
        {
            printf("Book ID %d found at index %d\n", id, index);
            return;
        }

        index = (index + 1) % SIZE;

        if (index == start)
            break;
    }

    printf("Book ID %d not found\n", id);
}

int main()
{
    int i, n, id, key;

    for (i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    printf("Enter number of book IDs: ");
    scanf("%d", &n);

    printf("Enter book IDs:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &id);
        insert(id);
    }

    printf("\nHash Table:\n");
    for (i = 0; i < SIZE; i++)
    {
        if (hashTable[i] == -1)
            printf("Index %d: Empty\n", i);
        else
            printf("Index %d: %d\n", i, hashTable[i]);
    }

    printf("\nEnter book ID to search: ");
    scanf("%d", &key);

    search(key);

    return 0;
}

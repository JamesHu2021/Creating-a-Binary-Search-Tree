#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE  100

/*

//另外一种方式
typedef struct Entry {
    int key;
    int value;
    struct Entry *next;  // 链表指针，用于处理冲突
    //// Pointer for linked list, used for collision resolution
} Entry;


Collision Resolution Methods:

Open Addressing (Linear Probing): When a slot is occupied, search for the next available slot linearly until an empty slot is found or the entire table is traversed. This can be achieved using methods like linear probing or quadratic probing.
Chaining (Linked Lists): Each slot in the hash table is the head of a linked list. When a collision occurs, the new key-value pair is inserted into the linked list.
Rehashing: Another hash function can be used to handle collisions. If a collision occurs with the first hash function, a second hash function is applied to find a new position.
Secondary Hash Table: In the case of collisions, a new hash table can be created for the conflicting slots, and the elements are inserted into the new table. This process can be recursive, forming multiple levels of hash tables.
*/

typedef struct {
  int key;
  int value;
}Entry;

typedef struct {
  Entry * Bucket[TABLE_SIZE];
  size_t tableSize;
} Hash_Table;

size_t hash_function(int key)
{
  return key % TABLE_SIZE;
}

void insert(Hash_Table * table, int key, int value)
{
  size_t index = hash_function(key);

  // 处理冲突：这里简单地使用开放寻址法，可以选择其他方法如链地址法等
  while (table->Bucket[index] != NULL)
  {
    index = (index + 1) % TABLE_SIZE;
  }

  Entry * tmp = malloc(sizeof(Entry));
  if (tmp == NULL)
  {
    printf("Memory allocate failed.");
    exit(-1);
  }
  tmp->key = key;
  tmp->value = value;
  //tmp->next = table->Bucket[index]; //for linked list, used for collision resolution
  table->Bucket[index] = tmp;
  table->tableSize++;

  // printf("insert %d %d : %d %d\n", key, value, tmp->key, tmp->value);
}

int Lookup(Hash_Table * table, int key)
{
  size_t index = hash_function(key);

  // printf("Lookup 01 : %d %d \n", key, index);

/*
  //for linked list, used for collision resolution
  Entry * cur = table->Bucket[index];
  while (cur != NULL)
  {
    if (cur->key == key)
      return cur->value;
    cur = cur->next;
  }
  return -1;
*/

  // 处理冲突
  while ((table->Bucket[index] != NULL) && (table->Bucket[index]->key != key)) {
    index = (index + 1)%TABLE_SIZE;//;
  }

  // 如果找到了对应的键值对
  if (table->Bucket[index] != NULL)
  {
    return table->Bucket[index]->value;
  }
  else {
    return -1;// 未找到
  }
}

void iniHashTable(Hash_Table * table)
{
  table->tableSize = 0;
  for (int i = 0; i<TABLE_SIZE; ++i)
  {
    table->Bucket[i] = NULL;
  }
}
/*
// Remove a key-value pair from the hash table
void removeEntry(Hash_Table *hashTable, int key) {
    size_t index = hash_function(key);

    Entry *current = hashTable->Bucket[index];
    Entry *prev = NULL;

    while (current != NULL) {
        if (current->key == key) {
            if (prev == NULL) {
                // Remove the first entry in the linked list
                hashTable->Bucket[index] = current->next;
            } else {
                // Remove from the middle or end of the linked list
                prev->next = current->next;
            }

            free(current);
            hashTable->tableSize--;
            return;
        }

        prev = current;
        current = current->next;
    }
}

// Free the memory allocated for the hash table
void freeHashTable(Hash_Table *hashTable) {
    for (size_t i = 0; i < TABLE_SIZE; ++i) {
        Entry *current = hashTable->Bucket[i];
        while (current != NULL) {
            Entry *next = current->next;
            free(current);
            current = next;
        }
    }
}
*/


int main() {

  Hash_Table myHashTable;
  iniHashTable(&myHashTable);
  insert(&myHashTable, 31, 100);
  insert(&myHashTable, 41, 200);

  printf("The value for key 31 is %d\n", Lookup(&myHashTable, 31));
  printf("The value for key 41 is %d\n", Lookup(&myHashTable, 41));
  return 0;
}

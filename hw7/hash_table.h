#ifndef HASH_TABLE_H
#define HASH_TABLE_H

typedef struct Customer {
    char *email;
    char *name;
    int shoe_size;
    char *favorite_food;
} Customer;

typedef struct Node {
    Customer *data;
    struct Node *next;
} Node;

typedef struct HashTable {
    Node **buckets;
    int bucket_count;
} HashTable;

HashTable *initialize_table(int bucket_count);

void free_table(HashTable *table);

void add_customer(HashTable *table, const char *email, const char *name, int shoe_size, const char *favorite_food);
Customer *lookup_customer(HashTable *table, const char *email);

int delete_customer(HashTable *table, const char *email);

void list_customers(HashTable *table);

#endif

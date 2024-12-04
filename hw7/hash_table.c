#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"

static unsigned int hash(const char *key, int bucket_count) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash * 31) + *key++;
    }
    return hash % bucket_count;
}

HashTable *initialize_table(int bucket_count) {
    HashTable *table = malloc(sizeof(HashTable));
    table->buckets = malloc(sizeof(Node *) * bucket_count);
    table->bucket_count = bucket_count;
    for (int i = 0; i < bucket_count; i++) {
        table->buckets[i] = NULL;
    }
    return table;
}

void free_table(HashTable *table) {
    for (int i = 0; i < table->bucket_count; i++) {
        Node *node = table->buckets[i];
        while (node) {
            Node *temp = node;
            node = node->next;
            free(temp->data->email);
            free(temp->data->name);
            free(temp->data->favorite_food);
            free(temp->data);
            free(temp);
        }
    }
    free(table->buckets);
    free(table);
}

void add_customer(HashTable *table, const char *email, const char *name, int shoe_size, const char *favorite_food) {
    unsigned int index = hash(email, table->bucket_count);
    Node *node = table->buckets[index];
    while (node) {
        if (strcmp(node->data->email, email) == 0) {
            free(node->data->name);
            free(node->data->favorite_food);
            node->data->name = strdup(name);
            node->data->favorite_food = strdup(favorite_food);
            node->data->shoe_size = shoe_size;
            return;
        }
        node = node->next;
    }
    Customer *customer = malloc(sizeof(Customer));
    customer->email = strdup(email);
    customer->name = strdup(name);
    customer->shoe_size = shoe_size;
    customer->favorite_food = strdup(favorite_food);
    Node *new_node = malloc(sizeof(Node));
    new_node->data = customer;
    new_node->next = table->buckets[index];
    table->buckets[index] = new_node;
}

Customer *lookup_customer(HashTable *table, const char *email) {
    unsigned int index = hash(email, table->bucket_count);
    Node *node = table->buckets[index];
    while (node) {
        if (strcmp(node->data->email, email) == 0) {
            return node->data;
        }
        node = node->next;
    }
    return NULL;
}

int delete_customer(HashTable *table, const char *email) {
    unsigned int index = hash(email, table->bucket_count);
    Node *node = table->buckets[index];
    Node *prev = NULL;
    while (node) {
        if (strcmp(node->data->email, email) == 0) {
            if (prev) {
                prev->next = node->next;
            } else {
                table->buckets[index] = node->next;
            }
            free(node->data->email);
            free(node->data->name);
            free(node->data->favorite_food);
            free(node->data);
            free(node);
            return 1;
        }
        prev = node;
        node = node->next;
    }
    return 0;
}

void list_customers(HashTable *table) {
    for (int i = 0; i < table->bucket_count; i++) {
        Node *node = table->buckets[i];
        while (node) {
            Customer *customer = node->data;
            printf("email: %s\nname: %s\nshoe size: %d\nfood: %s\n",
                   customer->email, customer->name, customer->shoe_size, customer->favorite_food);
            node = node->next;
        }
    }
}

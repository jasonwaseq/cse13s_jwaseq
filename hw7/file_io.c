#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_io.h"
#include "hash_table.h"

void load_customers(HashTable *table, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) return;
    char line[512];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;
        char *email = strtok(line, "\t");
        char *name = strtok(NULL, "\t");
        char *shoe_size_str = strtok(NULL, "\t");
        char *favorite_food = strtok(NULL, "\t");
        if (email && name && shoe_size_str && favorite_food) {
            int shoe_size = atoi(shoe_size_str);
            add_customer(table, email, name, shoe_size, favorite_food);
        }
    }
    fclose(file);
}

void save_customers(HashTable *table, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) return;
    for (int i = 0; i < table->bucket_count; i++) {
        Node *node = table->buckets[i];
        while (node) {
            Customer *customer = node->data;
            fprintf(file, "%s\t%s\t%d\t%s\n", customer->email, customer->name, customer->shoe_size, customer->favorite_food);
            node = node->next;
        }
    }
    fclose(file);
}

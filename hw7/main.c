#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"
#include "file_io.h"

#define BUCKET_COUNT 10

void handle_add(HashTable *table);

void handle_lookup(HashTable *table);

void handle_delete(HashTable *table);

void handle_list(HashTable *table);

void handle_save(HashTable *table, const char *filename);

int main(void) {
    HashTable *table = initialize_table(BUCKET_COUNT);
    load_customers(table, "customers.tsv");
    char command[16];
    while (1) {
        printf("command: ");
        if (fgets(command, sizeof(command), stdin) == NULL) break;
        command[strcspn(command, "\n")] = 0; 
        if (strcmp(command, "quit") == 0) {
            break;
        } else if (strcmp(command, "add") == 0) {
            handle_add(table);
        } else if (strcmp(command, "lookup") == 0) {
            handle_lookup(table);
        } else if (strcmp(command, "delete") == 0) {
            handle_delete(table);
        } else if (strcmp(command, "list") == 0) {
            handle_list(table);
        } else if (strcmp(command, "save") == 0) {
            handle_save(table, "customers.tsv");
        } else {
            printf("Unknown command.\n");
        }
    }
    save_customers(table, "customers.tsv");
    free_table(table);
    return 0;
}

void handle_add(HashTable *table) {
    char email[256], name[256], food[256];
    int shoe_size;
    printf("email address? ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = 0;
    printf("name? ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;
    printf("shoe size? ");
    scanf("%d", &shoe_size);
    while (getchar() != '\n'); 
    printf("favorite food? ");
    fgets(food, sizeof(food), stdin);
    food[strcspn(food, "\n")] = 0;
    if (strchr(email, '\t') || strchr(name, '\t') || strchr(food, '\t')) {
        printf("Invalid input: fields cannot contain tabs.\n");
        return;
    }
    add_customer(table, email, name, shoe_size, food);
}

void handle_lookup(HashTable *table) {
    char email[256];
    printf("email address? ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = 0;
    Customer *customer = lookup_customer(table, email);
    if (customer) {
        printf("email: %s\nname: %s\nshoe size: %d\nfood: %s\n",
               customer->email, customer->name, customer->shoe_size, customer->favorite_food);
    } else {
        printf("Customer not found.\n");
    }
}

void handle_delete(HashTable *table) {
    char email[256];
    printf("email address? ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = 0;
    if (delete_customer(table, email)) {
        printf("Customer deleted.\n");
    } else {
        printf("Customer not found.\n");
    }
}

void handle_list(HashTable *table) {
    list_customers(table);
}

void handle_save(HashTable *table, const char *filename) {
    save_customers(table, filename);
    printf("Database saved to %s\n", filename);
}

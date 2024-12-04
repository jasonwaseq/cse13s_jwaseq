#ifndef FILE_IO_H
#define FILE_IO_H
#include "hash_table.h"

void load_customers(HashTable *table, const char *filename);
void save_customers(HashTable *table, const char *filename);

#endif

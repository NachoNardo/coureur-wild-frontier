#ifndef INVENTORY_H
#define INVENTORY_H

#include <stdlib.h>

typedef struct {
    int index;
    int quantity;
    char name[100];
} item;

typedef struct item_node {
    item data;
    struct item_node* next;
} item_node;

typedef struct {
    item_node* weapons;
    item_node* consumables;
    item_node* materials;
    item_node* plants;
    item_node* food;
    item_node* goods;
    item_node* equipment;
} inventory;

#endif

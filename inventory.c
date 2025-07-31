#include <stdio.h>
#include <string.h>
#include <string.h>
#include "inventory.h"

void add_item(item_node** list, item new_item) {
    item_node* existing = find_item(*list, new_item.index);
    if (existing) {
        existing->data.quantity += new_item.quantity;
        return;
    }

    item_node* new_node = malloc(sizeof(item_node));
    if (!new_node) return;

    new_node->data = new_item;
    new_node->next = *list;
    *list = new_node;
}


char* list_items(item_node* list) {
    if (!list) {
        char* empty = malloc(20);
        if (empty) strcpy(empty, "No items.\n");
        return empty;
    }

    size_t capacity = 256;
    char* result = malloc(capacity);
    if (!result) return NULL;

    result[0] = '\0';
    size_t length = 0;

    while (list) {
        char buffer[200];
        snprintf(buffer, sizeof(buffer), "Index: %d | Name: %s | Quantity: %d\n",
                 list->data.index,
                 list->data.name,
                 list->data.quantity);

        size_t buffer_len = strlen(buffer);
        if (length + buffer_len + 1 >= capacity) {
            capacity *= 2;
            char* temp = realloc(result, capacity);
            if (!temp) {
                free(result);
                return NULL;
            }
            result = temp;
        }

        strcat(result, buffer);
        length += buffer_len;
        list = list->next;
    }

    return result;
}

item_node* find_item(item_node* list, int index) {
    while (list) {
        if (list->data.index == index) return list;
        list = list->next;
    }
    return NULL;
}

int remove_item(item_node** list, int index) {
    item_node* prev = NULL;
    item_node* curr = *list;

    while (curr) {
        if (curr->data.index == index) {
            if (prev) prev->next = curr->next;
            else *list = curr->next;

            free(curr);
            return 1;
        }
        prev = curr;
        curr = curr->next;
    }
    return 0;
}

void free_item_list(item_node* list) {
    while (list) {
        item_node* temp = list;
        list = list->next;
        free(temp);
    }
}

void free_inventory(inventory* inv) {
    free_item_list(inv->weapons);
    free_item_list(inv->consumables);
    free_item_list(inv->materials);
    free_item_list(inv->plants);
    free_item_list(inv->food);
    free_item_list(inv->goods);
    free_item_list(inv->equipment);
}

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "dynlist.h"


/*
Node *remove_from(DynList *list, Node *select_node) {
    if (select_node->prev) {
        select_node->prev->next = select_node->next;
    }
    if (select_node->next) {
        select_node->next->prev = select_node->prev;
    }
    if (!select_node->prev) {
        list->head = select_node->next;                             //Если удаляем крайний элемент.
    }
    if (!select_node->next) {
        list->tail = select_node->prev;
    }
    list->len--;
    return select_node;
}*/
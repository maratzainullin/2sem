#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "dynlist.h"


/*DynList::Node *DynList::get_to(int position) {
    Node *temp = head;
    int i = 1;
    while (i < position) {
        if (!temp) throw "tried to get to unreacheable position";
        temp = temp->next;
        i++;
    }
    return temp;
}*/



/* push_back и insert можно объединить
 */
/*void DynList::insert(Data_T data, int position) {
    //Добавляет элемент в указанную позицию, остальные элементы сдвигает(список удлиняется на один элемент)
    Node *insert_node = new Node(data);
    Node *select_node = get_to(position);
    insert_node->data = data;
    insert_node->prev = select_node->prev;
    insert_node->next = select_node;
    if (select_node->prev) {
        select_node->prev->next = insert_node;
    }
    select_node->prev = insert_node;
    if (!insert_node->prev) {
        head = insert_node;
    }
    len++;
}*/


/*DynList::Node *DynList::pop(int position) {
    Node *select_node = get_to(position);                  //Если удаляем не крайний элемент.
    if (select_node->prev) {
        select_node->prev->next = select_node->next;
    }
    if (select_node->next) {
        select_node->next->prev = select_node->prev;
    }
    if (!select_node->prev) {
        head = select_node->next;                             //Если удаляем крайний элемент.
    }
    if (!select_node->next) {
        tail = select_node->prev;
    }
    //delete select_node;
    len--;
    return select_node;
}*/


/*std::ostream &operator<<(std::ostream &out_stream, const DynList &list) {
   // if (list == nullptr or len == 0) {
    //    throw "\nList is not created! Select option.\n";
    //}
    //каждый тип данных имеет свою длину при выводе. out_line - число,
    //показывающее сколько данных будет выведено на одной строке.
    int k = list.head->data.len_of_line;
    DynList::Node *temp = list.head;
    for (int i = 1; i <= list.len; i++) {
        if (k == list.head->data.len_of_line) {
            out_stream << "\n*";
            k = 0;
        }
        out_stream << std::setw(5) << i << ": " << temp->data;
        temp = temp->next;
        k++;
    }
    out_stream << "\n";
    return out_stream;
}*/


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




/*int DynList::first_match(Data_T data) {
    Node *temp = head;
    int i = 1;
    while (temp->data.x != data.x or temp->data.y != data.y) {
        temp = temp->next;
        i++;
        if (temp == nullptr)
            throw "Node not found. Try againSSS. ";
    };
    return i;
}


int DynList::last_match(Data_T data) {
    Node *temp = tail;
    int i = len;
    while ((temp->data.x != data.x) or (temp->data.y != data.y)) {
        temp = temp->prev;
        i--;
        if (temp == nullptr)
            throw "Element not found. Select option.\n";
    };
    return i;
}*/
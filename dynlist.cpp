#include "dynlist.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>

#define MULTIPLIER 10
#define OUT_LEN 5


DynList::Node *DynList::get_to(int position) {
    Node *temp = head;
    int i = 1;
    while (i < position) {
        if (!temp) throw "tried to get to unreacheable position";
        temp = temp->next;
        i++;
    }
    return temp;
}


void DynList::init_rand_list() {
    std::cout << "Enter the length of the list:\n";
    std::cin >> len;
    for (int i = 0; i < len; i++) {
        Data_t data(rand()% MULTIPLIER, rand()% MULTIPLIER); //СОЗДАТЬ КОНСТРУКТОР С ДВУМЯ АРГУМЕНТАМИ
        //data.x = rand()% MULTIPLIER;
        //data.y = rand()% MULTIPLIER;
        push_back(data);
    }
}


int DynList::first_match(Data_t data) {
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


int DynList::last_match(Data_t data) {
    Node *temp = tail;
    int i = len;
    while ((temp->data.x != data.x) or (temp->data.y != data.y)) {
        temp = temp->prev;
        i--;
        if (temp == nullptr)
            throw "Element not found. Select option.\n";
    };
    return i;
}


void DynList::push_back(Data_t data) {
    Node *temp = new Node(data);
    temp->next = nullptr;
    temp->data.x = data.x;
    temp->data.y = data.y;
    temp->data.r = data.r;
    if (head) {                                   // Если список не пуст
        temp->prev = tail;                        // Указываем адрес на предыдущий элемент в соотв. поле
        tail->next = temp;                        // Указываем адрес следующего за хвостом элемента
        tail = temp;                              //Меняем адрес хвоста
    } else {                                            //Если список пустой
        temp->prev = nullptr;                           // Предыдущий элемент указывает в пустоту
        head = tail = temp;                 // Голова=Хвост=тот элемент, что сейчас добавили
    }
}


DynList::Node *DynList::pop(int position) {
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
}


std::ostream &operator<<(std::ostream &out, const DynList &list) {
    /*if (list == nullptr or len == 0) {
        throw "\nList is not created! Select option.\n";
    }*/
    int k = OUT_LEN;
    DynList::Node *temp = list.head;
    for (int i = 1; i <= list.len; i++) {
        if (k == OUT_LEN) {
            out << "\n*";
            k = 0;
        }
        out << std::setw(7) << std::fixed << std::setprecision(0) << i << ": ("
            << std::setw(2) << temp->data.x << "; "
            << std::setw(2) << temp->data.y << ") "
            << std::setw(5) << std::fixed << std::setprecision(2) << temp->data.r;
        temp = temp->next;
        k++;
    }
    out << "\n";
    return out;
}


std::istream &operator>>(std::istream &in, DynList::Data_t &data) {
    /*if (list == nullptr or len == 0) {
        throw "\nList is not created! Select option.\n";
    }*/

    //std::cout << "Enter data:\n";
    in >> data.y >> data.x;

    return in;
}


/*void delete_list(DynList *list) {
    Node *temp;
    temp = list->tail;
    Node *prev;
    while (temp) {
        prev = temp->prev;
        delete temp;
        temp = prev;
    }
    delete list;
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

void DynList::insert(Data_t data, int position) {
    //Добавляет элемент в указанную позицию, остальные элементы сдвигает(список удлиняется на один элемент)
    Node *insert_node = new Node(data);
    Node *select_node = get_to(position);
    insert_node->data.x = data.x;
    insert_node->data.y = data.y;
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
}
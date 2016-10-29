#ifndef INC_2SEM_DYNLIST_H
#define INC_2SEM_DYNLIST_H

#include <ostream>
#include <iomanip>
#include <stdlib.h>
#include "data.h"
#include <string>


template<class Data_T>
class DynList {
public:
    struct Node {
        Node *next, *prev;
        Data_T data;

        Node(Data_T init_data) : next(nullptr), prev(nullptr), data(init_data) {}       //контсруктор
    };

private:
    Node *head, *tail;
    int len;

public:
    DynList() : head(nullptr), tail(nullptr), len(0) {}

    ~DynList() {
        Node *temp;
        temp = tail;
        Node *prev;
        while (temp) {
            prev = temp->prev;
            delete temp;
            temp = prev;
        }
    }

    Node *get_to(int position);

    Node *pop(int position = 0);

    void push_back(Data_T data);

    void insert(Data_T data, int position);

    void print();//Нет корректного вывода для общего типа.

    int first_match(Data_T data);//Требуют перегрузки !=.

    int last_match(Data_T data);

    /*Не работает :с
     * friend std::ostream &operator<<(std::ostream &out_stream, const DynList &list);*/
};


template<class Data_T>
void DynList<Data_T>::push_back(Data_T data) {
    Node *temp = new Node(data);
    temp->next = nullptr;
    temp->data = data;
    if (head) {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    } else {
        temp->prev = nullptr;
        head = tail = temp;
    }
    len++;
}


template<class Data_T>
void DynList<Data_T>::print() {
    //int k = head->data.len_of_line;
    int k = 3;
    Node *temp;
    temp = head;
    for (int i = 1; i <= len; i++) {
        //if (k == head->data.len_of_line) {
        if (k == 3) {
            std::cout << "\n*";
            k = 0;
        }
        std::cout << std::setw(5) << i << ": " << temp->data;
        temp = temp->next;
        k++;
    }
    std::cout << "\n";
    return;
}


template<class Data_T>
void DynList<Data_T>::insert(Data_T data, int position) {
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
}


template<class Data_T>
typename DynList<Data_T>::Node *DynList<Data_T>::pop(int position) {
    Node *select_node = get_to(position);
    if (select_node->prev) {
        select_node->prev->next = select_node->next;
    }
    if (select_node->next) {
        select_node->next->prev = select_node->prev;
    }
    if (!select_node->prev) {
        head = select_node->next;
    }
    if (!select_node->next) {
        tail = select_node->prev;
    }
    len--;
    return select_node;
}        //зачем здесь typename?


template<class Data_T>
typename DynList<Data_T>::Node *DynList<Data_T>::get_to(int position) {
    Node *temp = head;
    int i = 1;
    while (i < position) {
        if (!temp) throw "tried to get to unreacheable position";
        temp = temp->next;
        i++;
    }
    return temp;
}     //зачем здесь typename?


template<class Data_T>
int DynList<Data_T>::first_match(Data_T data) {
    Node *temp = head;
    int i = 1;
    while (temp->data != data) {
        temp = temp->next;
        i++;
        if (temp == nullptr)
            throw "Node not found. Try againSSS. ";
    };
    return i;
}


template<class Data_T>
int DynList<Data_T>::last_match(Data_T data) {
    Node *temp = tail;
    int i = len;
    while (temp->data != data) {
        temp = temp->prev;
        i--;
        if (temp == nullptr)
            throw "Element not found. Select option.\n";
    };
    return i;
}


/*template<class Value_T>
std::ostream &operator<<(std::ostream &out_stream, const DynList<Value_T> &list) {
    // if (list == nullptr or len == 0) {
    //    throw "\nList is not created! Select option.\n";
    //}
    //каждый тип данных имеет свою длину при выводе. out_line - число,
    //показывающее сколько данных будет выведено на одной строке.
    int k = list.head->data.len_of_line;
    Node *temp;
    temp = list.head;
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

#endif //INC_2SEM_DYNLIST_H
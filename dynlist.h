#ifndef INC_2SEM_DYNLIST_H
#define INC_2SEM_DYNLIST_H

#include <ostream>
#include <stdlib.h>
#include "data.h"

/* Пoльзуясь библиотекой, знай, что она бросает исключение string. */


template<class Data_T>
class DynList {
public:


    struct Node {
        int i;
        Node *next, *prev;
        Data_T data;

        Node(Data_T init_data) : next(nullptr), prev(nullptr), data(init_data) {}       //контсруктор
    };

private:
    Node *head;
    Node *tail;
    int len;

public:
    //Создание пустого списка.
    DynList() : head(nullptr), tail(nullptr), len(0) {}

    // бывший delete_list()
    ~DynList() {
        Node *temp;
        temp = tail;
        Node *prev;
        while (temp) {
            prev = temp->prev;
            delete temp;
            temp = prev;
        }
    };

    void init_rand_list();

    //int first_match(Data_T data);

    //int last_match(Data_T data);

    void push_back(Data_T data);

    Node *get_to(int position);

    Node *pop(int position = 0);

    void insert(Data_T data, int position);

    void print(DynList<Data_T> &list);

    // требуется короткое описание

    //Data_T remove(Node *select_node);*/

    // бывший void print_list();
    //friend std::ostream &operator<<(std::ostream &out_stream, const DynList &list);
};

template<class Data_T>
void DynList<Data_T>::init_rand_list() {
    std::cout << "Enter the length of the list:\n";
    std::cin >> len;
    for (int i = 0; i < len; i++) {
        Data_T data;
        data.rand(P_MULTIPLIER);
        push_back(data);
    }
}

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
}

template<class Data_T>
void DynList<Data_T>::print(DynList<Data_T> &list) {
    int k = list.head->data.len_of_line;
    Node *temp;
    temp = list.head;
    for (int i = 1; i <= list.len; i++) {
        if (k == list.head->data.len_of_line) {
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

/*template<class Data_T>
std::ostream &operator<<(std::ostream &out_stream, const DynList<Data_T> &list) {
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



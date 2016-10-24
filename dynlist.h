#ifndef INC_2SEM_DYNLIST_H
#define INC_2SEM_DYNLIST_H

#include <ostream>
#include <stdlib.h>
#include "data.h"

/* Пoльзуясь библиотекой, знай, что она бросает исключение string. */


struct DynList {
public:
    typedef Point Data_t;

    struct Node {
        int i;
        Node *next, *prev;
        Data_t data;

        Node(Data_t init_data) : next(nullptr), prev(nullptr), data(init_data) {}       //контсруктор
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

    int first_match(Data_t data);

    int last_match(Data_t data);

    void push_back(Data_t data);

    Node *get_to(int position);

    Node *pop(int position = 0);

    void insert(Data_t data, int position);

    // требуется короткое описание

    //Data_t remove(Node *select_node);*/

    // бывший void print_list();
    friend std::ostream &operator<<(std::ostream &out_stream, const DynList &list);
};


#endif //INC_2SEM_DYNLIST_H



#ifndef INC_2SEM_DYNLIST_H
#define INC_2SEM_DYNLIST_H

#include <ostream>
#include <iomanip>
#include <stdlib.h>
#include "data.h"
#include <string>

/* Выдает исключения
 * типа string.
 * Требует перегрузки == и !=.
 */


template<class Data_T>
class DynList {
public:
    struct Node {
        Node *next, *prev;
        Data_T data;

        Node(Data_T init_data) : next(nullptr), prev(nullptr), data(init_data) {}
    };

private:
    Node *head, *tail;
    int len;

public:
    DynList() : head(nullptr), tail(nullptr), len(0) {}

    Node get_head() {
        if (head == nullptr) throw "List is empty!\n";
        return *head;
    }

    Node get_tail() {
        if (tail == nullptr) throw "List is empty!\n";
        return *tail;
    }

    ~DynList() {
        Node *temp;
        temp = tail;
        Node *prev;
        while (temp) {
            prev = temp->prev;
            delete temp; //если я так удалю temp, temp->next, temp->prev и temp->data тоже удаляться?
            temp = prev;
        }
    }

    void empty_list();

    int get_len();

    bool exist(Data_T data);

    Node *get_Node(int position);

    Data_T pop(int position = 0);

    void remove(Data_T data);

    void push_back(Data_T data);

    void insert(Data_T data, int position);

    void print(int len_of_string = 5);

    int first_match(Data_T data);

    int last_match(Data_T data);

    Data_T &operator[](int position);

    /*Не работает :с
     * friend std::ostream &operator<<(std::ostream &out_stream, const DynList &list);*/
};


template<class Data_T>
typename DynList<Data_T>::Node *
DynList<Data_T>::get_Node(int position) {
    if (position < 0 or position >= len) throw "Tried to get to unreacheable position.\n";
    Node *temp = head;
    for (int i = 0; i < position; i++) {
        temp = temp->next;
    }
    return temp;
}     //зачем здесь typename?


template<class Data_T>
Data_T &
DynList<Data_T>::operator[](int position) {
    return DynList::get_Node(position)->data;
}


template<class Data_T>
void
DynList<Data_T>::empty_list() {
    /* Опустошает список. По сути это деструктор. */

    Node *temp;
    temp = tail;
    Node *prev;
    while (temp) {
        prev = temp->prev;
        delete temp;
        temp = prev;
    }
    len = 0;
    head = nullptr;
    tail = nullptr;
}


template<class Data_T>
int
DynList<Data_T>::get_len() {
    return len;
}


template<class Data_T>
void
DynList<Data_T>::push_back(Data_T data) {
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
bool
DynList<Data_T>::exist(Data_T data) {
    if (len == 0) return false;
    if (tail->data == data) return true;
    Node *temp = head;
    while (temp != tail) {
        if (temp->data == data) return true;
        temp = temp->next;

    };
    return false;
}


template<class Data_T>
void
DynList<Data_T>::print(int len_of_string) {
    /* Парамаетр len_of_string - количество элементов списка в одной строке
     * по умолчанию len_of_string = 5. */

    if (len == 0) std::cout << "List is empty!\n";
    Node *temp;
    temp = head;
    for (int i = 0; i < double(len) / len_of_string; i++) {
        std::cout << "*";
        for (int j = 0; j < len_of_string; j++) {
            if (temp == nullptr) break;
            std::cout << std::setw(5) << j + i * len_of_string
                      << ": " << temp->data;
            temp = temp->next;
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    return;
}


template<class Data_T>
void
DynList<Data_T>::insert(Data_T data, int position) {
    /* Добавляет элемент в указанную позицию, остальные элементы СДВИГАЕТ,
     * не добавляет в конец!!! Исключение из get_Node(). */

    Node *select_node = get_Node(position);
    Node *insert_node = new Node(data);
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
void
DynList<Data_T>::remove(Data_T data) {
    /* Если в списке несколько заданных элементов - удаляет первый по порядку. */

    if (exist(data)) {
        Node *temp = head;
        while (temp->data != data) {
            temp = temp->next;
        };
        Node *select_node = temp;
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
        delete select_node;
        len--;
    } else throw "Data does not exist.";
}


template<class Data_T>
Data_T
DynList<Data_T>::pop(int position) {
    /* Исключение в get_Node(). По умолчанию удаляет нулевой элемент. */

    Node *select_node = get_Node(position);
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
    delete select_node;
    len--;
    return get_Node(position)->data;
}


template<class Data_T>
int
DynList<Data_T>::first_match(Data_T data) {
    Node *temp = head;
    int i = 0;
    while (temp->data != data) {
        temp = temp->next;
        i++;
        if (temp == nullptr) throw "Data does not exist.\n";
    };
    return i;
}


template<class Data_T>
int
DynList<Data_T>::last_match(Data_T data) {
    Node *temp = tail;
    int i = len - 1;
    while (temp->data != data) {
        temp = temp->prev;
        i--;
        if (temp == nullptr) throw "Data does not exist.\n";
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
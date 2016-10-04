#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <iomanip>

#define MULTIPL 3


struct Node {                               //Создание типа данных Node(звено).
    int i;
    double x, y;
    Node *next, *prev;
};


struct DynList {                            //Создание типа данных DynList(список).
    Node *head;                             //Указатели на адреса начала и конца списка.
    Node *tail;
};


DynList *create_list() {                 //Создание пустого списка.
    DynList *list = new DynList;            //Выделение памяти под переменную типа DynList.
    //std::cout << "Memory add " << list << "\n";
    list->head = list->tail = nullptr;         //Голова и хвост ничто(их указатели указывают на NULL), но они существуют.
    return list;
}


int first_match(DynList *list, double x, double y) {
    Node *temp = list->head;
    int i = 1;
    while (temp->x != x or temp->y != y) {
        temp = temp->next;
        i++;
        if (temp == nullptr)
            throw "Node not found.";
    };
    return i;
}


int last_match(DynList *list, double x, double y, int list_len) {
    Node *temp = list->tail;
    int i = list_len;
    while ((temp->x != x) or (temp->y != y)) {
        temp = temp->prev;
        i--;
        if (temp == nullptr)
            throw "Node not found.";
    };
    return i;
}


void add_node(DynList *list, int i, double x, double y) {
    Node *temp;
    temp = new Node();
    temp->next = nullptr;
    temp->i = i + 1;
    temp->x = x;
    temp->y = y;
    //std::cout << "Memory add " << temp << "\n";
    if (list->head) {                                   // Если список не пуст
        temp->prev = list->tail;                        // Указываем адрес на предыдущий элемент в соотв. поле
        list->tail->next = temp;                        // Указываем адрес следующего за хвостом элемента
        list->tail = temp;                              //Меняем адрес хвоста
    } else {                                            //Если список пустой
        temp->prev = nullptr;                           // Предыдущий элемент указывает в пустоту
        list->head = list->tail = temp;                 // Голова=Хвост=тот элемент, что сейчас добавили
    }
}


void init_list(DynList *list, int list_len) {
    for (int i = 0; i < list_len; i++) {
        add_node(list, i, rand() % MULTIPL, rand() % MULTIPL);
    }
}


void print_list(DynList *list) {
    int i = 0;
    Node *temp = list->head;
    std::cout << "\n";
    while (temp != nullptr) {
        i++;
        std::cout << std::setw(5) << temp->i << ": (" << temp->x << "; " << temp->y << ") ";
        temp = temp->next;
        if (i == 5){
            i = 0;
            std::cout << "\n";
        }

    }
    std::cout << "\n";
}


void delete_list(DynList *list) {
    Node *temp;
    temp = list->tail;
    Node *prev;
    while (temp) {
        prev = temp->prev;
        //std::clog << "Memory free " << temp << "\n";
        delete temp;
        temp = prev;
    }

    //std::cout << "Memory free " << list << "\n";
    delete list;
}


int main() {
    DynList *MyList = create_list();
    int list_len;
    double x, y;
    std::cout << "Enter the length of the list:\n ";
    std::cin >> list_len;
    std::cout << "Enter the search point:\n";
    std::cin >> x >> y;




    init_list(MyList, list_len);
    print_list(MyList);


    try {
        std::cout << "First match " << first_match(MyList, x, y)
                  << ", last match " << last_match(MyList, x, y, list_len)<< ".\n";
    }
    catch (char *str) {
        std::cout << str;
    }


    delete_list(MyList);
    return 0;
}
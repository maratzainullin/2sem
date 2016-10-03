#include <cstdlib>
#include <iostream>
#include <stdlib.h>

#define MULTIPL 3


struct Node {                               //Создание типа данных Node(звено).
    double x, y;                            //Данные звена.
    Node *next, *prev;                      //Указатели на адреса следующего и предыдущего элементов списка(звеньев).
};


struct DynList {                            //Создание типа данных DynList(список).
    Node *head;                             //Указатели на адреса начала и конца списка.
    Node *tail;
};


DynList *create_DynList() {                 //Создание пустого списка.
    DynList *list = new DynList;            //Выделение памяти под переменную типа DynList.
    //std::cout << "Memory add " << list << "\n";
    list->head = list->tail = nullptr;         //Голова и хвост ничто(их указатели указывают на NULL), но они существуют.
    return list;
}


int first_match(DynList *list, double x, double y) {
    Node *temp = list->head;
    int i = 1;
    while ((temp->x != x) or (temp->y != y)) {
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


void add_node(DynList *list, double x, double y) {
    Node *temp;
    temp = new Node();                // Выделение памяти под новый элемент структуры(звено).
    temp->next = nullptr;                      // Указываем, что изначально по следующему адресу пусто
    temp->x = x;                            // Записываем значение в структуру
    temp->y = y;
    //std::cout << "Memory add " << temp << "\n";
    if (list->head) {               // Если список не пуст
        temp->prev = list->tail;            // Указываем адрес на предыдущий элемент в соотв. поле
        list->tail->next = temp;            // Указываем адрес следующего за хвостом элемента
        list->tail = temp;                  //Меняем адрес хвоста
    } else {                                //Если список пустой
        temp->prev = nullptr;                  // Предыдущий элемент указывает в пустоту
        list->head = list->tail = temp;     // Голова=Хвост=тот элемент, что сейчас добавили
    }
}


void init_list(DynList *list, int list_len) {
    for (int i = 0; i < list_len; i++) {
        add_node(list, rand() % MULTIPL, rand() % MULTIPL);
    }
}


void print(DynList *list) {
    Node *temp = list->head;                                         // Временно указываем на адрес первого элемента
    std::cout << "\n";
    while (temp != nullptr) {                                           // Пока не встретим пустое значение
        std::cout << "(" << temp->x << "; " << temp->y << ") ";      //Выводим значение на экран
        temp = temp->next;                                           //Смена адреса на адрес следующего элемента
    }
    std::cout << "\n";
}


void delete_DynList(DynList *list) {
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
    DynList *MyList = create_DynList();
    int list_len;
    double x, y;
    std::cout << "Enter the search point:\n";
    std::cin >> x >> y;
    std::cout << "Enter the length of the list:\n ";
    std::cin >> list_len;



    init_list(MyList, list_len);
    print(MyList);


    try {
        std::cout << "First match " << first_match(MyList, x, y)
                  << ", last match " << last_match(MyList, x, y, list_len)<< ".\n";
    }
    catch (char *str) {
        std::cout << str;
    }


    delete_DynList(MyList);
    return 0;
}
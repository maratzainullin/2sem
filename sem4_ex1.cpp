#include <cstdlib>
#include <iostream>
#include <stdlib.h>



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
    std::cout << "Memory add " << list << "\n";
    list->head = list->tail = nullptr;         //Голова и хвост ничто(их указатели указывают на NULL), но они существуют.
    return list;
}


void delete_DynList(DynList *list) {
    Node *temp;
    temp = list->tail;
    Node *prev;
    while (temp) {
        prev = temp->prev;
        std::cout << "Memory free " << temp << "\n";
        delete temp;
        temp = prev;
    }

    std::cout << "Memory free " << list->tail << "\n";
    std::cout << "Memory free " << list << "\n";
    delete list;
}


void add_node(DynList *list, double x, double y) {
    Node *temp;
    temp = new Node();                // Выделение памяти под новый элемент структуры(звено).
    temp->next = nullptr;                      // Указываем, что изначально по следующему адресу пусто
    temp->x = x;                            // Записываем значение в структуру
    temp->y = y;
    std::cout << "Memory add " << temp << "\n";
    if (list->head) {               // Если список не пуст
        temp->prev = list->tail;            // Указываем адрес на предыдущий элемент в соотв. поле
        list->tail->next = temp;            // Указываем адрес следующего за хвостом элемента
        list->tail = temp;                  //Меняем адрес хвоста
    } else {                                //Если список пустой
        temp->prev = nullptr;                  // Предыдущий элемент указывает в пустоту
        list->head = list->tail = temp;     // Голова=Хвост=тот элемент, что сейчас добавили
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


int main() {
    DynList *MyList = create_DynList();
    for (int i = 0; i < 5; i++) {
        add_node(MyList, rand() % 100, rand() % 100);
    }
    print(MyList);
    delete_DynList(MyList);
    return 0;
}
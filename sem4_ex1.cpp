#include <cstdlib>
#include <iostream>

struct Node {      //Структура являющаяся звеном списка
    double x, y;     //Значение (x, y) будет передаваться в список
    Node *next, *prev; //Указатели на адреса следующего и предыдущего элементов списка
};


struct List { //Создаем тип данных Список
    Node *head = NULL;
    Node *tail;  //Указатели на адреса начала списка и его конца
};


void add(List *list, double x, double y) {
    Node *temp = new Node(); // Выделение памяти под новый элемент структуры
    temp->next = NULL;       // Указываем, что изначально по следующему адресу пусто
    temp->x = x;             // Записываем значение в структуру
    temp->y = y;
    if (list->head != NULL) { // Если список не пуст
        temp->prev = list->tail; // Указываем адрес на предыдущий элемент в соотв. поле
        list->tail->next = temp; // Указываем адрес следующего за хвостом элемента
        list->tail = temp;       //Меняем адрес хвоста
    } else { //Если список пустой
        temp->prev = NULL; // Предыдущий элемент указывает в пустоту
        list->head = list->tail = temp;    // Голова=Хвост=тот элемент, что сейчас добавили
    }
}


void print(List *list) {
    Node *temp = list->head;  // Временно указываем на адрес первого элемента
    while (temp != NULL) {    // Пока не встретим пустое значение
        std::cout << "(" << temp->x << " " << temp->y << "), "; //Выводим значение на экран
        temp = temp->next;     //Смена адреса на адрес следующего элемента
    }
    std::cout << "\n";
}


int main() {
    List lst;
    lst.tail = NULL;
    //lst->tail = NULL;
    for (int i = 0; i < 20; i++) {
        add(&lst, rand() % 100, rand() % 100);
    }
    print(&lst);
    return 0;
}
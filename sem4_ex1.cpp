#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <iomanip>

#define MULTIPLIER 11       // 56, (3; 2)
#define OUT_LEN 5


struct Node {                               //Создание типа данных Node(звено).
    int i;
    double x, y;
    Node *next, *prev;
};


struct DynList {                            //Создание типа данных DynList(список).
    Node *head;                             //Указатели на адреса начала и конца списка.
    Node *tail;
    int len;
};


DynList *create_list() {
    int len;                                //Создание пустого списка(фактическая длина - 0).
    DynList *list = new DynList;            //Выделение памяти под переменную типа DynList.
    list->head = list->tail = nullptr;         //Голова и хвост ничто(их указатели указывают на NULL), но они существуют.
    std::cout << "Enter the length of the list:\n";
    std::cin >> len;
    list->len = len;
    return list;
}


Node *select_to(DynList *list, int position) {
    Node *temp = list->head;
    int i = 1;
    while (i < position) {
        temp = temp->next;
        i++;
    }
    return temp;
}


int first_match(DynList *list, double y, double x) {
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


int last_match(DynList *list, double y, double x) {
    Node *temp = list->tail;
    int i = list->len;
    while ((temp->x != x) or (temp->y != y)) {
        temp = temp->prev;
        i--;
        if (temp == nullptr)
            throw "Node not found.";
    };
    return i;
}


void add_back(DynList *list, int i, double x, double y) {
    Node *temp = new Node();
    /*std::cout << "Memory set " << temp << "\n";*/
    temp->next = nullptr;
    temp->i = i + 1;
    temp->x = x;
    temp->y = y;
    if (list->head) {                                   // Если список не пуст
        temp->prev = list->tail;                        // Указываем адрес на предыдущий элемент в соотв. поле
        list->tail->next = temp;                        // Указываем адрес следующего за хвостом элемента
        list->tail = temp;                              //Меняем адрес хвоста
    } else {                                            //Если список пустой
        temp->prev = nullptr;                           // Предыдущий элемент указывает в пустоту
        list->head = list->tail = temp;                 // Голова=Хвост=тот элемент, что сейчас добавили
    }
}


void init_rand_list(DynList *list) {
    for (int i = 0; i < list->len; i++) {
        add_back(list, i, rand() % MULTIPLIER, rand() % MULTIPLIER);
    }
}


void add_to(DynList *list, double y, double x, int position) {
    //Добавляет элемент в указанную позицию, остальные элементы сдвигает(список удлиняется на один элемент)
    Node *insert_node = new Node;
    Node *select_node = select_to(list, position);
    insert_node->x = x;
    insert_node->y = y;
    insert_node->prev = select_node->prev;
    insert_node->next = select_node;
    if (select_node->prev) {
        select_node->prev->next = insert_node;
    }
    select_node->prev = insert_node;
    if (!insert_node->prev) {
        list->head = insert_node;
    }
    list->len++;
}


void remove_from(DynList *list, int position) {
    Node *select_node = select_to(list, position);                  //Если удаляем не крайний элемент.
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
    delete select_node;
    list->len--;
}


void print_list(DynList *list) {
    int k = OUT_LEN;
    Node *temp = list->head;
    for (int i = 1; i <= list->len; i++) {
        if (k == OUT_LEN) {
            std::cout << "\n*";
            k = 0;
        }
        k++;
        std::cout << std::setw(3) << i << ": ("
                  << std::setw(2) << temp->x << "; " << std::setw(2) << temp->y << ") ";
        temp = temp->next;
    }
    std::cout << "\n";
}


void delete_list(DynList *list) {
    Node *temp;
    temp = list->tail;
    Node *prev;
    while (temp) {
        prev = temp->prev;
        std::cout << "Memory free " << temp << "\n";
        delete temp;
        temp = prev;
    }

    //std::cout << "Memory free " << list << "\n";
    delete list;
}


int enter_pos() {
    int pos;
    std::cout << "Enter position:\n";
    std::cin >> pos;
    return pos;
}


double enter_data(bool f) {
    double x;
    if (f) {
        std::cout << "Enter data:\n";
    }
    std::cin >> x;
    return x;
}


int main() {
    DynList *MyList = nullptr;
    std::cout << "Select an option:\n"
            "1: Create a random list.\n"
            "2: Print a list.\n"
            "3: Add an element to this position and print list.\n"
            "4: Remove an element from this position and print list.\n"
            "5: Find an element(first and last match).\n"
            "0: Exit.\n";
    while (1) {
        int i;
        std::cin >> i;
        if (!i) {
            break;
        }
        switch (i) {
            case 1: {
                std::cout << "*******Create a random list.*******\n";
                MyList = create_list();
                init_rand_list(MyList);
                break;
            }
            case 2: {
                std::cout << "*******Print a list.*******\n";
                print_list(MyList);
                break;
            };
            case 3: {
                std::cout << "*******Adding an element.*******\n";
                add_to(MyList, enter_data(0), enter_data(1), enter_pos());
                print_list(MyList);
                break;
            }
            case 4: {
                std::cout << "*******Removing an element.*******\n";
                remove_from(MyList, enter_pos());
                print_list(MyList);
                break;
            }
            case 5: {
                double x = enter_data(1);
                double y = enter_data(0);
                std::cout << "*******Finding an element(first and last match).*******\n";
                std::cout << "First match: " << first_match(MyList, y, x)
                          << ", last match: " << last_match(MyList, y, x)
                          << ".\n";
                break;
            }
            default: {
                std::cout << "???Invalid option???";
            }
        }
    }
    /*try {
        std::cout << "First match " << first_match(MyList, enter_data(0),  enter_data(1))
                  << ", last match " << last_match(MyList, x, y) << ".\n";
    }
    catch (char const *str) {
        std::cout << str;
    }*/
    delete_list(MyList);
    return 0;
}
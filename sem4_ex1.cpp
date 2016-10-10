#include <cstdlib>
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <math.h>

#define MULTIPLIER 10
#define OUT_LEN 5


struct Node {
    int i;
    double x, y, r;
    Node *next, *prev;
};


struct DynList {
    Node *centre;
    Node *head;
    Node *tail;
    int len;
};


DynList *create_list() {
    //Создание пустого списка.
    DynList *list = new DynList;
    list->len = 0;
    list->head = list->tail = nullptr;
    list->centre = new Node();
    list->centre->x = list->centre->y = 0;
    return list;
}


Node *get_to(DynList *list, int position) {
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
            throw "Node not found. Try againSSS. ";
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
            throw "Element not found. Select option.\n";
    };
    return i;
}


void add_back(DynList *list, double x, double y, int i, double r = 0) {
    Node *temp = new Node();
    temp->next = nullptr;
    temp->x = x;
    temp->y = y;
    temp->r = r;
    temp->i = i;
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
    std::cout << "Enter the length of the list:\n";
    std::cin >> list->len;
    for (int i = 0; i < list->len; i++) {
        add_back(list, rand() % MULTIPLIER, rand() % MULTIPLIER, i);
    }
}


void add_to(DynList *list, double y, double x, int position) {
    //Добавляет элемент в указанную позицию, остальные элементы сдвигает(список удлиняется на один элемент)
    Node *insert_node = new Node;
    Node *select_node = get_to(list, position);
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


Node *remove_from(DynList *list, int position) {
    Node *select_node = get_to(list, position);                  //Если удаляем не крайний элемент.
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
    //delete select_node;
    list->len--;
    return select_node;
}


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
}


void print_list(DynList *list) {
    if (list == nullptr or list->len == 0) {
        throw "\nList is not created! Select option.\n";
    }
    int k = OUT_LEN;
    Node *temp = list->head;
    for (int i = 1; i <= list->len; i++) {
        if (k == OUT_LEN) {
            std::cout << "\n*";
            k = 0;
        }
        std::cout << std::setw(7) << std::fixed << std::setprecision(0) << i << ": ("
                  << std::setw(2) << temp->x << "; "
                  << std::setw(2) << temp->y << ") "
                  //<< std::setw(2) << temp->i << ")"
                  << std::setw(5) << std::fixed << std::setprecision(2) << temp->r;
        temp = temp->next;
        k++;
    }
    std::cout << "\n";
}


void delete_list(DynList *list) {
    Node *temp;
    temp = list->tail;
    Node *prev;
    while (temp) {
        prev = temp->prev;
        delete temp;
        temp = prev;
    }
    delete list;
}


int enter_pos(DynList *list) {
    if (list == nullptr) {
        throw "List is not created! Create it.\n";
    }
    int pos = 0;
    std::cout << "Enter position:\n";
    std::cin >> pos;
    if (pos > list->len or pos <= 0) {
        throw "Position not found. Select option.\n";
    }
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


Node *pattern1(Node *select_node) {
    if (select_node->x > 5 and select_node->y > 5) {
        return select_node;
    }
    return nullptr;
}


Node *get_centre(DynList *list) {

    Node *temp = list->head;
    while (temp) {
        list->centre->x += temp->x;
        list->centre->y += temp->y;
        temp = temp->next;
    }
    list->centre->x /= list->len;
    list->centre->y /= list->len;
    return list->centre;
}


Node *distance_to_centre(DynList *list, Node *select_node) {
    select_node->r = sqrt(pow(select_node->x - list->centre->x, 2)
                          + pow(select_node->y - list->centre->y, 2));
    return select_node;
}


Node *min_node(DynList *list, Node *select_node) {
    Node *temp, *min_node;
    min_node = list->head;
    temp = min_node->next;
    while (temp) {
        if (min_node->r > temp->r) {
            min_node = temp;
        }
        temp = temp->next;
    }
    min_node = remove_from(list, min_node);
    return min_node;
}


DynList *use_pattern_and_create(DynList *list, Node *(*pattern_ptr)(DynList *, Node *), int p) {
    DynList *ListWithPattern = create_list();
    Node *temp = list->head;
    Node *patterned_node;
    for (int i = 0; i < p; i++) {
        patterned_node = pattern_ptr(list, temp);
        if (patterned_node) {
            add_back(ListWithPattern, patterned_node->x, patterned_node->y, patterned_node->i,
                     patterned_node->r);
            ListWithPattern->len++;
        }
        temp = temp->next;
    }
    return ListWithPattern;
}


int main() {
    DynList *MyList = nullptr;
    std::cout << "*******Create a random list.*******\n";
    MyList = create_list();
    init_rand_list(MyList);
    //print_list(MyList);
    get_centre(MyList);
    std::cout << MyList->centre->x << " "
              << MyList->centre->y << "\n";


    DynList *MyListWithDist = nullptr;
    MyListWithDist = use_pattern_and_create(MyList, distance_to_centre, MyList->len);
    print_list(MyListWithDist);


    DynList *MyListWithDistSort = nullptr;
    MyListWithDistSort = use_pattern_and_create(MyListWithDist, min_node, 15);
    print_list(MyListWithDistSort);


    print_list(MyListWithDist);

    /*try {
        print_list(MyListWithDist);
    }
    catch (char const *str){
        std::cout << str;
    }*/


    /*std::cout << "Select an option:\n"
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
        try {
            switch (i) {
                case 1: {
                    std::cout << "*******Create a random list.*******\n";
                    MyList = create_list();
                    init_rand_list(MyList);
                    break;
                }
                case 2: {
                    std::cout << "*******Print a list.*******";
                    print_list(MyList);
                    break;
                };
                case 3: {
                    std::cout << "*******Adding an element.*******\n";
                    int pos = enter_pos(MyList);
                    add_to(MyList, enter_data(0), enter_data(1), pos);        //enter_data(0) = y
                    print_list(MyList);
                    break;
                }
                case 4: {
                    std::cout << "*******Removing an element.*******\n";
                    int pos = enter_pos(MyList);
                    remove_from(MyList, pos);
                    print_list(MyList);
                    break;
                }
                case 5: {
                    std::cout << "*******Finding an element(first and last match).*******\n";
                    if (MyList == nullptr) {
                        throw "List is not created! Create it.\n";
                    }
                    double x = enter_data(1);
                    double y = enter_data(0);
                    std::cout << "First match: " << first_match(MyList, y, x)
                              << ", last match: " << last_match(MyList, y, x)
                              << ".\n";

                    break;
                }
                default: {
                    std::cout << "*******Invalid option! Try again.*******\n";
                    continue;
                }
            }
        }
        catch (char const *str) {
            std::cout << str;
            continue;
        }
        std::cout << "Done! Select an option.\n";
    }
    if (MyList) {
        delete_list(MyList);
    }*/
    return 0;
}
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <math.h>
#include "dynlist.h"

/*DynList::Data_t enter_data() {
    DynList::Data_t data(0, 0);
    double x;
    std::cout << "Enter data:\n";
    std::cin >> data.x >> data.y >> "\n";
    return data;
}*/

int enter_pos(DynList list) {
    /*if (&list == nullptr) {                            //arning: the address of 'list' will never be NULL
        throw "List is not created! Create it.\n";
    }*/
    int pos = 0;
    std::cout << "Enter position:\n";
    std::cin >> pos;
    /*if (pos > list->len or pos <= 0) {
        throw "Position not found. Select option.\n";
    }*/
    return pos;
}

/*Node *patternsravneniya(Node *select_node) {
    if (select_node->x > 5 and select_node->y > 5) {
        return select_node;
    }
    return nullptr;
}*/

/*
Node *get_centre(DynList *list) {
    if (list == nullptr) {
        throw "List is not created! Create it.\n";
    }
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
    if (list == nullptr) {
        throw "List is not created! Create it.\n";
    }
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

*/

int main() {


    std::cout << "*******Create a random list.*******\n";
    DynList MyList = DynList();
    MyList.init_rand_list();


    std::cout << "*******Print a list.*******";
    std::cout << MyList;

    std::cout << "*******Adding an element.*******\n";
    //int pos = enter_pos(MyList);
    DynList::Data_t data(0, 0); //написать ентер дата для типа данных ДАТА

    std::cin >> data;

    MyList.insert(data, 5);

    std::cout << "*******Print a list.*******";
    std::cout << MyList;


/*
    std::cout << "Select an option:\n"
            "1: Create a random list.\n"
            "2: Print a list.\n"
            "3: Add an element to this position and print list.\n"
            "4: Remove an element from this position and print list.\n"
            "5: Find an element(first and last match).\n"
            "6: Print N closest nodes to the center of mass(center of mass - first node)."
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
                    (*MyList) = DynList();
                    MyList->init_rand_list();
                    break;
                }
                case 2: {
                    std::cout << "*******Print a list.*******";
                    std::cout << MyList;
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
                case 6: {
                    std::cout << "*******Print N closest nodes to the center of mass(center - first node).*******\n";
                    get_centre(MyList);
                    std::cout << "Enter N:\n";
                    int n = 0;
                    std::cin >> n;
                    DynList *MyListWithDist = nullptr;
                    DynList *MyListWithDistSort = nullptr;

                    MyListWithDist = use_pattern_and_create(MyList, distance_to_centre, MyList->len);
                    MyListWithDistSort = use_pattern_and_create(MyListWithDist, min_node, n);
                    std::cout << "Center of mass:      (" << get_centre(MyList)->x
                              << "; " << get_centre(MyList)->y << ")\n";
                    print_list(MyListWithDistSort);
                    A[1] = MyListWithDist;
                    A[2] = MyListWithDistSort;
                    break;
                }
                case 7: {
                    for (int k = 0; k < 10; k++) {
                        if (A[k]) {
                            delete_list(A[k]);
                        }
                    }
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
    }*/
    return 0;
}
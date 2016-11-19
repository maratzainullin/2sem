#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include "dynlist.h"

int main() {
    try {
        DynList<Point_2D> MyList_2D;
        std::cout << "*******Create a random Number Book.*******\n";
        for (int i = 0; i < 10; i++) {
            MyList_2D.push_back(Point_2D::frand(100));
        }
        MyList_2D.print();
        std::cout << "Head: " << MyList_2D.get_head().data << ", tail: " << MyList_2D.get_tail().data << "\n";
        std::cout << "Len: " << MyList_2D.get_len() << "\n";
        MyList_2D.insert(MyList_2D[6], 9);
        MyList_2D.print();

        Point_2D A = MyList_2D[6];
        MyList_2D.remove(A);
        MyList_2D.remove(A);
        MyList_2D.remove(A);
        MyList_2D.print(5);


    }


    catch (char const *c) {
        std::cout << c;
    }


    return 0;
}
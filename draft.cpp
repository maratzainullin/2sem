#include <iostream>
#include <list>     // подключаем заголовок списка
#include <iterator> // заголовок итераторов

using namespace std;



struct point {
    int x, y;
};

int main() {
    point a;
    list <point> myList; // объявляем пустой список
    for (int i = 0; i < 11; i++) {
        a.x = rand() % 10;
        a.y = rand() % 10;
        myList.push_back(a); // добавляем в список новые элементы
    }

    int f(int i){
        i++;
        return 2*i;
    }

    {
        cout << "Список: ";
        copy(myList.begin(), myList.end(), ostream_iterator<point>(cout, " ")); // вывод на экран элементов списка
        /* << "\nПервый элемент списка: " << myList.front();
        cout << "\nПоследний элемент списка: " << myList.back();*/
    }
    return 0;
}








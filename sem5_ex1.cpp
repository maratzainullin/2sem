#include <iostream>
#include <string>

#define SIZE 17

using namespace std;


class Person {
/* Класс, который содержит немного информации о человеке.
 * Содержит исключительно информацию о человеке.
 * Используется как тип данных для элементов списка.
 *
 * Для случая коллизий. Не надо класс, содержайщий информацию
 * о человеке мешать со списками, тем более пересоздавать здесь
 * обрезанную версию списка.
 *
 * Хэш-таблица есть массив, элементы данного массива - двусвязные списки.
 * Класс Person содержит только данные для элементов уже списка, как дата
 * в библиотеке списка.
 *
 * Нужно как-то реализовать возможность кидать в список тип данных
 * Person.
 */
private:
    //Person *next;//
    string name;
    int telephone_number;

public:
    Person(string _name, int _telephone_number) : name(_name), telephone_number(_telephone_number) {}


    ~Person() {
        //cout << "Delete " << this->name << endl;
        if (this->next != NULL) {
            delete this->next;
        }
    }

};


class HashTable {
/* Хэш-таблица есть массив.
 * Элементы массива - двусвязные списки.
 * Элементы списка типа Person.
 *
 * Необходимо отделить интерфейс от реализации.
 * Класс Person можно сделать вложенным в класс хэш-таблицы.
 *
 * Не должна быть фиксированного размера, должна изменяться
 * в зависимости от степени загруженности(загруженна должна
 * быть не более, чем на 30%.
 */
private:
    Person *table[SIZE];


    int hash(int number) {
        return number % SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            table[i] = nullptr;
        }
    }


    ~HashTable() {
        //cout << "Delete table\n";
        for (int i = 0; i < SIZE; i++) {
            delete table[i];
        }
    }


    void push(string name, int telephone_number) {
        int hashNumber = hash(telephone_number);
        Person *pers = new Person(name, telephone_number);
        Person *place = table[hashNumber];
        if (place == NULL) {
            table[hashNumber] = pers;
            return;
        }

        while (place->next != NULL) {
            place = place->next;
        }
        place->next = pers;
    }


    Person *find(int telephone_number) {
        int hashNumber = hash(telephone_number);
        Person *result = table[hashNumber];
        if (!result) {
            cout << "Element not found" << endl;
            return NULL;
        }
        while (result->telephone_number != telephone_number) {
            if (!result->next) {
                cout << "Element not found" << endl;
                break;
            }
            result = result->next;
        }
        return result;
    }
};


int main() {
    HashTable newTable;
    newTable.push("Petr", 800355);
    newTable.push("Vasili", 800596);
    newTable.push("Vlad", 800948);
    newTable.push("Anna", 800948);
    newTable.push("Maria", 800457);

    Person *search = newTable.find(800948);
    if (search) {
        cout << search->name << endl;
    }
    return 0;
}
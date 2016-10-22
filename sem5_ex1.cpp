//хэш таблицы, добавление, поиск, удаление;
// Реализация хеш-таблицы через остаток от деления
// Добавление и поиск элементов осуществлятся через имя (name).

#include <iostream>
#include <string>

#define SIZE 17

using namespace std;

class Person { // Класс, который содержит немного информации о человеке.
public:
    Person *next; // При возникновении коллизии элементы будут помещены в односвязный список.
    string name;
    int telephone_number;

    Person(string name, int telephone_number = 0) {
        this->name = name;
        this->telephone_number = telephone_number;
        this->next = NULL;
    }

    ~Person() {
        //cout << "Delete " << this->name << endl;
        if (this->next != NULL) {
            delete this->next;
        }
    }
};

class HashTable { // Хеш-таблица, представленная в виде массива элементов (которые в свою очередь представляют список).
    Person *table[SIZE];

    int hash(int number) {
        return number % SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            table[i] = NULL;
        }
    }

    ~HashTable() {
        //cout << "Delete table\n";
        for (int i = 0; i < SIZE; i++) {
            delete table[i];
        }
    }

    // Вставляет элемент в таблицу
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

    // Получает элемент из таблицы по его имени.
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

int main()
{
    HashTable newTable;
    newTable.push("Petr", 800355);
    newTable.push("Vasili", 800596);
    newTable.push("Vlad", 800948);
    newTable.push("Anna", 800948);
    newTable.push("Maria", 800457);

    Person * search = newTable.find(800948);
    if ( search ) {
        cout << search->name << endl;
    }
    return 0;
}
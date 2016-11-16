#ifndef INC_2SEM_HASH_TABLE_H
#define INC_2SEM_HASH_TABLE_H

#include <iostream>
#include <string>
#include "hash.h"
#include "dynlist.h"

#define CAPP 1700
#define LOAD_FACTOR
#define MAX_HASH 100;


template<class Key_T, class Value_T>
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
public:
    struct Pair {
        Key_T key;
        Value_T value;

        Pair(Key_T _key, Value_T _value) : key(_key), value(_value) {};

        bool operator==(Pair temp) {
            return (key == temp.key and value == temp.value);
        }

        bool operator!=(Pair temp) {
            return (key != temp.key and value != temp.value);
        }
    };


private:
    DynList<Pair> *Table = new DynList<Pair>[CAPP];
    int len;


public:
    HashTable() : len(0) {};

    void put(Key_T key, Value_T value);

    Pair get(Key_T key);

    void remove(Key_T key);

    ~HashTable() {
        for (int i = 0; i < len; i++) {
            Table[i].empty_list(); //Возможно, это не нужно, если вместе со списком при удалении его из памяти
            //удаляются так же и ноды(не известно, так ли это).

        }
        delete[] Table;  //Узнать, как точно работает оператор delete(нужны ли здесь []).
        //При delete срабатывает деструктор класса? Или просто как-то высвобождается память?
        //Как именно память высвобождается? Если у меня данные это массив классов(списков),
        //то при delete удалятся все свписки массива из памяти? Сам массив удалится, но
        //что это значит?
        //Понятно(или нет), что отдельные точки списка не удалятся(или нет)(или, если вызовется
        //деструктор, то все вообще удалится?)

    };
};


template<class Key_T, class Value_T>
void
HashTable<Key_T, Value_T>::put(Key_T key, Value_T value) {
    int h = hash::get_hash(key);
    Pair temp(key, value);
    if (!Table[h].exist(temp)) {
        Table[h].push_back(temp);
    } else throw "Pair already exists.\n";
}


template<class Key_T, class Value_T>
typename HashTable<Key_T, Value_T>::Pair
HashTable<Key_T, Value_T>::get(Key_T key) {
    int h = hash::get_hash(key);
    for (int i = 0; i < Table[h].get_len(); i++) {
        if (Table[h][i].key == key) {
            return Table[h][i];
        }
    }
    throw "Pair does not exist.\n";
};


template<class Key_T, class Value_T>
void
HashTable<Key_T, Value_T>::remove(Key_T key) {
    int h = hash::get_hash(key);
    Table[h].remove(get(key));
};


#endif //INC_2SEM_HASH_TABLE_H

#ifndef INC_2SEM_HASH_TABLE_H
#define INC_2SEM_HASH_TABLE_H

#include <iostream>
#include <string>
#include "dynlist.h"

#define CAPP 170
#define LOAD_FACTOR


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
        int len_of_line = 5;

        Pair(Key_T _key, Value_T _value) : key(_key), value(_value) {};
    };

private:
    DynList<Pair> *Table = new DynList<Pair>[CAPP];
    int len;

    int get_hash(Key_T key) {
        return key;
    };


public:
    HashTable() : len(0) {};

    void put(Key_T key, Value_T value);

    DynList<Pair> get(Key_T key) {
        int h = get_hash(key);
        return Table[h];

    };

    //void remove(Key_T, Value_T);

    //~HashTable();
};


template<class Key_T, class Value_T>
void HashTable<Key_T, Value_T>::put(Key_T key, Value_T value) {
    int h = get_hash(key);
    Pair *pair_p = new Pair(key, value);  //проверить без выделения памяти.
    Table[h].push_back(*pair_p);
}


/*template<class Key_T, class Value_T>
DynList<HashTable<Key_T, Value_T>::Pair> HashTable<Key_T, Value_T>::get(Key_T key) {
    int h = get_hash(key);
    return Table[h];

}*/


#endif //INC_2SEM_HASH_TABLE_H

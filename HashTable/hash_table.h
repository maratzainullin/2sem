#ifndef INC_2SEM_HASH_TABLE_H
#define INC_2SEM_HASH_TABLE_H

#include <iostream>
#include <string>
#include "hash.h"
#include "../DinList/dynlist.h"

#define CAPACITY 700


template<class Key_T, class Value_T>
class HashTable {
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
    DynList<Pair> *Table = new DynList<Pair>[CAPACITY];
    int len;


public:
    HashTable() : len(0) {};

    void put(Key_T key, Value_T value);

    Pair get(Key_T key);

    void remove(Key_T key);

    ~HashTable() {
        /*for (int i = 0; i < len; i++) {
            Table[i].empty_list();

        }*/
        delete[] Table;  //При delete вызывается деструктор?


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

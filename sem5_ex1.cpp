/*#include <iostream>
#include <string>
#include "data.h"
#include "dynlist.h"

#define CAPP 17
#define LOAD_FACTOR

using namespace std;

template<class Key_T, class Value_T>
class HashTable {

public:
    struct Pair;

private:
    DynList<Value_T> *Table = new DynList<Value_T>[CAPP];
    int len;
    int hash(int number) {
        return number % CAPP;
    }

public:
    HashTable() {
        for (int i = 0; i < CAPP; i++) {
            Table[i] = nullptr;
        }
    }
    void put(Key_T key, Value_T value);
    Value_T get(Key_T key);
    void remove(Key_T key, Value_T value);
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

    return 0;
}*/
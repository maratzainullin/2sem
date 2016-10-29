#include "hash_table.h"
#include <string>

int main(){
    HashTable<int, std::string> h1;
    h1.put(11, "hui");
    h1.put(10, "zalupa");
    h1.put(111, "manda");
    h1.get(11).print();



}
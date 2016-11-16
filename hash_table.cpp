#include "hash_table.h"
#include <string>

int main() {
    try {
        HashTable<int, Person> P;
        DynList<Person> Number_Book;
        for (int i; i < 10; i++) {
            Number_Book.push_back(Person::frand(10));
        }
        Number_Book.print(3);


        P.put(135, Number_Book[0]);
        P.put(1135, Number_Book[1]);
        P.put(145, Number_Book[2]);
        P.put(35, Number_Book[3]);
        P.put(123, Number_Book[4]);
        P.put(45, Number_Book[5]);
        P.put(13435, Number_Book[6]);
        P.put(1233, Number_Book[7]);
        P.put(133, Number_Book[8]);
        P.put(153, Number_Book[9]);


        std::cout << "*" << std::setw(6) << "Key:" << std::setw(11) << " " << " Value:\n"
                  << "*" << std::setw(5) << P.get(135).key << ":" << std::setw(11) << " " << P.get(135).value << "\n"
                  << "*" << std::setw(5) << P.get(1135).key << ":" << std::setw(11) << " " << P.get(1135).value << "\n"
                  << "*" << std::setw(5) << P.get(145).key << ":" << std::setw(11) << " " << P.get(145).value << "\n"
                  << "*" << std::setw(5) << P.get(35).key << ":" << std::setw(11) << " " << P.get(35).value << "\n"
                  << "*" << std::setw(5) << P.get(123).key << ":" << std::setw(11) << " " << P.get(123).value << "\n"
                  << "*" << std::setw(5) << P.get(45).key << ":" << std::setw(11) << " " << P.get(45).value << "\n"
                  << "*" << std::setw(5) << P.get(13435).key << ":" << std::setw(11) << " " << P.get(13435).value << "\n"
                  << "*" << std::setw(5) << P.get(1233).key << ":" << std::setw(11) << " " << P.get(1233).value << "\n"
                  << "*" << std::setw(5) << P.get(133).key << ":" << std::setw(11) << " " << P.get(133).value << "\n"
                  << "*" << std::setw(5) << P.get(153).key << ":" << std::setw(11) << " " << P.get(153).value << "\n\n";


        P.remove(135);


        std::cout << "*" << std::setw(6) << "Key:" << std::setw(11) << " " << " Value:\n"
                  << "*" << std::setw(5) << P.get(1135).key << ":" << std::setw(11) << " " << P.get(1135).value << "\n"
                  << "*" << std::setw(5) << P.get(145).key << ":" << std::setw(11) << " " << P.get(145).value << "\n"
                  << "*" << std::setw(5) << P.get(35).key << ":" << std::setw(11) << " " << P.get(35).value << "\n"
                  << "*" << std::setw(5) << P.get(123).key << ":" << std::setw(11) << " " << P.get(123).value << "\n"
                  << "*" << std::setw(5) << P.get(45).key << ":" << std::setw(11) << " " << P.get(45).value << "\n"
                  << "*" << std::setw(5) << P.get(13435).key << ":" << std::setw(11) << " " << P.get(13435).value << "\n"
                  << "*" << std::setw(5) << P.get(1233).key << ":" << std::setw(11) << " " << P.get(1233).value << "\n"
                  << "*" << std::setw(5) << P.get(133).key << ":" << std::setw(11) << " " << P.get(133).value << "\n"
                  << "*" << std::setw(5) << P.get(153).key << ":" << std::setw(11) << " " << P.get(153).value << "\n\n";


    }


    catch (char const *s) {
        std::cout << s;
    }


}
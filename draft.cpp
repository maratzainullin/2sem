//
// Created by Marat on 17.09.2016.
//
#include <iostream>

int main() {
    int x = 0x61fe2c;
    int y = *x;
    int z = 100;
    int *ptrz = &z;


    std::cout << z << " " << ptrz << " " << *ptrz << " " << x <<std::endl;
    return 0;
}








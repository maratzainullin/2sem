#include <iostream>
void good_incrementor(int *a){
    (*a)++;
}
int main(){
    int x = 0;
    std::cout << "x old: " << x << std::endl;
    good_incrementor(&x);
    std::cout << "x changed: " << x << std::endl;
    return 0;
}


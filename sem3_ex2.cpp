#include <iostream>
void good_incrementor(int *x){
    (*x)++;
}
int main(){
    int x = 5;
    std::cout << "x old: " << x << std::endl;
    good_incrementor(&x);
    std::cout << "x changed: " << x << std::endl;
    return 0;
}


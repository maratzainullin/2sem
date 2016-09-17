#include <iostream>
void better_incrementor(int &x) {
    x++;
}
int main(){
    int x = 5;
    std::cout << "x old: " << x << std::endl;
    better_incrementor(x);
    std::cout << "x changed: " << x << std::endl;
    return 0;
}


#include <iostream>
void bad_incrementor(int x){
    x++;
    std::cout << "x changed: " << x << std::endl;
}
int main(){
    int x;
    std::cin >> x;
    bad_incrementor(x);
    std::cout << "x old: " << x << std::endl;
    return 0;
}


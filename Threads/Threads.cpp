#include <iostream>
#include <thread>

int x;



void threadFunction1() {
    for (int i = 0; i < 1000003; ++i) {
        x++;
    }
}



void threadFunction2() {
    for (int i = 0; i < 1000000; ++i) {
        [](int x1) -> void {
            if ((x1 % 2) == 0) {
                std::cout << "x = " << x1 << std::endl;
            }
        }(x);
    }

}



int main() {
    std::thread t1(threadFunction1);
    std::thread t2(threadFunction2);
    t1.join();
    t2.join();
    return 0;
}


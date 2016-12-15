#include <iostream>
#include <vector>

template<typename T, unsigned int s = 1>
class CircularBuffer {
public:
    CircularBuffer() {
        head = tail = 0;
        arr.reserve(s);
    }

    // Добавить элемент
    void put(const T &value) {
        if (tail == arr.capacity()) {
            tail = 0;
        }

        ++tail;
        arr.push_back(value);
    }


    // Извлечь последний элемент
    T &pop() {
        if (head == arr.capacity()) {
            head = 0;
        }
        T &elem = arr[head];
        ++head;
        arr.pop_back();
        return elem;

    }

    // Кол-во элементов в буфере
    size_t size() const {
        return arr.size();
    }

    // Ёмкость буфера
    size_t capacity() const {
        return arr.capacity();
    }

    T operator[](const int i) {
        return arr[i];
    }

    void printBuffer() {
        std::cout << head << " " << tail << " ";
        for (int i = 0; i < arr.capacity(); i++) {
            std::cout << arr[i] << " ";
        }
    }


private:
    std::vector<T> arr;             // массив-буфер
    int head;              // индекс первого элемента
    int tail;              // индекс последнего элемента
};


int main() {
    CircularBuffer<int, 3> buf;

    for (int i = 0; i < 10; ++i) {
        buf.put(i * 2);
        if (buf.size() == buf.capacity()) {
            std::cout << "---------------" << std::endl;
            while (buf.size()) {
                std::cout << buf.pop() << std::endl;
            }
        }
    }

    std::cout << "---------------" << std::endl;
    while (buf.size()) {
        std::cout << buf.pop() << std::endl;
    }
    return 0;
}

#include <iostream>
#define N  5
#define M  6

void init_array(int **A){
    for(int i = 0; i < N; i++)
        for(int k = 0; k < M; k++)
            std::cin >> A[i][k];
}

void free_mem(int **A){
    for(int i = 0; i < N; i++)
        delete[]A[i];
    delete[] A;
}

int main(){
    //std::cin >> N >> M;
    int **A;
    A = new int *[N];
    for (int i = 0; i < N; i++)
        A[i] = new int[M];

    init_array(A);

    return 0;
}



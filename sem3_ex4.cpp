#include <iostream>
#define HEIGHT 2 //N
#define WIDTH 3  //M


int **matrix_set_mem(int N, int M){
    int **A;
    A = new int *[N];
    for (int i = 0; i < N; i++)
        A[i] = new int[M];
    return A;
}


void init_matrix(int N, int M, int **A){
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            std::cin >> A[i][j];        //A[i] = *(A + i)
                                        // A[i][2] = *((A[i]) + j)
}


void matrix_free_mem(int N, int **A){
    for(int i = 0; i < N; i++)
        delete []A[i];
    delete []A;
}


void matrix_print(int N, int M, int **A) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            std::cout << A[i][j] << " ";
        std::cout << std::endl;
    }
}


void matrix_test(int N, int M){
    int **A = matrix_set_mem(N, M);
    init_matrix(N, M, A);
    matrix_print(N, M, A);
    matrix_free_mem(N, A);
}


int main() {
    //std::cin >> N >> M;
    matrix_test(HEIGHT, WIDTH);
    return 0;
}



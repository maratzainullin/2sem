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

void matrix_free_mem(int N, int **A){
    for (int i = 0; i < N; i++)
        delete []A[i];
    delete []A;
}

void matrix_enter(int N, int M, int **A){
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            std::cin >> A[i][j];        //A[i] = *(A + i)
                                        // A[i][2] = *((A[i]) + j)
}

void matrix_print(int N, int M, int **A) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            std::cout << A[i][j] << " ";
        std::cout << std::endl;
    }
}

int **trans_matrix_init(int N, int M, int **A){
    int **A_T = matrix_set_mem(M, N);
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            A_T[i][j] = A[j][i];
    return A_T;
}       //выделяет память, после использования нужно очищать









void matrix_test(int N, int M){
    int **A = matrix_set_mem(N, M);
    matrix_enter(N, M, A);
    matrix_print(N, M, A);
    int **A_T = trans_matrix_init(N, M, A);
    matrix_print(M, N, A_T);
    matrix_free_mem(M, A_T);
    matrix_free_mem(N, A);
}

int main() {
    //std::cin >> N >> M;
    matrix_test(HEIGHT, WIDTH);
    return 0;
}



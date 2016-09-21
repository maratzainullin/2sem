#include <iostream>
#include <iomanip>
#include <math.h>
#define HEIGHT 3 //N
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
        std::cout << "||";
        for (int j = 0; j < M; j++)
            std::cout << std::setw(4) << std::left << A[i][j];
        std::cout << "||" << std::endl;
    }
    std::cout << std::endl;
}

int **trans_matrix_init(int N, int M, int **A){
    int **A_T = matrix_set_mem(M, N);
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            A_T[i][j] = A[j][i];
    return A_T;
}       //выделяет память, после использования нужно очищать

int matrix_det(int N, int M, int **A){
    int D = 0;
    if (N != M) {
        std::cout << "Error: M != N." << std::endl;         //return printf('%s', 'error");
        return NULL;
    }
    if (M == 1)
        return A[0][0];
    if (M != 2)
        for (int k = 0; k < M; k++) {                           //если порядок матрицы не равен 2, то считаем так
            int **B = matrix_set_mem(N - 1, M - 1);             //создаем подматрицу без первой строки и k-го столбца
            for (int i = 0; i < N - 1; i++) {                   //потом нужно очистить память под B
                for (int j = 0; j < k; j++)
                    B[i][j] = A[i + 1][j];
                for (int j = k; j < M - 1; j++)
                    B[i][j] = A[i + 1][j + 1];
            }
            D += pow(-1, k) * A[0][k] * matrix_det(N - 1, M - 1, B);
            matrix_free_mem(N - 1, B);
        }
    else {                                                      //если порядок матрицы стал равен 2, то считаем так
        D = A[0][0] * A[1][1] - A[0][1] * A[1][0];
        matrix_free_mem(N, A);                                  //удаляет миноры второго порядка
        return D;
    }
}

void matrix_test(int N, int M){
    int **A = matrix_set_mem(N, M);
    matrix_enter(N, M, A);
    matrix_print(N, M, A);
    int **A_T = trans_matrix_init(N, M, A);
    matrix_print(M, N, A_T);
    std::cout << "det(A) = " << matrix_det(N, M, A);
    matrix_free_mem(M, A_T);
    matrix_free_mem(N, A);
}

int main() {
    matrix_test(HEIGHT, WIDTH);
    return 0;
}
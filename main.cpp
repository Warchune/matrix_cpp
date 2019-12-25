#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <iostream>
#include <fstream>

using namespace std;

int menu(void);
int newcalc(void);
int lastcalc(void);
void clear(void);

int main(int argc, char **argv){
    int result;
    if (result = menu() == 0) {
        return 0;
    }
}

/*   Главное меню.  */
int menu(void){
    char c;
    int result;
    while(true){
        system("clear");
        printf("Умножение матриц.\n"
               "Нажмите цифру одного из действий.\n"
               "1. Новое вычисление;\n"
               "2. Прошлое вычисление;\n"
               "3. Выход.\n");
        c = getchar();
        switch (c) {
            case '1' :
                system("clear");
                result = newcalc();
                if (result == 0) {
                    printf("Успешно!\n");
                    getchar();
                }
                if (result == 1) {
                    printf("Неверный формат!\n");
                    getchar();
                }
                break;
            case '2' :
                system("clear");
                result = lastcalc();
                if (result == 0) {
                    printf("Успешно!");
                    getchar();
                }
                break;
            case '3' :
                system("clear");
                return 0;
            default:
                continue;
        }
    }
}

int newcalc(void) {
    int n1, x, m2, res;
    printf("Введите размер матриц A(n1Xx), B(xXm2):\n");

    printf("n1 - ");

    res = scanf("%d", &n1);
    clear();
    if (res == EOF || n1 < 1) {
        return 1;
    }

    printf("\nx - ");
    res = scanf("%d", &x);
    clear();
    if (res == EOF || x < 1) {
        return 1;
    }
    printf("\nm2 - ");

    res = scanf("%d", &m2);
    clear();
    if (res == EOF || m2 < 1) {
        return 1;
    }

    fstream size_f;
    size_f.open("storage_files/size_f.txt", fstream:: out);
    size_f << n1 << " " << x << " " << m2;
    size_f.close();

    int A[n1][x], B[x][m2], C[n1][m2];
    int i, j, k;

    fstream matrix_A, matrix_B, matrix_C;
    matrix_A.open("storage_files/matrix_A.txt", fstream:: out | fstream:: trunc);
    matrix_B.open("storage_files/matrix_B.txt", fstream:: out | fstream:: trunc);
    matrix_C.open("storage_files/matrix_C.txt", fstream:: out | fstream:: trunc);

    if (!matrix_A && !matrix_B && !matrix_C) {
        cout << "Ошибка!" << endl;
    } else {
        cout << "успешно!" << endl;

        srand(time(NULL));
        for (i = 0; i < n1; i++) {
            for (j = 0; j < x; j++) {
                A[i][j] = rand() % 10;
                matrix_A << A[i][j] << "\t";
                B[i][j] = rand() % 10;
                matrix_B << B[i][j] << "\t";
            }
            matrix_A << "\n";
            matrix_B << "\n";
        }

        for (i = 0; i < n1; i++) {
            for (j = 0; j < m2; j++) {
                C[i][j] = 0;
                for (k = 0; k < x; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
                matrix_C << C[i][j] << "\t";
            }
            matrix_C << "\n";
        }

        matrix_A.close();
        matrix_B.close();
        matrix_C.close();

        printf("A\n");
        for (i = 0; i < n1; i++) {
            for (j = 0; j < x; j++)
                printf("%d ", A[i][j]);
            printf("\n");
        }

        printf("B\n");
        for (i = 0; i < x; i++) {
            for (j = 0; j < m2; j++)
                printf("%d ", B[i][j]);
            printf("\n");
        }

        printf("C\n");
        for (i = 0; i < n1; i++) {
            for (j = 0; j < m2; j++)
                printf("%3d ", C[i][j]);
            printf("\n");
        }
        getchar();
        return 0;
    }
}

int lastcalc(void){
    int n1, x, m2;
    fstream size_f;
    size_f.open("storage_files/size_f.txt", fstream::in);
    size_f >> n1 >> x >> m2;
    size_f.close();

    int A[n1][x], B[x][m2], C[n1][m2];
    int i, j, k;

    fstream matrix_A, matrix_B, matrix_C;
    matrix_A.open("storage_files/matrix_A.txt", fstream::in);
    matrix_B.open("storage_files/matrix_B.txt", fstream::in);
    matrix_C.open("storage_files/matrix_C.txt", fstream::in);

    printf("A\n");
    for (i = 0; i < n1; i++) {
        for (j = 0; j < x; j++) {
            matrix_A >> A[i][j];
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("B\n");
    for (i = 0; i < x; i++) {
        for (j = 0; j < m2; j++) {
            matrix_B >> B[i][j];
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    printf("C\n");
    for (i = 0; i < n1; i++) {
        for (j = 0; j < m2; j++) {
            matrix_C >> C[i][j];
            printf("%3d ", C[i][j]);
        }
        printf("\n");
    }

    matrix_A.close();
    matrix_B.close();
    matrix_C.close();

    getchar();

    return 0;
}

void clear() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { };
}

#include <stdio.h>
#define lmax 22 

void input(int a[lmax][lmax],int *n){
    int k,n1;
    printf("Введите число n\n");
    do{
        k = scanf("%d", &n1);
        while (getchar() != '\n');
    }while (n1 <= 0 || n1 > lmax || k!=1);
    *n = n1;
    printf("Введите матрицу %d на %d\n", n1, n1);
    for (int i = 0; i < n1; i++){
        for (int j = 0; j < n1; j++){
            scanf("%d", &a[i][j]);
        }
    }
}

void func(int a[lmax][lmax], int *result, int n){
    int r = 0;
    int Z[lmax];
    for (int j = 0; j < n; j++){// i-строки,j-столбцы
        int max = a[0][j];
        for (int i = 0; i < n; i++){
            if (max < a[i][j]){
                max = a[i][j];
            }
        }
        Z[r] = max;
        r++;
    }
    int min = Z[0];
    for (int m = 0; m < r; m++){
        if (min > Z[m]){
            min = Z[m];
        }
    }
    *result = min;
}

int main(){
	printf("Лабораторная работа №3\n");
    printf("Выполнил: Алексеев Фёдор Павлович\n");
    printf("Группа: БИТ232\n");
    printf("Задание №2\n");
    int a[lmax][lmax], Z[lmax], n, m, nz, k, sum, result;
    input(a, &n);
    func(a, &result,n);
    printf("%d", result);
}

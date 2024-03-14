#include <stdio.h>
#include <stdlib.h>
#define lmax 100

int main()
{

    printf("Лабораторная работа №2\n");
    printf("Выполнил: Алексеев Фёдор Павлович\n");
    printf("Группа: БИТ232\n");
    printf("Задание №2\n\n");

    int temp;
    int n;
    printf("Введите длину массива a от 1 до lmax. n = ");

    do
    {
        temp = scanf("%d", &n);
        while(getchar() != '\n');
    } while(n <= 0 || n >= lmax || temp != 1);

    int A[n];
    printf("Введите массив A\n");

    for(int i = 0; i < n; i++) scanf("%d", &A[i]);
    
    int B[n];
    int abs_of_element;
    int last_digit;

    for(int i = 0; i < n; i++)
    {
        B[i] = 1;
        abs_of_element = abs(A[i]);
        do
        {
            last_digit = abs_of_element % 10;
            abs_of_element /= 10;
            B[i] *= last_digit;
        } while(abs_of_element != 0);
    }
    printf("\n");
    printf("Новый массив B\n");
    for(int i = 0; i < n; i++) printf("%d ", B[i]);

    return 0;
}

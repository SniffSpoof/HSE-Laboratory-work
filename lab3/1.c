#include <stdio.h>

void input(double x[], double y[], double *X){
    printf("\nВведите Х1, Х2, Х3: ");
    for(int i = 0; i < 3; i++) scanf("%lf", (x+i));
    
    printf("\nВведите Y1, Y2, Y3: ");
    for(int i = 0; i < 3; i++) scanf("%lf", (y+i));
    printf("\nВведите х: ");
    scanf("%lf", X);
} 

void calc(double x[], double y[], double X){
    double Y;
    
    if(x[0] <= X && X < x[1]){
        Y = y[0] + (y[1]-y[0])*(X-x[0])/(x[1]-x[0]);
        printf("%lf", Y);
    }
    else if(x[1] <= X && X < x[2]){
        Y = y[1] + (y[2]-y[1])*(X-x[1])/(x[2]-x[0]);
        printf("%lf", Y);
    }
    else if (X == x[2]){
        Y = y[2];
        printf("%lf", Y);
    }
    else{
        printf("Функция неопределенна для данного аргумента");
    }
    
}

int main()
{
    printf("Лабораторная работа №3\n");
    printf("Выполнил: Алексеев Фёдор Павлович\n");
    printf("Группа: БИТ232\n");
    printf("Задание №2\n");
    double x[3];
    double y[3];
    double X;
    input(x, y, &X);
    calc(x, y, X);
    return 0;
}

#include <stdio.h>
#include <math.h>
#define lmax 100

int main()
{
    int i,n;
    float x, h, a, r[lmax];
    
    printf ("Лабораторная работа №1\n");
    printf ("Выполнил: Алексеев Фёдор Павлович\n");
    printf ("Группа: БИТ232\n");
    printf ("\n");
    printf ("Задание №1\n");
    printf ("Введите длину массива R от 1 до %d: ", lmax);
        
    do {
        scanf ("%d", &n);
    }
    while (n<=0 || n>lmax);
    
    printf ("Введите переменную x: ");
    scanf ("%f", &x);
    printf ("Введите переменную h: ");
    scanf ("%f", &h);
    printf ("Введите переменную а: ");
    scanf ("%f", &a);
    
    for (i=1; i<=n; i++) { 
        r[i] = 5.5*sin (i*h) + cos (a*x + i*h);
    }
    
    printf ("Массив r из %d элементов: \n", n);
    for (i=1; i<=n; i++) { 
    printf ("%.2f ", r[i]);
    }
    printf ("\n\n");
    
    printf("Задание 2\n");
    int k = 0;
    int pmax = 1;
    
    for (int i = 2; i <= n; i++) {
        if (r[i] > r[pmax])
            pmax = i;
    }
    
    printf("Максимальное положительное число pmax = %.2f\n", r[pmax]);
    for (int i = 1; i <= n; i++) {
        if ((r[i] >= 0 && i < pmax) || (i >= pmax)) {
            k++;
            r[k] = r[i];
        }
    }
    
    if (k == n)
        printf("Нет удаления. В массиве осталось %d элементов: \n" , n);    
    
    printf("Новый массив из %d элементов \n" , k);
    for (int i = 1; i <= k; i++)
        printf("%.2f ", r[i]);
    printf("\n\n");
    
    printf("Задание 3\n");
    int nmin = 0;
    float sr = 0;
    for(i = 0; i < k; i++){
        if (r[nmin] >= r[i])
            nmin = i;
        }
    }
    if(nmin < 1){
        printf("Нет среднего значения");
    }
    else{
        for(i = 0; i <= nmin; i++){
            sr += r[i];
        }

        printf("sr = %f",(sr/(nmin+1)));
    }
    
    return 0;
}

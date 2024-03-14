#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define lmax 200

void input(int a[lmax], int *n)
{
    int n1, k;
	printf("Введите длину массива \n");
	do{
		k = scanf("%d", &n1);
		while(getchar() != '\n');
	}while(n1 <= 0 || n1 >= lmax || k != 1);
	*n=n1;
	printf("Введите массив из %d элементов \n", n1);
	for(int i = 0; i < n1; i++) 
	{
		do
		{
			k = scanf("%d", &a[i]);
			while(getchar() != '\n');
		}while(k != 1);
	}
}

void func1(int a[lmax], int e[lmax], int *n)
{
	int n1, k;
	n1 = *n;
	k = 0;
	for(int i = 0; i < n1; i++){
	    e[i] = 1;
	}
	for(int i = 0; i < n1; i++)
	{
		for(int j = i+1; j < n1; j++)
		{
			if(a[i] == a[j]) 
			{
				e[i]++;
				for(k = j; k < n1; k++){
				a[k] = a[k+1];
				}
				n1--;
				j--;
			}
		}
	}
	for(int j = 0; j < k-1; j++){
        printf("Число %d встретилось %d раз(a)\n", a[j], e[j]);
    }
	*n = n1;
}

void func2(int a[lmax], int b[lmax], int e[lmax], int *k, int *n){
    int n1 = *n, k1 = *k;
    k1 = 0;
    for (int j = 0; j < n1; j++){
        if (e[j] == 1){
            k1++;
            b[k1]=a[j];
        }
    }
    if (k1==0){
        printf("В массиве нет неповторяющихся элементов");
    }
    if (k1!=0){
        printf("Получен массив: ");
        for (int j = 1; j < k1+1; j++){
            printf("%d ", b[j]);
        }
    }
}

int main(){
	printf("Лабораторная работа №3\n");
    printf("Выполнил: Алексеев Фёдор Павлович\n");
    printf("Группа: БИТ232\n");
    printf("Задание №3\n");
	int a[lmax],b[lmax],e[lmax],num[lmax],n,m,i,k;
	input (a, &n);
	func1 (a, e, &n);
	func2 (a, b, e, &k, &n);
	return 0;
}

#include <stdio.h>
#define lmax 10

int main()
{
    printf("Лабораторная работа №2\n");
    printf("Выполнил: Алексеев Фёдор Павлович\n");
    printf("Группа: БИТ232\n");
    printf("Задание №1\n");
    
    int n, m;
    int temp;
    printf("Введите количество строк и столбцов от 1 до lmax\n");
    
    do
    {
        temp = scanf("%d%d", &n, &m);
        while (getchar() != '\n');
	    } while (n <= 0 || m <= 0 || n >= lmax || m >= lmax || temp != 2);
    
    int Q[n][m];
    printf("Введите матрицу Q\n");
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) scanf("%d", &Q[i][j]);
    }
    
    int z_len;
    printf("Введите длину массива Z от 1 до lmax. z_len = ");
    
    do
    {
        temp = scanf("%d", &z_len);
        while (getchar() != '\n');
    } while (z_len <= 0 || z_len >= lmax || temp != 1);
    
    int Z[z_len];
    printf("Введите массив Z\n");
    
    for(int i = 0; i < z_len; i++) scanf("%d", &Z[i]);
    
    int S[n];
    for(int i = 0; i < n; i++)
    {
        S[i] = 0;
        for(int j = 0; j < m; j++)
        {
            S[i] += Q[i][j];
        }
    }
    for(int i = 0; i < n; i++) printf("%d ", S[i]);
    printf("\n");
    
    int flag_current; int flag_global;
    int buffer;
    int z;
    for(int i = 0; i < n; i++)
    {
        flag_current = 0;
        z = 0;
        do
        {
            if(Z[z] == S[i])
            {
                flag_global = 1;
                flag_current = 1;
            }
            z++;
        } while(flag_current == 0 && z != z_len);
        
        if(flag_current == 1)
        {
            for(int j = 0; j < m-1; j++)
            {
                for(int g = j+1; g < m; g++)
                {
                    if(Q[i][j] < Q[i][g])
                    {
                        buffer = Q[i][j];
                        Q[i][j] = Q[i][g];
                        Q[i][g] = buffer;
                    }
                }
            }
        }
    }
    
    if(flag_global == 0) printf("Нет изменений в матрице Q\n");
    else
    {
        printf("Измененная матрица Q\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++) printf("%d ", Q[i][j]);
            printf("\n");
        }
    }
    return 0;
}

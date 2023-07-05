#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>



void fill_arr(int *mass, int n);
int result(int *mass, int n);
int sum_between_zeroes(int *mass, int n);
int size();

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int code = 1 * 10, rt;
    while (code != 27)
    {
        printf("\n");
        int n = size();
        int mass[n];
        fill_arr(mass, n);
        for (int i = 0; i < n; i++)
        {
            printf("\t [%d]:%d", i, mass[i]);
        }
        rt = result(mass, n);
        if (rt == 1)
        {
            printf("\nОтримали: %d", sum_between_zeroes(mass,n));
        }
        rt=0;
        n=0;
        printf("\nВихід - Esc | Продовжити - Enter");
        code = getch();
    }
    return 0;
}

void fill_arr(int *mass, int n)
{
    printf("\nВведіть елементи масиву:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &mass[i]);
    }
}

int result(int *mass, int n)
{
    int res = 0, i = n - 1, m_i = 0;
    for (i; i != 0; i--)
    {
        m_i = i - 1;
        if (mass[i] == 0 && (m_i >= 0 && mass[m_i] == 0))
        {
            printf("\nНулі йдуть підряд, отримаємо: 0");
            res=0;
            return 0;
        }
    }
    for(int j = 0; j < n; j++)
    {
        if (mass[j]==0)
        {
            return 1;
        }
    }
    printf("\nУ даному масиві відсутні нулі");
}
int sum_between_zeroes(int *mass, int n)
{
    int sum = 0, start = -1;
    for (int i = 0; i < n; i++)
    {
        if (mass[i] == 0)
        {
            if (start != -1 && i > start + 1)
            {
                for (int j = start + 1; j < i; j++)
                {
                    sum += mass[j];
                }
                return sum;
            }
            start = i;
        }
    }
    return sum;
}
int size()
{
    int n;
    do
    {
        printf("\nВведіть розмір масиву: ");
        scanf("%d", &n);
    } while (n < 1);
    return n;
}

#include <stdio.h>
#include <stdlib.h>

#define CYLINDERS 1000
#define SIZE_OF_ARRAY 100

int main(int argc, char **argv)
{
    srand(time(NULL));
    int start;
    int A[SIZE_OF_ARRAY];
    int i = 0;
    printf("Please enter a number (0~999): ");
    scanf("%d", &start);
    for (i = 0; i < SIZE_OF_ARRAY; i++)
    {
        A[i] = rand() % 1000;
    }
    printf("FCFS：%d\n", FCFS(start, A));
    printf("SSTF：%d\n", SSTF(start, A));
    printf("SCAN：%d\n", SCAN(start, A));
    printf("C_SCAN：%d\n", C_SCAN(start, A));
}

int FCFS(int start, int *A)
{
    int sum = 0;
    int prev = start;
    for (int i = 0; i < SIZE_OF_ARRAY; i++)
    {
        sum = sum + abs(A[i] - prev);
        prev = A[i];
    }
    // printf("%d\n", sum);
    return sum;
}

int compare(const void *a, const void *b)
{
    return *(int *)a > *(int *)b;
}

int SSTF(int start, int *A)
{
    int sum = 0;
    int prev = start;
    int bfore;
    int after;
    int B[SIZE_OF_ARRAY];
    int countbfore;
    int countafter;

    for (int i = 0; i < SIZE_OF_ARRAY; i++)
    {
        B[i] = A[i];
    }
    qsort(B, SIZE_OF_ARRAY, sizeof(int), compare); // 排序
    // for (int i = 0; i < SIZE_OF_ARRAY; i++)
    // {
    //     printf("%d\n", B[i]);
    // }

    if (B[SIZE_OF_ARRAY - 1] < start) //排序後，start 的位置在哪兩個位置中間
    {
        bfore = SIZE_OF_ARRAY - 1;
        after = SIZE_OF_ARRAY;
        countbfore = SIZE_OF_ARRAY;
        countafter = 0;
    }
    else
    {
        for (int i = 0; i < SIZE_OF_ARRAY; i++)
        {

            if (B[i] >= start)
            {
                bfore = i - 1;
                after = i;
                countbfore = i;
                countafter = SIZE_OF_ARRAY - i;
                break;
            }
        }
    }

    int a_p; // after 和 prev 的距離(a-p)
    int p_b; // prev 和 before 的距離(p-b)
    while (countbfore != 0 && countafter != 0)
    {
        a_p = B[after] - prev;
        p_b = prev - B[bfore];
        if (p_b < a_p)
        {
            sum += p_b;
            prev = B[bfore];
            countbfore -= 1;
            bfore -= 1;
            // printf("%d\n", sum);
        }
        else
        {
            sum += a_p;
            prev = B[after];
            countafter -= 1;
            after += 1;
            // printf("%d\n", sum);
        }
    }

    if (countbfore == 0)
    {
        sum += B[SIZE_OF_ARRAY - 1] - prev;
    }
    if (countafter == 0)
    {
        sum += prev - B[0];
    }

    // printf("%d\n", sum);

    return sum;
}

int SCAN(int start, int *A)
{
    int sum = 0;
    int bfore;
    int B[SIZE_OF_ARRAY];

    for (int i = 0; i < SIZE_OF_ARRAY; i++)
    {
        B[i] = A[i];
    }
    qsort(B, SIZE_OF_ARRAY, sizeof(int), compare); // 排序

    if (B[SIZE_OF_ARRAY - 1] < start) //排序後，start 的前一個index是多少
    {
        bfore = SIZE_OF_ARRAY - 1;
    }
    else
    {
        for (int i = 0; i < SIZE_OF_ARRAY; i++)
        {
            if (B[i] >= start)
            {
                bfore = i - 1;
                break;
            }
        }
    }

    if (bfore == -1)
    {
        sum = B[SIZE_OF_ARRAY - 1] - start;
    }
    else
    {
        sum = (CYLINDERS - 1 - start) + (CYLINDERS - 1 - B[0]);
    }

    // printf("%d\n", sum);

    return sum;
}

int C_SCAN(int start, int *A)
{
    int sum = 0;
    int bfore;
    int B[SIZE_OF_ARRAY];

    for (int i = 0; i < SIZE_OF_ARRAY; i++)
    {
        B[i] = A[i];
    }
    qsort(B, SIZE_OF_ARRAY, sizeof(int), compare); // 排序

    if (B[SIZE_OF_ARRAY - 1] < start) //排序後，start 的前一個index是多少
    {
        bfore = SIZE_OF_ARRAY - 1;
    }
    else
    {
        for (int i = 0; i < SIZE_OF_ARRAY; i++)
        {
            if (B[i] >= start)
            {
                bfore = i - 1;
                break;
            }
        }
    }

    if (bfore == -1)
    {
        sum = B[SIZE_OF_ARRAY - 1] - start;
    }
    else
    {
        sum = (CYLINDERS - 1 - start) + (CYLINDERS - 1) + B[bfore];
    }

    // printf("%d\n", sum);
    return sum;
}
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h> // for intptr_t
#include <stdbool.h>

#define NUMBER_OF_THREADS 5
#define NUMBER_OF_RESOURCES 3
int available[NUMBER_OF_RESOURCES];
int allocation[NUMBER_OF_THREADS][NUMBER_OF_RESOURCES];
int max[NUMBER_OF_THREADS][NUMBER_OF_RESOURCES];
int need[NUMBER_OF_THREADS][NUMBER_OF_RESOURCES];
bool finish[NUMBER_OF_THREADS]; // make sure if all the threads finish their job
// int request[NUMBER_OF_RESOURCES + 1]; // all the threads(customers) can only submit their request by this request array, request[i-1] store the id of that process
char type_of_res[3] = {'A', 'B', 'C'};
pthread_mutex_t mutex;
void *thread_func();
bool banker(int *req, int id);
void releaseResource(int id);
void getResource(int *req, int id);

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    pthread_t thread[NUMBER_OF_THREADS];
    pthread_mutex_init(&mutex, NULL);

    // initialize available
    for (int i = 0; i < NUMBER_OF_RESOURCES; i++)
    {
        printf("please enter the number of resource of %c: ", type_of_res[i]);
        scanf("%d", &available[i]);
    }
    // initialize allocation
    for (int i = 0; i < NUMBER_OF_THREADS; i++)
    {
        for (int j = 0; j < NUMBER_OF_RESOURCES; j++)
        {
            allocation[i][j] = 0;
        }
    }

    // initialize Max
    for (int i = 0; i < NUMBER_OF_THREADS; i++)
    {
        printf("Max resource needed by thread %d (A, B, C): ", i);
        for (int j = 0; j < NUMBER_OF_RESOURCES; j++)
        {
            max[i][j] = rand() % (available[j] + 1);
            printf("%d ", max[i][j]);
        }
        printf("\n");
    }

    // initialize need
    for (int i = 0; i < NUMBER_OF_THREADS; i++)
    {
        for (int j = 0; j < NUMBER_OF_RESOURCES; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // initialize finish
    for (int i = 0; i < NUMBER_OF_THREADS; i++)
    {
        int isFinishWhenStart = true;
        for (int j = 0; j < NUMBER_OF_RESOURCES; j++)
        {
            if (need[i][j] != 0)
            {
                isFinishWhenStart = false;
                break;
            }
        }
        finish[i] = isFinishWhenStart;
    }

    // create p_thread
    for (int i = 0; i < NUMBER_OF_THREADS; i++)
    {
        pthread_create(&thread[i], NULL, &thread_func, (void *)(intptr_t)i); // special usage
    }

    // join p_thread
    for (int i = 0; i < NUMBER_OF_THREADS; i++)
    {
        pthread_join(thread[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    printf("\n*************Finish all the threads**************\n\n");

    return 0;
}

void *thread_func(int id)
{
    printf("thread %d created.\n", id);
    int requestArray[NUMBER_OF_RESOURCES];
    while (!finish[id])
    {
        // printf("thread %d not finished.\n", id);
        for (int i = 0; i < NUMBER_OF_RESOURCES; i++)
        {
            if (need[id][i] == 0)
            {
                requestArray[i] = 0;
            }
            else
            {
                requestArray[i] = rand() % (need[id][i] + 1);
            }
        }

        bool isReqNone = true;
        for (int i = 0; i < NUMBER_OF_RESOURCES; i++)
        {
            if (requestArray[i] != 0)
            {
                isReqNone = false;
                break;
            }
        }

        if (isReqNone)
        {
            continue;
        }

        pthread_mutex_lock(&mutex);
        printf("\n---------------------------------------------------------------\n");
        printf("Request from thread %d is: ", id);
        for (int i = 0; i < NUMBER_OF_RESOURCES; i++)
        {
            printf("%d ", requestArray[i]);
        }
        printf("\n");

        if (banker(requestArray, id))
        {
            getResource(requestArray, id);

            printf("\nProvide resources to thread %d\n", id);
            printf("\nResources OS possesses after allocation : ");
            for (int i = 0; i < NUMBER_OF_RESOURCES; i++)
            {
                printf("%c:", type_of_res[i]);
                printf("%d  ", available[i]);
            }
            printf("\n");

            printf("\nCurrent need of all threads after allocation: ");
            printf("\n");
            for (int i = 0; i < NUMBER_OF_THREADS; i++)
            {
                printf("%d : ", i);
                {
                    for (int j = 0; j < NUMBER_OF_RESOURCES; j++)
                        printf("%d ", need[i][j]);
                }
                printf("\n");
            }
        }

        bool checkNeedZero = true;
        for (int i = 0; i < NUMBER_OF_RESOURCES; i++)
        {
            if (need[id][i] != 0)
            {
                checkNeedZero = false;
                break;
            }
        }

        if (checkNeedZero)
        {
            releaseResource(id);
            printf("\nThread %d return resources to OS, resources OS possesses now : ", id);
            for (int i = 0; i < NUMBER_OF_RESOURCES; i++)
            {
                printf("%c:", type_of_res[i]);
                printf("%d  ", available[i]);
            }
            printf("\n");
        }
        pthread_mutex_unlock(&mutex);
    }
}
void getResource(int *req, int id)
{
    for (int i = 0; i < NUMBER_OF_RESOURCES; i++)
    {
        need[id][i] = need[id][i] - req[i];
        allocation[id][i] = allocation[id][i] + req[i];
        available[i] = available[i] - req[i];
    }
}
void releaseResource(int id)
{
    for (int i = 0; i < NUMBER_OF_RESOURCES; i++)
    {
        available[i] = available[i] + allocation[id][i];
        allocation[id][i] = 0;
        finish[id] = true;
    }
}

bool banker(int *req, int id)
{
    // printf("start to calculate thread %d's request.\n", id);

    printf("\nCurrent need of all threads: ");
    printf("\n");
    for (int i = 0; i < NUMBER_OF_THREADS; i++)
    {
        printf("%d : ", i);
        {
            for (int j = 0; j < NUMBER_OF_RESOURCES; j++)
                printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    // first step
    for (int i = 0; i < NUMBER_OF_RESOURCES; i++)
    {
        if (req[i] > need[id][i])
        {
            printf("\nthread %d request more than it need!\n", id);
            return false;
        }
    }

    // second step
    for (int i = 0; i < NUMBER_OF_RESOURCES; i++)
    {
        if (req[i] > available[i])
        {
            printf("OS doesn't have enough resources to provide!");
            return false;
        }
    }

    // printf("prepare %d's safety algo. \n", id);

    // third step
    int B_available[NUMBER_OF_RESOURCES];
    int B_need[NUMBER_OF_THREADS][NUMBER_OF_RESOURCES];
    int B_allocation[NUMBER_OF_THREADS][NUMBER_OF_RESOURCES];

    // B_available
    for (int i = 0; i < NUMBER_OF_RESOURCES; i++)
    {
        B_available[i] = available[i] - req[i];
    }

    // B_need
    for (int i = 0; i < NUMBER_OF_THREADS; i++)
    {
        for (int j = 0; j < NUMBER_OF_RESOURCES; j++)
        {
            B_need[i][j] = need[i][j];
        }
    }
    for (int i = 0; i < NUMBER_OF_RESOURCES; i++)
    {
        B_need[id][i] = need[id][i] - req[i];
    }

    // B_allocaction
    for (int i = 0; i < NUMBER_OF_THREADS; i++)
    {
        for (int j = 0; j < NUMBER_OF_RESOURCES; j++)
        {
            B_allocation[i][j] = allocation[i][j];
        }
    }
    for (int i = 0; i < NUMBER_OF_RESOURCES; i++)
    {
        B_allocation[id][i] = allocation[id][i] + req[i];
    }

    printf("\n****start thread %d's safety algo.**** \n", id);
    // forth step: safety algo
    // 1.
    bool Finish[NUMBER_OF_THREADS];
    for (int i = 0; i < NUMBER_OF_THREADS; i++)
    {
        Finish[i] = finish[i];
    }
    int Work[NUMBER_OF_RESOURCES];
    for (int i = 0; i < NUMBER_OF_RESOURCES; i++)
    {
        Work[i] = B_available[i];
    }

    // ---------------------print-------------------------
    printf("\nWork : ");
    for (int i = 0; i < NUMBER_OF_RESOURCES; i++)
    {
        printf("%d ", Work[i]);
    }
    printf("\n");
    printf("\nB_need : ");
    printf("\n");
    for (int i = 0; i < NUMBER_OF_THREADS; i++)
    {
        printf("%d : ", i);
        {
            for (int j = 0; j < NUMBER_OF_RESOURCES; j++)
                printf("%d ", B_need[i][j]);
        }
        printf("\n");
    }
    printf("\nB_allocation : ");
    printf("\n");
    for (int i = 0; i < NUMBER_OF_THREADS; i++)
    {
        printf("%d : ", i);
        {
            for (int j = 0; j < NUMBER_OF_RESOURCES; j++)
                printf("%d ", B_allocation[i][j]);
        }
        printf("\n");
    }

    // ---------------------print-------------------------

    // 2.
    for (int i = 0; i < NUMBER_OF_THREADS; i++)
    {
        if (Finish[i] == false)
        {
            bool pass = true;
            for (int j = 0; j < NUMBER_OF_RESOURCES; j++) // check if the thread can finish its job after allocation
            {
                if (B_need[i][j] > Work[j])
                {
                    pass = false;
                }
            }
            if (pass)
            {
                Finish[i] = true;
                for (int j = 0; j < NUMBER_OF_RESOURCES; j++)
                {
                    Work[j] = Work[j] + B_allocation[id][j];
                }
                i = 0;
                continue;
            }
        }
    }

    bool isSafe = true;
    for (int i = 0; i < NUMBER_OF_THREADS; i++)
    {
        if (Finish[i] == false)
        {
            isSafe = false;
        }
    }
    if (isSafe)
    {
        printf("\nthread %d's request is safe\n", id);
    }
    else
    {
        printf("\nthread %d's request is not safe\n", id);
    }
    // sleep(2);
    return isSafe;
}
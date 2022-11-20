#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <math.h>
#include <stdlib.h>

int n = 0;
int n_thread = 0;
int point  = 0;
pthread_mutex_t mutex;

void *count(void *X)
{ 
    srand( time(NULL) ); // set the time to the seed of random number, the rand() would from 0 to RAND_MAX
    /* initialize random numbers */
    for (int i=0; i < n_thread; i++)
    {	
        
        double X = (double)rand() / RAND_MAX; // X is between 0 ~ 1
        double Y = (double)rand() / RAND_MAX; // Y is between 0 ~ 1
        
        if (((X * X) + (Y * Y)) <= 1)  // This would be the amount of points in a sector
        {
            pthread_mutex_lock(&mutex);
            point++;
            pthread_mutex_unlock(&mutex);

        }
    }
    return NULL;
}

int main()
{
    pthread_t thread1, thread2, thread3, thread4;
    pthread_mutex_init(&mutex, NULL);

    
    do
	{
        printf("Please enter a positive number? \n");
        scanf("%d", &n);  	
	}while (n <= 0);

    n_thread = n/4;

    pthread_create(&thread1, NULL, &count, NULL);
    pthread_create(&thread2, NULL, &count, NULL);
    pthread_create(&thread3, NULL, &count, NULL);
    pthread_create(&thread4, NULL, &count, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);

    pthread_mutex_destroy(&mutex);
    
    double total_points = 4.0 * point;
    double pi = total_points / n;
    printf("pi is : %f \n", pi);  
    return 0;
}
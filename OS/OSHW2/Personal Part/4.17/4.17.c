#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <math.h>
#include <stdlib.h>

int n = 0;
int point  = 0;

void *count(void *X)
{ 
    srand( time(NULL) ); // set the time to the seed of random number, the rand() would from 0 to RAND_MAX
    /* initialize random numbers */
    for (int i=0; i < n; i++)
    {	
        
        double X = (double)rand() / RAND_MAX; // X is between 0 ~ 1
        double Y = (double)rand() / RAND_MAX; // Y is between 0 ~ 1
        
        if (((X * X) + (Y * Y)) <= 1)  // This would be the amount of points in a sector
        {
            point++;
        }
    }
    return NULL;
}

int main()
{
    pthread_t thread;
    
    do
	{
        printf("Please enter a positive number? \n");
        scanf("%d", &n);  	
	}while (n <= 0);
  
    pthread_create(&thread, NULL, &count, NULL);
    pthread_join(thread, NULL);
    
    double total_points = 4.0 * point;
    double pi = total_points / n;
    printf("pi is : %f \n", pi);  
    return 0;
}
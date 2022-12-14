#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <math.h>
#include <stdlib.h>

int n = 0;
int A[1000];
int i;

void *f(void *X)
{ 
    A[0] = 1;
    A[1] = 1;
    if( n >= 3 ){
        for(i = 2; i < n; i++){
            A[i] = A[i-1] + A[i-2];
        }
    }
}

int main()
{
    pthread_t thread;
    
    do
	{
        printf("Please enter a positive number? \n");
        scanf("%d", &n);  	
	}while (n <= 0);
  
    pthread_create(&thread, NULL, &f, NULL);
    pthread_join(thread, NULL);
    printf("The Fibonacci sequence from the first term to the %dth term : \n", n);
    for(i = 0; i < n; i++ ){
        printf("%d", A[i]);
        printf(" ");
    }
   
}
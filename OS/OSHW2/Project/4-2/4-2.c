#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <math.h>
#include <stdlib.h>


int n = 12;
int A[12]={1,6,4,9,7,0,10,3,2,8,5,11};
int i;
int j;

typedef struct Arr
{
    int low;
    int high;
} Array;

void swap(int* A, int* B){
    int temp = *A;
    *A = *B;
    *B = temp; 
}

void *smaller_list(void *X)
{ 
    Array* sa = X;
    
    int low = sa->low;
    int high = sa->high;

    // printf("%d", low);
    // printf("%d", high);
    // printf("\n");

    for(i = low; i<= high; i++){
        int temp = i;
        for (j = i; j <= high-1; j++){
            if (A[temp] > A[j+1]){
                temp = j+1;
            }      
        }

        swap(&A[temp], &A[i]);
    }
    // for(i = 0; i < n; i++ ){
    //     printf("%d", A[i]);
    //     printf(" ");
    // }

}

void *merge(void *X)
{ 
    int b[n];
    int left = 0;
    int right = n/2;
    int index = 0;

    while(left < n/2 && right < n ){
        if(A[left] < A[right]){
            b[index] = A[left]; 
            index += 1;
            left += 1;
        }
        else{
            b[index] = A[right];
            index += 1;
            right += 1;
        }
    }

    while(left < n/2){
        b[index] = A[left]; 
            index += 1;
            left += 1;
    }

    while(right < n){
        b[index] = A[right];
            index += 1;
            right += 1;
    }
    
    for(i = 0; i < n; i++){
        A[i]=b[i];
    }
}

int main()
{
    pthread_t thread1, thread2, thread3;
    Array A1;
    Array A2;

    int mid = n/2; 

    A1.low = 0;
    A1.high = mid - 1;
    A2.low = mid;
    A2.high = n - 1; 

    
  
    pthread_create(&thread1, NULL, &smaller_list, &A1);
    pthread_create(&thread2, NULL, &smaller_list, &A2);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_create(&thread3, NULL, &merge, NULL);
    pthread_join(thread3, NULL);
    printf("The sorted array: ");
    for(i = 0; i < n; i++ ){
        printf("%d", A[i]);
        printf(" ");
    }
    printf("\n");
   
}
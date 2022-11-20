#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex;

void *NorthFarmer(void* arg){ // North Farmer Thread
	pthread_mutex_lock(&mutex); 
	printf("North farmer is on the bridge. \n");
    sleep(2);
	printf("North farmer leaves the bridge. \n");
	pthread_mutex_unlock(&mutex); 
	pthread_exit(0); // Exit Thread.
}

void *SouthFarmer(void* arg){ // North Farmer Thread
	pthread_mutex_lock(&mutex); 
	printf("South farmer is on the bridge. \n");
    sleep(2);
	printf("South farmer leave the bridge. \n");
	pthread_mutex_unlock(&mutex); 
	pthread_exit(0); // Exit Thread.
}

int main(){
	pthread_t North[10]; // North Thread
	pthread_t South[10]; // South Thread
	pthread_mutex_init(&mutex,NULL); 

	for(int i = 0; i < 10; i++){ // create all threads
    	pthread_create(&North[i], NULL, NorthFarmer, NULL); 
    	pthread_create(&South[i], NULL, SouthFarmer, NULL); 

   	}

   	for(int i = 0; i < 10; i++){ 
      	pthread_join(North[i],NULL); 
    	pthread_join(South[i],NULL); 
   	}

    printf("All the farmers cross the bridge. \n");
   	pthread_mutex_destroy(&mutex); 
   	return 0;
}

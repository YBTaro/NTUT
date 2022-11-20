#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int A[20];
int numOfFrames = 0;
int i;
int j;

int FIFO();
int LRU();
int OPT();

int main(int argc, char **argv) {
    while(numOfFrames <= 0 || numOfFrames > 7){
        printf("Please enter the number of frame (1~7):");
        scanf("%d", &numOfFrames);
    }
    srand( time(NULL) ); 
    for(i = 0; i < 20; i++){
        A[i] = rand() % 10;
    }

    printf("The random Pages : ");
    for(i = 0; i < 20; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    printf("FIFO : %d\n", FIFO());
    printf("LRU : %d\n", LRU());
    printf("OPT : %d\n", OPT());
   
}

int FIFO(){
    int* frames = malloc(sizeof(int) * numOfFrames);
    for(i = 0; i < numOfFrames; i++){
        frames[i] = -1;
    }

    // for(i = 0; i < numOfFrames; i++){
    //     printf("%d ", frames[i]);
    // }

    int pointer = 0;
    int page;
    int numOfFaults = 0;

    for(i = 0; i < 20; i++){
        page = A[i];
        int findPage = 0;
        for(j = 0; j < numOfFrames; j++){
            if(page == frames[j]){
                // printf("find");
                findPage = 1;
                break;
            }
        }
        if(findPage == 0){
            // printf("fault \n");
            frames[pointer] = page;
            numOfFaults++;
            pointer = (pointer + 1) % numOfFrames; 
        }
    }

    free(frames);
    return numOfFaults;
    // return 0;

}

int LRU(){
    int* frames = malloc(sizeof(int) * numOfFrames);
    int* framesCounter = malloc(sizeof(int) * numOfFrames);
    for(i = 0; i < numOfFrames; i++){
        frames[i] = -1;
    }
    for(i = 0; i < numOfFrames; i++){
        framesCounter[i] = -1;
    }

    // for(i = 0; i < numOfFrames; i++){
    //     printf("%d ", frames[i]);
    // }

    int page;
    int numOfFaults = 0;

    for(i = 0; i < 20; i++){
        page = A[i];
        int findPage = 0;
        for(j = 0; j < numOfFrames; j++){
            if(page == frames[j]){
                // printf("find");
                findPage = 1;
                framesCounter[j] = i; // update the recently used
                break;
            }
        }
        if(findPage == 0){
            // printf("fault \n");
            int least = i; // the least recently used
            int pointer = 0; // the least recently used pointer
            for(j = 0; j < numOfFrames; j++){
                if(framesCounter[j] < least){
                    least = framesCounter[j];
                    pointer = j;
                }
            }
            frames[pointer] = page;
            framesCounter[pointer] = i;
            numOfFaults++;

            
        }
    }

    free(frames);
    free(framesCounter);
    return numOfFaults;
    // return 0;

}

int OPT(){
    // printf("start");
    int* frames = malloc(sizeof(int) * numOfFrames);
    int* framesCount = malloc(sizeof(int) * numOfFrames);
    for(i = 0; i < numOfFrames; i++){
        frames[i] = -1;
    }

    // for(i = 0; i < numOfFrames; i++){
    //     printf("%d ", frames[i]);
    // }

    int page;
    int numOfFaults = 0;

    // printf("start");

    for(i = 0; i < 20; i++){
        page = A[i];
        int findPage = 0;
        for(j = 0; j < numOfFrames; j++){
            if(page == frames[j]){
                // printf("find");
                findPage = 1;
                break;
            }
        }

        

        if(findPage == 0){
            // printf("fault \n");
            for(j = 0; j < numOfFrames; j++){ // initialize the page count
                if(frames[j] == -1){
                    framesCount[j] = 21; // set the frames haven't been used to the largest number
                }
                else{
                    framesCount[j] = 20; // others set to 20
                }

            }
            

            for(j = 0; j < numOfFrames; j++){ // count when each page's next usage is
                for(int k = i + 1; k < 20; k++){ // k is the pointer after i
                    
                    if(frames[j] == A[k]){
                        framesCount[j] = k;
                        break;
                    }
                        
                    }


            }



            // printf("start to pick");
            int pointer = 0;
            int most = 0; // record the largest number in framesCount
            for(j = 0; j < numOfFrames; j++){
                if(framesCount[j] > most){
                    most = framesCount[j];
                    pointer = j;
                }
            }

            frames[pointer] = page;
            numOfFaults++;


        }
        // for(j=0; j< numOfFrames; j++){
        //     printf("%d", frames[j]);
        // }
        // printf("\n");
    }

    free(frames);
    free(framesCount);
    return numOfFaults;
    // return 0;

}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char* argv[]){
    int n;
    printf("Please enter a positive integer： ");
    scanf("%d", &n);
    while (n < 1){
        printf("Please enter a positive integer： ");
        scanf("%d", &n);
    }
    int pid = fork();
    printf("your pid is %d\n", pid);
    if (pid == -1){
        printf("fork() Error!");
    }

    if (pid > 0){
        wait(NULL);
    }
    else{
        while( n != 1){
            if((n % 2) == 0){
                printf("%d\n", n);
                n = n/2;
                if(n == 1){
                    printf("%d\n", n);
                }
            }
            else{
                printf("%d\n", n);
                n = 3*n + 1;
            }
        }
        
    }

    return 0;
}
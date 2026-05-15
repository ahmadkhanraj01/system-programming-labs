#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Usage: %s <number_of_processes>\n",argv[0]);
        return 1;
    }
    int n = atoi(argv[1]);
    pid_t pid;
    for(int i = 1; i<=n; i++){
        pid = fork();
        if(pid <0){
            perror("Fork Faield ");
            exit(1);
        }
        printf("i = %d |PID= %d| PPID= %d| Child PID= %d\n", i, getpid(), getppid(), pid);
        if(pid >0){
            break;
        }
    }
    return 0;
}
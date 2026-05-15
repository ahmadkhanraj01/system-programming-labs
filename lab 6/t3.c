#include<stdio.h>
#include<unistd.h>
int main(){

    int fd[2];
    pipe(fd);
    if(fork()==0){
        close(fd[1]);
        int value;
        read(fd[0], &value, sizeof(value));
        printf("Child received: %d\n",value);
    }else{
        close(fd[0]);
        int value = 100;
        write(fd[1], &value, sizeof(value));
        printf("Parent sent: %d\n",value);
    }
    
    return 0;
}

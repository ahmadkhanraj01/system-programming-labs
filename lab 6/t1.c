#include<stdio.h>
#include<unistd.h>
int main(){

    if (fork() ==0)
    {
        printf("Child: input task\n");
    }
    else{
        printf("Parent: Output Task\n");
    }
    
    return 0;
}

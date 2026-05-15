#include<stdio.h>
#include<unistd.h>
int main(){
    int start, end , sum = 0;

    if (fork() ==0)
    {
        start =1;
        end = 10;
    }
    else{
        start =11;
        end = 20;
    }
    for (int i = start; i <= end; i++)
    {
        sum +=1;
    }
    printf("Sum from %d to %d = %d\n", start, end, sum);
    return 0;
}

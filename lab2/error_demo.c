#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(){
    if(close(-1) == -1){
        printf("Error number: %d\n",errno);
        perror("close error");
        printf("Using strerror: %s\n", strerror(errno));
    }
    return 0;
}
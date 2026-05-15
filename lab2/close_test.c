#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

int main(){
    printf("SUCCESS CASE\n");
    int fd = open ("text.txt", O_CREAT|O_WRONLY,0644);
    if(fd >= 0){
        int result = close(fd);
        if(result >= 0){
            printf("File Closed Successfully.\n");
        }
    }
    printf("FAILURE CASE\n");
    if(close(-1) == -1){
        printf("\nReturn value: -1\n");
        printf("Error number: %d\n",errno);
        perror("Using perror");
        printf("Using sterror: %s\n",strerror(errno));
    }
    return 0;
}
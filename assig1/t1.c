#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int fd;
    char buffer[100];
    int bytes_read;

    fd = open("data.txt",O_RDONLY);
    if (fd == -1)
    {
        perror("Error opeining files");
        return 1;
    }
    bytes_read = read(fd, buffer,sizeof(buffer)-1);
    if (bytes_read == -1)
    {
        perror("Error reading file");
        close(fd);
        return 1;
    }
    buffer[bytes_read]='\0';
    printf("File contents: \n%s\n",buffer);
    close(fd);
    return 0;   
    
}
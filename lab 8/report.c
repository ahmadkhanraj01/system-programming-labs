#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>

int main(int argc, char *argv[]){
    if ((argc -1)%2 != 0)
    {
        write(1,"Error: Even number of files required\n",38);
        return 1;
    }
    for(int i =1 ; i<argc; i+=2){
        if (fork() == 0)
        {
            int src = open(argv[i],O_RDONLY);
            int dest = open(argv[i+1],O_WRONLY|O_CREAT|O_TRUNC,0666);
            char buf[1024];
            int n;
            while ((n = read(src,buf,1024))>0)
            {
                write(dest,buf,n);
            }
            close(src);
            close(dest);
            return 0;
        }
        
    }
    while (wait(0)>0);
    return 0;
    
}
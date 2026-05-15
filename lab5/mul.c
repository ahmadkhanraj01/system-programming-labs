#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[]){
    if(argc < 2){
        printf("Useage: %s num1 num2 ... \n",argv[0]);
        return 1;
    }
    int mul =01;
    for(int i =1; i < argc; i++){
        mul *= atoi(argv[i]);
    }
    printf("Product = %d\n ",mul);
    return 0;
}
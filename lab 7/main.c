#include <stdio.h>
#include <stdlib.h>
#include <memtrack.h>

int main(){
    char *leak = malloc(500);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}

int maximo(int vec[], int n){
    int max;
    if(n == 0)
        return vec[n];
    else{
        max = maximo(vec, n - 1);
        if(v[n] > max)
            return v[n];
        else
            return max;
    }
}



#include <stdio.h>
#include <stdlib.h>
#define N 15

int main()
{
    int i;
    for(i = 1; i <= N; i++){
        if(i % 2 != 0)
            printf("%d\t", i);
    }
    return 0;
}

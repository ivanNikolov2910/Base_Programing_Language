#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("-1<1u -> %d\n", -1 < 1u);
    printf("-1u<1 -> %d\n", -1u < 1);
    printf("-1u<1u -> %d\n", -1u < 1u);
}
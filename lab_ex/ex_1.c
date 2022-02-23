#include <stdio.h>

int main()
{
    printf("    **      **      \n");
    printf("  ******  ******    \n");
    printf("******************  \n");
    printf(" ****************   \n");
    printf("   ************     \n");
    printf("     ********       \n");
    printf("        **          \n");

    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\t%d\n", a, b);
    // scanf("A:%d   B:%d", &a, &b);      wrooong
    printf("%d\t%d\n", a, b);

    return 0;
}
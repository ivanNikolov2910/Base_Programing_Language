#include <stdio.h>
#include <stdlib.h>

//int main()
//{
//    char c = 'x';
//
//    while (c!=EOF){   /* EOF = ^Z */
//        c = getchar();
//        putchar(c);
//    }
////    printf("Hello world!\n");
//    return 0;
//}

int main()
{
    char c;

    while ((c = getchar()) != EOF){   /* EOF = ^Z */
//        putchar(c);
        printf("%c",c);
    }
//    printf("Hello world!\n");
    return 0;
}

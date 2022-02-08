#include <stdio.h>
#include <stdlib.h>

//#define STEP 20

//int main()
//{
//    const int LOWER = 0;
//    int upper = 300;
//    float fahr;
//    int cel;
//
//    printf("Celsius to Fahrenheit Converter\n");
//    printf("Celsius\tFahrenheit\n");
///*    upper = 200;  */
//    for(cel=LOWER;cel<=upper;cel+=STEP){
//        fahr = cel*9./5 + 32;
//        printf("%d\t%g\n",cel,fahr);
//    }
//
////    printf("Hello world!\n");
//    return 0;
//}

int main()
{
    unsigned lower,upper,step;
    float fahr;
    int cel;

    printf("Input lower: ");
    scanf("%d",&lower);
    printf("Input upper: ");
    scanf("%d",&upper);
    printf("Input step: ");
    scanf("%d",&step);


    printf("Celsius to Fahrenheit Converter\n");
    printf("C\tF\n");

    for(cel=lower;cel<=upper;cel+=step){
        fahr = cel*9./5 + 32;
        printf("%d\t%.2f\n",cel,fahr);
    }

    return 0;
}

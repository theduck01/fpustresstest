#include <stdio.h>
#include <math.h>
# include <fenv.h>
void fputest1();



void main() {
    int choice;
    printf("C FPU TEST\n");
    printf("\n");
    printf("1. Start Test\n");
    printf("2. Exit\n");
    scanf("%d", &choice);

    if (choice == 1)
    {
        fputest1();
    }
    

}

void fputest1() {
    float ftest;
    float ftest2 = 1.000002;
    float ftest3 = 1.000002;
    for (int i = 0; i < 10000000; i++)
    {
        ftest = ftest2 * ftest3;
        ftest2 = ftest * ftest3;
        printf("%f\n", ftest);
        
    }
    
}
#include <stdio.h>
#include <math.h>
#include <fenv.h>
#include <pthread.h>
#include <string.h>

void *fputest1(void *arg);

int main(void) {
    int choice;

    printf("C FPU TEST\n");
    printf("\n");
    printf("1. Start Test\n");
    printf("2. Exit\n");
    scanf("%d", &choice);

    if (choice == 1)
    {
        pthread_t thread;
        int thread_create = pthread_create(&thread, NULL, fputest1, NULL);

        if (!thread_create)
        {
            pthread_join(thread, NULL);
            return 0;
        }

        fprintf("%s\n", strerror(thread_create), stderr);
        return 1;
    }
}

void *fputest1(void *arg) {
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

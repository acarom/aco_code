// gcc -o p -fopenmp pi_calculation.c -lm 
#include <stdio.h>
#include <omp.h>
#include <time.h>
//#define _USE_MATH_DEFINES
#include <math.h>

#define M_PI 3.14159265358979323846
void main() {
    // N of the sum to calculate Pi
    int N = 40;

    // Array with a number of threads?
    float array[N]; 
    
    //time.h for clocking the computation
    clock_t begin, end;
    begin = clock();

    //omp.h for clocking the computation
    double start = omp_get_wtime();

    double sqrt12 = sqrt(12);
    double m1over3 =  -1.0/3.0;
    long double sum = 0.0;

    for (int k=0; k < N; k++){
        long double divfun = (1.0/(1+2.0*k)); //10000
        sum += pow(m1over3,k)*divfun; 
        /*
        printf("Index =%i \n", k);
        printf("Sum =%Lf \n", sum);
        printf("## Pow = %f \n",pow(m1over3,k));
        printf("## Div = %f \n",(1.0/(1.0+2*k))); 
        */
    }

    // printf("Final Sum = %LE \n\n", (sqrt12*sum)-M_PI);
    printf("Final Sum = %Lf \n\n", (sqrt12*sum));
    double time2 = 1000.*(omp_get_wtime() - start); //ms
    double time = 1000.*(clock() - begin)/CLOCKS_PER_SEC; //ms
    
    printf(" Time CLOCK = %E ms \n",time2); 
    printf(" Time OMP = %E ms \n",time); 
    printf(" Time Diff = %E ms \n",time-time2); 
}
// gcc -o p -fopenmp par_b.c
#include <stdio.h>
#include <omp.h>
#include <time.h>

void main(){
  int N = 10;
  float STARTVALUE = 2.;
  float a[N];

  double time=0.;
  double time2=0.;

  clock_t begin, end;
  begin = clock();
  

  a[0] = STARTVALUE;

  double start;
  double send;
  start = omp_get_wtime();

#pragma omp parallel 
  {
    int ID = omp_get_thread_num();
    # pragma omp for
    for(int i=1; i<N; i++){
      float b = a[0];
      for(int j=0; j<i; j++){
	b = 2*b ;
      }
      a[i] = b;
      printf("Thread %d: a[%d]=%.1f \n",ID,i,a[i]);
    }
  } // end of parallel section
  

  printf("Work took %f seconds\n", end - start);

  printf("\n Results:\n");
  for(int i=0; i<N; i++){
    printf("a[%d]=%.1f \n",i,a[i]);
  }

  send = omp_get_wtime();
  end = clock();
  time = 1000.*(end - begin)/CLOCKS_PER_SEC; //s
  printf("\n Time with Clock() = %E ms \n",time);    
  time2 = 1000.*(send - start); //s
  printf("Time with omp_get_wtime() = %E ms\n", time2);
}
  

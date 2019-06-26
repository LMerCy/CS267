#include <omp.h>
#include <iostream>
#define NUM_THREADS 4
static long num_steps = 100000000;
double step;

int main ()
{ 
	int i,nthreads; 
	double pi, sum_pi[NUM_THREADS],tdata;
	step = 1.0/(double) num_steps;
	omp_set_num_threads(NUM_THREADS);
	tdata = omp_get_wtime();
#pragma omp parallel
{
	int i,id,nthrds;
	double x;
	id  = omp_get_thread_num();
	nthrds = omp_get_num_threads();
	//std::cout << "num threads:" << nthrds <<  std::endl;
	if(id == 0) nthreads = nthrds;
	for (i=id,sum_pi[id]=0;i< num_steps; i = i + nthrds){
		x = (i+0.5)*step;
		sum_pi[id] += 4.0/(1+x*x);
	}
}
	for(i = 0,pi=0;i<nthreads;i++) pi+=sum_pi[i]*step;	
	tdata = omp_get_wtime() - tdata;
	std::cout << "pi="<< pi << "in "<<tdata<<"secs"<<std::endl;
	return 0;
}

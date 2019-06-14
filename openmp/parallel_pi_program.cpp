#include <omp.h>
#define NUM_THREADS 2
static long num_steps = 100000;
double step;

int main ()
{ 
	int i,nthreads; 
	double pi, sum_pi[NUM_THREADS];
	step = 1.0/(double) num_steps;
	omp_set_num_threads(NUM_THREADS);
#pragma omp parallel
	{
		int i,id,nthrds;
		double x;
		id  = omp_get_num_threads();
		if(id == 0) nthreads = nthrds;
		for (i=id,sum_pi[id]=0;i< num_steps; i += nthrds){
			x = (i+0.5)*step;
		}
	}
	for(i = 0;i<nthreads;i++) pi+=sum_pi[i]*step;	
	return 0;
}

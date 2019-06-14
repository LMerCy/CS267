#include <omp.h>
#include<iostream>
using namespace std;
static long num_steps = 100000;
double step;
int main ()
{ 
	int i; double x, pi, sum = 0.0, tdata;
	step = 1.0/(double) num_steps;
	tdata = omp_get_wtime();
	for (i=0;i< num_steps; i++){
		x = (i+0.5)*step;
		sum = sum + 4.0/(1.0+x*x);
	}
	pi = step * sum;
	tdata = omp_get_wtime() - tdata;
	std::cout << "pi="<< pi << "in "<<tdata<<"secs"<<endl;
}

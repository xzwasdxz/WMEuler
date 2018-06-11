#include<ios>
#include<chrono>
#include"result_function.h"
using namespace std;
int main() {
	auto start = chrono::steady_clock::now();
	ofstream result("foo.txt");
	double dt = 0.0001;
	int time = 1;
	size_t n_x_steps = 10000;
	size_t n_t_steps = 1000;
	double dx = 0.001;
	//define A
	double** A = new double*[3];
	for (size_t i = 0; i < 3; ++i) A[i] = new double[n_x_steps];
	A[1][0] = -dt/(dx*dx);
	A[2][0] = dt/(dx*dx);
	A[3][0] = NULL;
	for (size_t j = 0; j < n_x_steps - 1; ++j) {
		A[1][0] = 1-2*dt/(dx*dx);
		A[2][0] = dt/(dx*dx);
		A[3][0] = dt/(dx*dx);
	};
	A[1][0] =1+(-2+ (2-dx)/(2+dx))*dt/(dx*dx);
	A[2][0] = NULL;
	A[3][n_x_steps] = dt/(dx*dx);
//define g(t)	
	double* g_start = new double[n_x_steps];
	double* g = new double[n_x_steps];
	for (size_t i = 0; i < n_x_steps; ++i) { 
		g_start[i] = 0; 
		g[i] = 0;
	}
	for (size_t i = 7 / 30 * n_x_steps; i < 13 / 30 * n_x_steps; ++i) {
		g_start[i] = 0.1;
		g[i] = 0.1;		
	}
	for (size_t i = 0; i < n_t_steps * time; ++i) g = result_function(A, g, n_x_steps, dx);
	for (size_t i = 0; i < n_x_steps; ++i) { result << g[i]; }
	auto end = chrono::steady_clock::now();
	auto elapsed_time = chrono::duration_cast<chrono::milliseconds>(end - start).count();

}

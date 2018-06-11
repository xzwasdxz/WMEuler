#include<fstream>
#include<chrono>
#include"Multiplication.h"
int main() {
	ofstream result("foo.txt");
	double dt = 0.0001;
	int time = 1;
	size_t n_x_steps = 10000;
	size_t n_t_steps = 10000;
	double dx = 0.0001;
	//define A
	double** A = new double*[3];
	for (size_t i = 0; i < 3; ++i) A[i] = new double[n_x_steps];
	A[1][0] = -dt;
	A[2][0] = dt;
	A[3][0] = NULL;
	for (size_t j = 0; j < n_x_steps - 1; ++j) {
		A[1][0] = 1-2*dt;
		A[2][0] = dt;
		A[3][0] = dt;
	};
	A[1][0] =1+(-2+ (2-dx)/(2+dx))*dt;
	A[2][0] = NULL;
	A[3][n_x_steps] = dt;
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
	for (size_t i = 0; i < n_t_steps * time; ++i) g = three_tape_matrix_vector_multiplication(A, g, n_x_steps);
	
	for (size_t i = 0; i < n_x_steps; ++i) { result << g[i]; }

}

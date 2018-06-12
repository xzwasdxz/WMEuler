#include<fstream>
#include<iostream>
#include<chrono>
#include"result_function.h"
using namespace std;
int main() {
	auto start = chrono::steady_clock::now();
	size_t n_x_steps = 100;
	size_t n_t_steps = 1000;
	double dx = 1/n_x_steps;
	double dt = 1/n_t_steps;
//define A
	double** A = new double*[3];
	for (size_t i = 0; i < 3; ++i) A[i] = new double[n_x_steps];
	A[1][0] = 1 - dt / (dx * dx);
	A[2][0] = dt / (dx * dx);
	for (size_t j = 1; j < n_x_steps - 1; ++j) {
		A[1][j] = 1 - 2 * dt / (dx * dx);
		A[2][j] = dt / (dx * dx);
		A[0][j] = dt / (dx * dx);
	};
	A[1][n_x_steps-1] =1 + (-2 + (2 - dx) / (2 + dx)) * dt / (dx * dx);
//define g(t)	
	double* g_start = new double[n_x_steps];
	double* g = new double[n_x_steps];
	for (size_t i = 0; i < n_x_steps; ++i) { 
		g_start[i] = 0; 
		g[i] = 0;
	} 
	for (size_t i = 7. / 30 * n_x_steps; i < 13. / 30 * n_x_steps; ++i) {
		g_start[i] = 0.1;
		g[i] = 0.1;		
	}
	for (size_t i = 0; i < size_t(n_t_steps); ++i) g = result_function(A, g, n_x_steps, dx);
	ofstream result("foo.txt");
	for (size_t i = 0; i < n_x_steps; ++i) result << g[i] << endl; 
	for (size_t i = 0; i < 3; ++i)delete[] A[i];
	delete[] A, g, g_start;
	auto end = chrono::steady_clock::now();
	auto elapsed_time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
	std::cout << elapsed_time << " milliseconds" << endl;
	std::cin >> dx;
}

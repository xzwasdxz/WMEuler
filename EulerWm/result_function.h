double *result_function(double **matrix, double *vector, size_t N, double dx) {
	double *out_vector = new double[N];
	for (size_t i = 0; i < N; ++i) {
		out_vector[i] = 0;
	}
	out_vector[0] += matrix[1][0] * vector[0] + matrix[2][0] * vector[0];
	out_vector[N-1] += matrix[0][N-2] * vector[N-1] + matrix[1][N-1] * vector[N-1];
	for(size_t j = 1; j < N-1; ++j){
		for (size_t i = 0; i < 3; ++i) {
			out_vector[j] += matrix[i][j] * vector[i+j-1];
		}
	}
	out_vector[0] -= 1 / dx;
	return out_vector;
}
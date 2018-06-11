double *result_function(double **matrix, double *vector, size_t N, double dx) {
	double *out_vector = new double[N];
	for (size_t i = 0; i < N; ++i) {
		out_vector[i] = 0;
	}
	for (size_t i = 0; i < 3; ++i) {
		for (size_t j = 0; j < N; ++j) {
			out_vector[i] += matrix[i][j] * vector[j];
		}
	}
	out_vector[0] -= 1 / dx;
	return out_vector;
}
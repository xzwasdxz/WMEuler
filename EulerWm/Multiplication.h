double** matrix_matrix_multiplication(double** in_1, double** in_2, size_t N) {
	double** out_matrix = new double*[N];
	for (size_t i = 0; i < N; ++i) out_matrix[i] = new double[N];
	for (size_t i = 0; i < N; ++i) for (size_t j = 0; j < N; ++j) out_matrix[i][j] = 0;
	for (size_t i = 0; i < N; ++i) {
		for (size_t j = 0; j < N; ++j) {
			for (size_t k = 0; k < N; ++k) {
				out_matrix[i][j] += in_1[i][k] * in_2[k][j];
			}
		}
	}
	return out_matrix;
}

double *matrix_vector_multiplication(double **matrix, double *vector, size_t N) {
	double *out_vector = new double[N];
	for (size_t i = 0; i < N; ++i) {
		out_vector[i] = 0;
	}
	for (size_t i = 0; i < N; ++i) {
		for (size_t j = 0; j < N; ++j) {
			out_vector[i] += matrix[i][j] * vector[j];
		}
	}
	return out_vector;
}
double *three_tape_matrix_vector_multiplication(double **matrix, double *vector, size_t N) {
	double *out_vector = new double[N];
	for (size_t i = 0; i < N; ++i) {
		out_vector[i] = 0;
	}
	for (size_t i = 0; i < 3; ++i) {
		for (size_t j = 0; j < N; ++j) {
			out_vector[i] += matrix[i][j] * vector[j];
		}
	}
	return out_vector;
}
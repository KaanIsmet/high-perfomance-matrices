#include <iostream>
#include <cstdlib>
#include <random>
#include <chrono>


#define ROWS 10000
#define COLS 10000

void allocateMatrix(int*** matrixPtr);
void deallocateMatrix(int*** matrixPtr);
void populateMatrix(int*** matrixPtr);
void populateEmptyMatrix(int*** matrixPtr);
void addMatrices(int** matrix_a, int** matrix_b, int*** matrix_result);
void printMatrix(int** matrix_result);


int main(int argc, char** argv) {
	int** matrix_a;
	int** matrix_b;
	int** matrix_result;
	auto start = std::chrono::high_resolution_clock::now();


	allocateMatrix(&matrix_result);	
	allocateMatrix(&matrix_a);
	allocateMatrix(&matrix_b);

	populateMatrix(&matrix_a);
	populateMatrix(&matrix_b);

	populateEmptyMatrix(&matrix_result);

	addMatrices(matrix_a, matrix_b, &matrix_result);

	printMatrix(matrix_result);
	
	deallocateMatrix(&matrix_a);
	deallocateMatrix(&matrix_b);
	deallocateMatrix(&matrix_result);
	
	//calculting time in seconds
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;
	auto seconds = std::chrono::duration_cast<std::chrono::seconds>(end - start);
	std::cout << "Time (in seconds): " << seconds.count() << std::endl;
	return 0;
}




void allocateMatrix(int*** matrixPtr) {
	*matrixPtr = (int**) malloc(ROWS * sizeof(int*));

	(*matrixPtr)[0] = (int*) malloc(ROWS * COLS * sizeof(int));



	for (int i = 1; i < ROWS; i++) {
		(*matrixPtr)[i] = (*matrixPtr)[0] + i + COLS; 
	}
}

void deallocateMatrix(int*** matrixPtr) {
	free((*matrixPtr)[0]);
	free(*matrixPtr);
}

void populateMatrix(int*** matrixPtr) {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(0, 10);
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < ROWS; j++) {
			(*matrixPtr)[i][j] = dist(mt);
		}
	}
}

void populateEmptyMatrix(int*** matrixPtr) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			(*matrixPtr)[i][j] = 0;
		}
	}
}

void addMatrices(int** matrix_a, int** matrix_b, int*** matrix_result) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			(*matrix_result)[i][j] = matrix_a[i][j] + matrix_b[i][j];
		}
	}
}

void printMatrix(int** matrix) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

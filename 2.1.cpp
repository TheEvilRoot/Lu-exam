#include "stdio.h"
#include "stdlib.h"

int **initializationOfMatrix(int, int);
void inputMatrix(int**, int, int);
void outputMatrix(int**, int, int);
int** matrixMultiplication(int**, int**, int**, int, int, int);

int main(){
	int rows1, rows2, columns1, columns2;
	do{
		scanf("%d", &rows1);
		scanf("%d", &columns1);
		scanf("%d", &rows2);
		scanf("%d", &columns2);
	} while (columns1 != rows2);

	int **matrix1 = initializationOfMatrix(rows1, columns2);
	int **matrix2 = initializationOfMatrix(rows2, columns2);
	int **matrix3 = initializationOfMatrix(rows1, columns2);

	inputMatrix(matrix1, rows1, columns1);
	inputMatrix(matrix2, rows2, columns2);

	outputMatrix(matrix1, rows1, columns1);
	outputMatrix(matrix2, rows2, columns2);

	matrix3=matrixMultiplication(matrix1, matrix2, matrix3, rows1, columns2, columns1);

	outputMatrix(matrix3, rows1, columns2);

	return 0;
}

int** initializationOfMatrix(int columns, int rows){
	int**matrix = (int**)malloc(sizeof(int*)*columns);
	for (int i = 0; i < columns; i++){
		matrix[i] = (int*)malloc(sizeof(int)*rows);
	}
	return matrix;
}

void inputMatrix(int**matrix, int rows, int columns){
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < columns; j++){
			matrix[i][j] = rand() % 10 + 1;
		}
	}
}

void outputMatrix(int** matrix, int rows, int columns){
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < columns; j++){
			printf("%4d", matrix[i][j]);
		}
		puts("");
	}
	puts("");
}

int** matrixMultiplication(int** matrix1, int**matrix2,int** matrix3, int rows1 , int columns2,int columns1){
	for (int i = 0; i < rows1; i++){
		for (int j = 0; j < columns2; j++){
			matrix3[i][j] = 0;
			for (int k = 0; k < columns1; k++){
				matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
	return matrix3;
}
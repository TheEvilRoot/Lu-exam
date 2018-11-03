//Transpose matrix relative to the secondary diagonal with the help cycle do - while, not use additional matrixes or arrays
#include "stdio.h"
#include "stdlib.h"
#include "ctime"

int** initializationOfMatrix(int);
void inputMatrix(int**,int,int);
void outputMatrix(int**,int,int);
void transposingMatrix(int**,int,int);

int main(){
	srand(time(NULL));
	int raw, columns, size;
	while(! ( (scanf("%d",&raw)) && (scanf("%d",&columns)) ) ){
		printf("Wrong value of raw or column,please try again\n");
		fflush(stdin);
	}
	if (raw >= columns){
		size = raw;
	}
	else{
		size = columns;
	}
	system("cls");
	int **matrix = initializationOfMatrix(size);
	inputMatrix(matrix,raw,columns);
	outputMatrix(matrix, raw, columns);
	transposingMatrix(matrix, raw, columns);
	outputMatrix(matrix, raw, columns);
	return 0;
}
int** initializationOfMatrix(int size){
	int **matrix = (int**)malloc(sizeof(int*)*size);
	for (int i = 0; i<size; i++){
		matrix[i] = (int*)malloc(sizeof(int)*size);
	}
	return matrix;
}
void inputMatrix(int**matrix,int raw,int columns){
	for (int i = 0; i < raw; i++){
		for (int j = 0; j < columns; j++){
			matrix[i][j]=rand()%100+1;
		}
	}
}
void outputMatrix(int**matrix, int raw, int columns){
	puts("");
	for (int i = 0; i < raw; i++){
		for (int j = 0; j < columns; j++){
			printf("%4d", matrix[i][j]);
		}
		puts("");
	}
	puts("");
}
void transposingMatrix(int**matrix, int raw, int columns){
	int temp;
	for (int i =0; i < raw; i++){
		for (int j = 0; j < columns-i; j++){
			temp = matrix[i][j];
			matrix[i][j] = matrix[raw-i-1][columns-j-1];
			matrix[raw-i-1][columns-j-1] = temp;
		}
	}
}
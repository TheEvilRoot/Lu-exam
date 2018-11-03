//Transpose matrix relative to the secondary diagonal with the help cycle do - while, not use additional matrixes or arrays
#include <stdio.h>
#include <stdlib.h>

int main(){
	int raw, columns;
	while(!scanf("%d",&raw) || !scanf("%d",&columns)){
		printf("Wrong value of raw or column,please try again\n");
		fflush(stdin);
		fseek(stdin, 0, SEEK_END);
	}

	int size = columns;
	if (raw > columns){
		size = raw;
	}

	int **matrix = (int**)malloc(sizeof(int*)*size);
	for (int i = 0; i<size; i++){
		matrix[i] = (int*)malloc(sizeof(int)*size);
	}

	for (int i = 0; i < raw; i++){
		for (int j = 0; j < columns; j++){
			matrix[i][j] = (i+1) * 10 + 1 + j;
		}
	}

	printf("\n");
	for (int i = 0; i < raw; i++){
		for (int j = 0; j < columns; j++){
			printf("%3d", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	// for (int i =0; i < raw; i++){
	// 	for (int j = 0; j < columns-i; j++){
	// 		int temp = matrix[size - j - 1][size - i - 1];
	// 		matrix[size - j - 1][size - i - 1] = matrix[i][j];
	// 		matrix[i][j] = temp;
	// 	}
	// }

	int r = 0, c = 0;
	do {
		c = 0;
		do {
			int temp = matrix[size - c - 1][size - r - 1];
			matrix[size - c - 1][size - r - 1] = matrix[r][c];
			matrix[r][c] = temp;
			c++;
		} while(c < columns - r);
		r++;
	} while (r < raw);

	printf("\n");
	for (int i = size-columns; i < size; i++){
		for (int j = size-raw; j < size; j++){
			printf("%3d", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}
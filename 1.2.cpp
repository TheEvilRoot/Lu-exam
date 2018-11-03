//in main enter string,consisting of integer numbers separated by an arbitrary number of spaces.
//In function transform string in array of short integer numbers.Output array in main.
#include "stdio.h"
#include "stdlib.h"
#include "cmath"
int lengthOfString(char*);
void transformOfString(int*, char*, int);

int main(){
	int size = 1000;
	char* string = (char*)malloc(size);
	gets(string);
	fflush(stdin);
	int length = lengthOfString(string);
	int*array = (int*)calloc(sizeof(int),length);
	int counter = 0, numberOfElement = 0;
	for (int i = 0; i < length; i++){
		if ((string[i] >= '0') && (string[i] <= '9')){
			array[numberOfElement] += (string[i] - '0')*pow(10, counter);
			counter++;
		}
		else{
			numberOfElement++;
			counter = 0;
		}
	}
	for (int i = 0; i < length; i++){
		printf("%3d", *(array + i));
	}
	puts("");
	return 0;
}
int lengthOfString(char*string){
	int i = 0;
	while (string[i] != '\0'){
		i++;
	}
	return i;
}
//in main enter string,consisting of integer numbers separated by an arbitrary number of spaces.
//In function transform string in array of short integer numbers.Output array in main.
#include "stdio.h"
#include "stdlib.h"
int countOfNumbers(char*);
int stringLength(char*);
void transformOfString(int*, char*, int);
int pow(int, int);

int main(){
	int size = 1000;
	char* string = (char*)malloc(size);
	gets(string);
	fflush(stdin);
	int length = countOfNumbers(string);
	int strLength = stringLength(string);
	int*array = (int*)calloc(sizeof(int),length);
	int counter = 0, numberOfElement = 0, isProcessing = 0;
	for (int i = strLength - 1; i >= 0; i--){
		if ((string[i] >= '0') && (string[i] <= '9')){
			isProcessing = 1;
			array[numberOfElement] += (string[i] - '0')*pow(10, counter);
			counter++;
		}
		else if(isProcessing){
			numberOfElement++;
			counter = 0;
			isProcessing = 0;
		}
	}
	for (int i = length - 1; i >= 0; i--){
		printf("%d\n", *(array + i));
	}
	puts("");
	return 0;
}
int countOfNumbers(char*string){
	int count = 0;
	for (int i = 0; string[i] != '\0'; i++) {
		if (string[i] >= '0' && string[i] <= '9') {
			for (; string[i] >= '0' && string[i] <= '9'; i++);
			count++;
		}
	}
	return count;
}

int stringLength(char *string) {
	int len = 0;
	for (; string[len] != '\0'; ++len);
	return len;
}

int pow(int base, int power) {
	int ret = 1;
	for (int i = 0; i < power; i++) {
		ret *= base;
	}
	return ret;
}
#include <stdio.h>
#include <stdlib.h>

int main(){

  int count = 0;

  do {
    printf("Enter number of strings: ");
    fflush(stdin);
    fseek(stdin, 0, SEEK_END);
  } while (!scanf("%d", &count));

  char **strings = (char**) malloc(count * sizeof(char*));

  for (int i = 0; i < count; i++) {
    strings[i] = (char*) malloc(64 * sizeof(char));
    fflush(stdin);
    fseek(stdin, 0, SEEK_END);
    gets(strings[i]);
  }

  for (int i = 0; i < count; i++) {
    printf("'%s'\n", strings[i]);
  }

  int maxLength = 0;

  int sPos = 0;
  int wPos = 0;

  for (int i = 0; i < count; i++) {
    int sLength = 0;
    for (; strings[i][sLength] != '\0'; ++sLength);
    for (int t = sLength - 1; t >= 0; t--) {
      if ((strings[i][t] >= 'a' && strings[i][t] <= 'z') || (strings[i][t] >= 'A' && strings[i][t] <= 'Z')) {
        int wLength = 0;
        for (; (strings[i][t + wLength] >= 'a' && strings[i][t + wLength] <= 'z') || (strings[i][t + wLength] >= 'A' && strings[i][t + wLength] <= 'Z'); ++wLength);
        if (wLength > maxLength) {
          sPos = i;
          wPos = t;
          maxLength = wLength;
        }
      }
    }
  }

  printf("Max word with size %d on [%d][%d] to %d\n", maxLength, sPos, wPos, wPos + maxLength);
  for (int i = 0; i < maxLength; i++) {
    printf("%c", strings[sPos][i + wPos]);
  }
  printf("\n");

  return 0;
}
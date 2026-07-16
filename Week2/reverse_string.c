#include <stdio.h>

int str_len(char *str) {
  int len = 0;

  while (str[len] != '\0') {
    len++;
  }

  return len;
}

void reverse_string(char *str) {
  int left = 0;
  int right = str_len(str) - 1;

  while (left < right) {
    char temp = str[left];
    str[left] = str[right];
    str[right] = temp;
    left++;
    right--;
  }
}

int main() {
  char str[] = "Data Structures";
  reverse_string(str);
  printf("%s \n", str);
}
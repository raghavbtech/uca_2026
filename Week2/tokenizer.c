#include <stdio.h>
#include <string.h>

int main() {
  char language[] = "C,C++,Java,Python,Rust";
  char *token = strtok(language, ",");

  while (token != NULL) {
    printf("%s \n", token);
    token = strtok(NULL, ",");
  }
  return 0;
}
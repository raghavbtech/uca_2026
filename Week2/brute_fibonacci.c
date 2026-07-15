#include <stdio.h>

int evenFib(int n) {
  int a = 1, b = 1;
  int sum = 0;
  while (b <= n) {
    if (b % 2 == 0) {
      sum += b;
    }
    int next = a + b;
    a = b;
    b = next;
  }
  return sum;
}

int main() {
  int n;

  scanf("%d", &n);

  printf("%d \n", evenFib(n));

  return 0;
}
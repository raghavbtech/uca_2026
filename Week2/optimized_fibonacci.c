#include <stdio.h>


int evenFib(int n) {
  int sum = 0;
  int e1 = 2;
  int e2 = 8;

  while (e1 <= n) {

    sum += e1;

    int next = 4 * e2 + e1;

    e1 = e2;
    e2 = next;
  }
  return sum;
}

int main() {
  int n;
  scanf("%d", &n);

  printf("%d \n ", evenFib(n));
}
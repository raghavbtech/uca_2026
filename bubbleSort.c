#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void generate_numbers(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 100000;
  }
}

int main() {
  srand(time(NULL));

  int size1 = 40000;
  int size2 = 80000;

  int *arr1 = (int *)malloc(size1 * sizeof(int));
  int *arr2 = (int *)malloc(size2 * sizeof(int));
  generate_numbers(arr1, size1);
  clock_t start1 = clock();
  bubble_sort(arr1, size1);
  clock_t end1 = clock();

  double time1 = ((double)(end1 - start1)) / CLOCKS_PER_SEC;

  generate_numbers(arr2, size2);
  clock_t start2 = clock();
  bubble_sort(arr2, size2);
  clock_t end2 = clock();

  double time2 = ((double)(end2 - start2)) / CLOCKS_PER_SEC;

  printf(" \n %f ", time2 / time1);
  return 0;
}

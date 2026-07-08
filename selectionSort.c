#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    int min = i;

    for (int j = i + 1; j < size; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }

    if (min != i) {
      int temp = arr[i];
      arr[i] = arr[min];
      arr[min] = temp;
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
  selection_sort(arr1, size1);
  clock_t end1 = clock();

  double time1 = ((double)(end1 - start1)) / CLOCKS_PER_SEC;

  generate_numbers(arr2, size2);
  clock_t start2 = clock();
  selection_sort(arr2, size2);
  clock_t end2 = clock();

  double time2 = ((double)(end2 - start2)) / CLOCKS_PER_SEC;

  printf("\nTime ratio (80000/40000): %f\n", time2 / time1);

  free(arr1);
  free(arr2);

  return 0;
}

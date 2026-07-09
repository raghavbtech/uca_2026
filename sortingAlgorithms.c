#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Bubble Sort
void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }

    arr[j + 1] = key;
  }
}

// Selection Sort
void selectionSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int min = i;

    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min])
        min = j;
    }

    int temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
  }
}

// Quick Sort
int partition(int arr[], int low, int high) {
  int pivot = arr[high];

  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) {
      i++;

      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }

  int temp = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = temp;

  return i + 1;
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);

    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

// Merge Sort
void merge(int arr[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = 0;

    int temp[right - left + 1];

    while(i <= mid && j <= right)
    {
        if(arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while(i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while(j <= right)
    {
        temp[k++] = arr[j++];
    }

    for(i = 0; i < k; i++)
    {
        arr[left + i] = temp[i];
    }
}

void mergeSort(int arr[], int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}
// Heap Sort
void heapify(int arr[], int n, int i) {
  int largest = i;

  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest])
    largest = left;

  if (right < n && arr[right] > arr[largest])
    largest = right;

  if (largest != i) {
    int temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;

    heapify(arr, n, largest);
  }
}

void heapSort(int arr[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  for (int i = n - 1; i > 0; i--) {
    int temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;

    heapify(arr, i, 0);
  }
}

// Generate Arrays
void generateRandom(int arr[], int n) {
  for (int i = 0; i < n; i++)
    arr[i] = rand() % 100000;
}

void generateAscending(int arr[], int n) {
  for (int i = 0; i < n; i++)
    arr[i] = i;
}

void generateDescending(int arr[], int n) {
  for (int i = 0; i < n; i++)
    arr[i] = n - i;
}

// Measure Time
double measureTime(int arr[], int n) {
  int *temp = (int *)malloc(n * sizeof(int));

  memcpy(temp, arr, n * sizeof(int));

  struct timespec start, end;

  clock_gettime(CLOCK_MONOTONIC, &start);

  heapSort(temp, n);

  clock_gettime(CLOCK_MONOTONIC, &end);

  free(temp);

  double timeTaken = (end.tv_sec - start.tv_sec) * 1000.0 +
                     (end.tv_nsec - start.tv_nsec) / 1000000.0;

  return timeTaken;
}

// Main
int main() {
  srand(time(NULL));

  int sizes[] = {8000, 12000, 16000, 20000, 24000, 28000, 32000, 36000};

  printf("Sorting Time Analysis\n");

  printf("%-8s %-15s %-15s %-15s\n", "Size", "Random", "Ascending",
         "Descending");

  for (int i = 0; i < 8; i++) {
    int n = sizes[i];

    int *arr = (int *)malloc(n * sizeof(int));

    generateRandom(arr, n);
    double randomTime = measureTime(arr, n);

    generateAscending(arr, n);
    double ascendingTime = measureTime(arr, n);

    generateDescending(arr, n);
    double descendingTime = measureTime(arr, n);

    printf("%-8d %.9lf %.9lf %.9lf\n", n, randomTime, ascendingTime,
           descendingTime);
    free(arr);
  }

  return 0;
}

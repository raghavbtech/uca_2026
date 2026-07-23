#include <stdio.h>

int count = 0;

void merge(int arr[], int L, int mid, int R, int temp[]) {
  int j = mid + 1;

  for (int i = L; i <= mid; i++) {
    while (j <= R && (long long)arr[i] > 2LL * arr[j]) {
      j++;
    }
    count += (j - (mid + 1));
  }

  int i = L;
  j = mid + 1;
  int k = L;

  while (i <= mid && j <= R) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
    }
  }

  while (i <= mid) {
    temp[k++] = arr[i++];
  }
  while (j <= R) {
    temp[k++] = arr[j++];
  }

  for (int i = L; i <= R; i++) {
    arr[i] = temp[i];
  }
}
void mergeSort(int arr[], int L, int R, int temp[]) {
  if (L >= R)
    return;

  int mid = L + (R - L) / 2;

  mergeSort(arr, L, mid, temp);
  mergeSort(arr, mid + 1, R, temp);
  merge(arr, L, mid, R, temp);
}

int main() {
  int n;
  scanf("%d", &n);

  int arr[n], temp[n];

  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  mergeSort(arr, 0, n - 1, temp);
  printf("%d", count);
}

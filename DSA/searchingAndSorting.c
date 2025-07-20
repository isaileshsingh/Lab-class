#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void bubbleSort(int arr[], int n) {
    printf("Bubble Sort: Repeatedly swaps adjacent elements if they are in wrong order.\n");
    printf("Time: O(n^2), Space: O(1)\n");
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int t = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = t;
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    printf("Insertion Sort: Builds the sorted array one item at a time by shifting elements.\n");
    printf("Time: O(n^2), Space: O(1)\n");
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[100], R[100];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void mergeSortWrapper(int arr[], int n) {
    printf("Merge Sort: Divides array into halves, sorts and merges them.\n");
    printf("Time: O(n log n), Space: O(n)\n");
    mergeSort(arr, 0, n - 1);
}

void selectionSort(int arr[], int n) {
    printf("Selection Sort: Repeatedly selects the minimum element and places it in order.\n");
    printf("Time: O(n^2), Space: O(1)\n");
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) min = j;
        }
        int t = arr[i]; arr[i] = arr[min]; arr[min] = t;
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++; int t = arr[i]; arr[i] = arr[j]; arr[j] = t;
        }
    }
    int t = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = t;
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

void quickSortWrapper(int arr[], int n) {
    printf("Quick Sort: Picks a pivot and partitions array around it.\n");
    printf("Time: O(n log n), Space: O(log n)\n");
    quickSort(arr, 0, n - 1);
}

int main() {
    int choice, arr[100], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("\n1. Bubble Sort\n2. Insertion Sort\n3. Merge Sort\n4. Selection Sort\n5. Quick Sort\n");
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            bubbleSort(arr, n);
            break;
        case 2:
            insertionSort(arr, n);
            break;
        case 3:
            mergeSortWrapper(arr, n);
            break;
        case 4:
            selectionSort(arr, n);
            break;
        case 5:
            quickSortWrapper(arr, n);
            break;
        default:
            printf("Invalid choice\n");
            return 0;
    }

    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}

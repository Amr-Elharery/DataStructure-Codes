// Author: Amr Elharery
// Merge sort Not COMPLETE
#include <iostream>
using namespace std;

void print(int arr[], int size) {
    cout << "[";
    for (int i = 0; i < size - 1; ++i) {
        cout << arr[i] << ", ";
    }
    cout << arr[size - 1];
    cout << "]\n";
}

void merge(int *arr, int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int *leftArr = new int[leftSize];
    int *rightArr = new int[rightSize];

    for (int i = 0; i < leftSize; ++i) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < rightSize; ++i) {
        rightArr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < rightSize) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(int *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int nums[] = {4, 7, 6, 3, 8};
    int size = sizeof(nums) / sizeof(nums[0]);

    cout << "Before sorting: \n";
    print(nums, size);
    cout << "-----------" << endl;
    mergeSort(nums, 0, size - 1);
    cout << "After sorting: \n";
    print(nums, size);

    return 0;
}

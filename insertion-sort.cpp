//Author Amr Elharery
//Insertion sort
#include <iostream>
#include <algorithm>
using namespace std;

// O(n^2) Worst case
// O(n) Best case
void sort(int arr[], int size){
    for (int i = 0; i < size-1; ++i) {
        for (int j = i; j >= 0 && arr[j+1] < arr[j]; --j) {
            swap(arr[j], arr[j+1]);
        }
    }
}

void print(int *arr, int size){
    cout << "[";
    for (int i = 0; i < size-1; ++i) {
        cout << arr[i] << ", ";
    }
    cout << arr[size-1];
    cout << "]\n";
}

int main(){
    int nums[] = {4,7,6,3,8};
    int size = sizeof(nums) / sizeof(nums[0]);

    cout << "Before sorting: \n";
    print(nums, size);
    cout << "-----------" << endl;
    sort(nums, size);
    cout << "After sorting: \n";
    print(nums, size);

    return 0;
}

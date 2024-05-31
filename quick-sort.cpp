#include <iostream>
using namespace std;

void sort(int arr[], int left, int right){
    int i=left, j=right,tmp, pivot=arr[left];

//    Partition
    while(i<=j){
        while(arr[i] < pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i<=j){
            tmp =  arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }

//    Recursion
    if(left < j){
        sort(arr, left, j);
    }
    if(i < right){
        sort(arr, i, right);
    }
}

void print(int arr[], int size){
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
    sort(nums, 0, size-1);
    cout << "After sorting: \n";
    print(nums, size);

    return 0;
}
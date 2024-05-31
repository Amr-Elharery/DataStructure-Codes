//Author Amr Elharery
//Selection sort
#include <iostream>
using namespace std;

// O(n^2)
void sort(int arr[], int size){
    int minIdx, tmp;
    for (int i = 0; i < size - 1 ; ++i) {
        minIdx = i;
        for (int j = i+1; j < size; ++j) {
            if(arr[j] < arr[minIdx]){
                minIdx = j;
            }
        }
        if(i != minIdx){
            tmp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = tmp;
        }
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
    sort(nums, size);
    cout << "After sorting: \n";
    print(nums, size);

    return 0;
}
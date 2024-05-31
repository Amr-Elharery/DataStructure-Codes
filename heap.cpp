//
// Created by AMR on 23/05/2024.
//
#include <iostream>
#include <vector>

using namespace std;

class Heap {
private:
    bool isMinHeap;
    vector<int> heap;

public:
    Heap(bool minHeap = true) : isMinHeap(minHeap) {}

    int parent(int index) {
        return index == 0 ? -1 : (index - 1) / 2;
    }

    int left(int index) {
        return (index * 2) + 1;
    }

    int right(int index) {
        return (index * 2) + 2;
    }

    bool compare(int n1, int n2) {
        if (isMinHeap) {
            return n1 < n2;
        }
        return n1 > n2;
    }

    unsigned long long size() {
        return heap.size();
    }

    void heapifyUp(int index) {
        if (index && compare(heap[index], heap[parent(index)])) {
            swap(heap[index], heap[parent(index)]);
            heapifyUp(parent(index));
        }
    }

    void heapifyDown(int index) {
        int leftChild = left(index);
        int rightChild = right(index);
        int selected = index;

        if (leftChild < size() && compare(heap[leftChild], heap[index]))
            selected = leftChild;

        if (rightChild < size() && compare(heap[rightChild], heap[selected]))
            selected = rightChild;

        if (selected != index) {
            swap(heap[index], heap[selected]);
            heapifyDown(selected);
        }
    }

    void add(int value) {
        heap.push_back(value);
        heapifyUp(size() - 1);
    }

    void remove() {
        if (size()) {
            heap[0] = heap.back();
            heap.pop_back();
            heapifyDown(0);
        }
    }

    void display() const {
        for (int value : heap) {
            cout << value << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap minHeap(true); // Min-Heap
    minHeap.add(10);
    minHeap.add(5);
    minHeap.add(20);
    minHeap.add(1);

    cout << "Min-Heap elements:" << endl;
    minHeap.display();

    minHeap.remove();
    cout << "Min-Heap after removing the root:" << endl;
    minHeap.display();

    Heap maxHeap(false); // Max-Heap
    maxHeap.add(10);
    maxHeap.add(5);
    maxHeap.add(20);
    maxHeap.add(1);

    cout << "Max-Heap elements:" << endl;
    maxHeap.display();

    maxHeap.remove();
    cout << "Max-Heap after removing the root:" << endl;
    maxHeap.display();

    return 0;
}

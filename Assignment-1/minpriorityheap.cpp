#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    int Parent(int i) { return (i - 1) / 2; }
    int Left(int i) { return 2 * i + 1; }
    int Right(int i) { return 2 * i + 2; }

    void MinHeapify(int i) {
        int l = Left(i);
        int r = Right(i);
        int smallest = i;

        if (l < heap.size() && heap[l] < heap[smallest])
            smallest = l;
        if (r < heap.size() && heap[r] < heap[smallest])
            smallest = r;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            MinHeapify(smallest);
        }
    }

public:
    MinHeap() {}

    int HeapMinimum() {
        return heap.empty() ? INT_MIN : heap[0];
    }

    int HeapExtractMin() {
        if (heap.empty()) return INT_MIN;

        int min = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        MinHeapify(0);

        return min;
    }

    void HeapDecreaseKey(int i, int key) {
        if (key > heap[i]) {
            cout << "New key is greater than the current key." << endl;
            return;
        }

        heap[i] = key;
        while (i > 0 && heap[Parent(i)] > heap[i]) {
            swap(heap[i], heap[Parent(i)]);
            i = Parent(i);
        }
    }

    void MinHeapInsert(int key) {
        heap.push_back(INT_MAX);
        HeapDecreaseKey(heap.size() - 1, key);
    }

    void PrintHeap() {
        for (int i : heap) cout << i << " ";
        cout << endl;
    }
};

int main() {
    MinHeap minHeap;

    minHeap.MinHeapInsert(3);
    minHeap.MinHeapInsert(2);
    minHeap.MinHeapInsert(15);
    minHeap.MinHeapInsert(5);
    minHeap.MinHeapInsert(4);

    cout << "Heap: ";
    minHeap.PrintHeap();

    cout << "Minimum: " << minHeap.HeapMinimum() << endl;

    cout << "Extract Minimum: " << minHeap.HeapExtractMin() << endl;

    minHeap.PrintHeap();

    minHeap.HeapDecreaseKey(2, 1);
    cout << "After Decrease Key: ";
    minHeap.PrintHeap();

    return 0;
}

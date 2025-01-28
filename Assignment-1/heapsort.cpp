#include <iostream>
#include <vector>
using namespace std;

void MaxHeapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        MaxHeapify(arr, n, largest);
    }
}

void BuildMaxHeap(vector<int>& arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        MaxHeapify(arr, n, i);
    }
}

void HeapSortDescending(vector<int>& arr) {
    int n = arr.size();

    BuildMaxHeap(arr, n);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        MaxHeapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Original Array: ";
    for (int i : arr) cout << i << " ";
    cout << endl;

    HeapSortDescending(arr);

    cout << "Sorted Array in Descending Order: ";
    for (int i : arr) cout << i << " ";
    cout << endl;

    return 0;
}

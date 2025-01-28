#include <iostream>
#include <vector>
#include <queue> 
#include <climits>
using namespace std;

int FindLargestUsingHeap(const vector<int>& arr) {
    if (arr.empty()) return INT_MIN;

   
    priority_queue<int> maxHeap;

  
    for (int i : arr) {
        maxHeap.push(i);
    }

  
    return maxHeap.top();
}

int main() {
    vector<int> arr = {12, 3, 45, 2, 34, 7};

    cout << "Array: ";
    for (int i : arr) cout << i << " ";
    cout << endl;

    cout << "Largest Element (using heap): " << FindLargestUsingHeap(arr) << endl;

    return 0;
}

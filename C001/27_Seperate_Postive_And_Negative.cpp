// ORDER MUST BE PREESVED

// O(1) --> Space complexity
// With two-pointer we can't maintain relative order order

#include <iostream>
#include <vector>
using namespace std;

void segregatePosNeg(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        // If current element is negative
        if (arr[i] < 0) {
            int j = i;
            // Shift all positive elements to the right until we reach the front
            while (j > 0 && arr[j - 1] >= 0) {
                swap(arr[j], arr[j - 1]);
                j--;
            }
        }
    }
}

int main() {
    vector<int> arr = {1, -2, 3, -4, 5, -6, 7, 8};
    segregatePosNeg(arr);
    
    for (int x : arr)
        cout << x << " ";
    return 0;
}

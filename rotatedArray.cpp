#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rightRotate(vector<int>& arr, int d) {
    int n = arr.size();
    d = d % n;

    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin() + d);
    reverse(arr.begin() + d, arr.end());
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int d = 2;

    rightRotate(arr, d);

    for (int num : arr)
        cout << num << " ";
    return 0;
}

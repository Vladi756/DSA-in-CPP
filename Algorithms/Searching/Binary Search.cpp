#include <bits/stdc++.h>

using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {       
        int mid = l + (r - l) / 2;      // The mid point of the array.

        if (arr[mid] == x) return mid;  // If element is in the middle, return it right away.

        if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);  // If target > middle (i.e. in the left part) run binary search recursively on new subarray.
        else return binarySearch(arr, mid + 1, r, x);       // Else recursively run it on new subarray (same thing just different part of the array)
    }

    return -1;
}

int main(void)  // Test Driver
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x;
    cin >> x;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result;
    return 0;
}

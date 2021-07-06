#include <bits/stdc++.h>

int maxSubArray(int arr[]);

int main()  // Test Driver for the algorithm
{
    int arr[9] = {-2, 4, -2, 6, 9, 4, -5, 6, -13};

    int x = maxSubArray(arr);

    std::cout << x;

    return 0;
}
// Algorithm implemented in the function below 
 int maxSubArray(int arr[9]) {
        int n = sizeof(arr)/sizeof(int);     // Size of array
        int a = INT_MIN;                     // Maximum so Far
        int b = 0;                           // Maximum ending at particular poisition it's at (maximum ending here).
        for(int i = 0; i < n; i++) {
            b += arr[i];                    // Subarray 
            if(b > a){                      // New Maximum 
                a = b;
            }
            if(b < 0) {                     // If the maximum is negative, assign it to 0.
                b = 0;
            }
        }
    return a;                               // Maximum subarray. 
    }

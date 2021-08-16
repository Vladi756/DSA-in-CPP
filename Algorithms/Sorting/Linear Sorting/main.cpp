#include <bits/stdc++.h>

void countingSort(int arr[], size_t n, int k){
    int count[k+1];
    int b[n];
    for(int i = 0; i < n; i++){ // Initialize everything to 0.
        count[i] = 0;
    }
    for(int i = 0; i < n; i++){ // Counts number of elements with distinct keys.
        ++count[arr[i]];
    }
    for(int i = 1; i <= k; i++){ // Updates the count array to show the position (NOT index position) the values should be at.
        count[i] += count[i-1];
    }
    for(int i = n-1; i >= 0; i--){  // Prints the numbers to their respective positions.
        b[--count[arr[i]]] = arr[i];
    }
    for(int i = 0; i < n; i++){  // Copies sorted result back into original array.
        arr[i] = b[i];
    }
}

int main(){
    int arr[] = {0, 10, 1, 9, 2, 8, 3, 7, 4, 6, 5};
    size_t n = 11;
    int k = 10;
    countingSort(arr, n, k);
    for(int x : arr){std::cout << arr[x] << "\t";}
}

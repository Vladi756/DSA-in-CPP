#include <bits/stdc++.h>

void mergeSort(int arr[], int l, int r);
void mergeFunction(int arr[], int l, int m, int r);

int main(){         // Test Driver;

    int myArray[10] = {4, 2, 8, 9, 6, 10, 1, 5, 3, 7};

    std::cout << "Original array: " << std::endl;

    for(int i = 0; i < 10; i++){
        std::cout << myArray[i] << std::endl;
    }
    std::cout << "Running MergeSort..." << std::endl;

    mergeSort(myArray, 0, 9);

    std::cout << "Sorted Array:" << std::endl;

    for(int i = 0; i < 10; i++) {
        std::cout << myArray[i] << std::endl;
    }

    return 0;
}

void mergeSort(int arr[], int l, int r) {   // Merge Sort Algorithm
    if(l < r){
        int m = (l + r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        mergeFunction(arr, l, m, r);
    }
}

void mergeFunction(int arr[], int l, int m, int r){             // Merge function
    int i = l;          // Starting point of left subarray.
    int j = m + 1;      // Starting point of right subarray.
    int k = l;          // Starting point of temp array.
    int temp[10];       // To avoid size restrictions, use vectors.

    while((i <= m) && (j <= r)) {           // While both subarrays still have elements
        if(arr[i] <= arr[j]){
            temp[k] = arr[i];
            k++;
            i++;
        } else {
            temp[k] = arr[j];
            k++;
            j++;
        }
    }
    while(i <= m) {         // While left subbaray sitll has elements, but left one is empty
        temp[k] = arr[i];   // Because it's already sorted, so just assign the remainder to temp array.
        k++;
        i++;
    }
    while(j <= r) {
        temp[k] = arr[j];
        k++;
        j++;
    }
    for(int p = l; p <= r; p++) {
        arr[p] = temp[p];
    }
}

#include <iostream>

void bubbleSort(int arr[], size_t n); // Forward Declaration

void swap(int *a, int *b) {  // Utility Function
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    
    int arr[] = {1, 10, 2, 9, 3, 8, 4, 5, 8, 6, 7}; // Test Array 
    size_t n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);

    for(unsigned int i = 0; i < n; i++) {    // To show sorted array.
        std::cout << arr[i] << "\t";
    }

}

void bubbleSort(int arr[], size_t n) {
    for(unsigned int i = 0; i < n; i++){
        for(unsigned int j = i; j < n - i - 1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Output: 1    2   3   4   5   6   7   8   9   10

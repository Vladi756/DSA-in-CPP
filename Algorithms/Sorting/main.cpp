#include <iostream>

void insertionSort(int arr[], size_t n);    // Forward Declaration 

int main() { // Driver code
    int arr[] = {1, 10, 2, 9, 3, 8, 4, 5, 8, 6, 7};
    size_t n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, n);

    for(unsigned int i = 0; i < n; i++){
        std::cout << arr[i] << "\t";
    }

}

void insertionSort(int arr[], size_t n){
   int i, k, j;
   for(i = 1; i < n; i++){
        j = i - 1;
        k = arr[i];
        while(j > 0 && arr[j] > k){
            arr[j+1] = arr[j]; // j+1 is where k is.
            j--;
        }
        arr[j+1] = k;
   }
}

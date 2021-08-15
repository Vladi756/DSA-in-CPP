#include <iostream>

void insertionSort(int arr[], size_t n){
    int i, j, k;            // i, key, value; respectively
    for(int i = 1; i < n; i++){
        j = i - 1;
        k = arr[i];
        while(j > 0 && arr[j] > k){
            arr[j+1] = arr[j];      // Have two of the same elements
            j--;
        }
        arr[j+1] = k;         // Overrides to proper position
    }
}

int main()
{
    int arr[] = {0, 10, 1, 9, 2, 8, 3, 7, 4, 6, 5}; // size 11
    int n = 11;

    insertionSort(arr, n);

    for(int i = 0; i < n; i++){std::cout << arr[i] << "\t";}

    return 0;
}

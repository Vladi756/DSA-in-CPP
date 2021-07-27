#include <iostream>

void selectionSort(int arr[], size_t n);

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int arr[] = {1, 10, 2, 9, 3, 8, 4, 5, 8, 6, 7};
    size_t n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);

    for(unsigned int i = 0; i < n; i++){
        std::cout << arr[i] << "\t";
    }

}

void selectionSort(int arr[], size_t n){
    unsigned int i, j, minInd;
    for(i = 0; i < n-1; i++){       // Because when only n is left - it is already sorted - no need to do another pass.
        minInd = i;
        for(j = i + 1; j < n; j++){
            if(arr[j] < arr[minInd]){
                minInd = j;
            }
        }
        swap(&arr[minInd], &arr[i]);
    }
}

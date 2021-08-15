#include <iostream>

void quicksort(int arr[], int s, int e);
int Partition(int arr[], int s, int e);

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int arr[] = {0, 10, 1, 9, 2, 8, 3, 7, 4, 6, 5};

    quicksort(arr, 0, 11);

    for(int i = 0; i < 11; i++){
        std::cout << arr[i] << "\t";
    }
}

void quicksort(int arr[], int s, int e){
    if(s < e){
        int p = Partition(arr, s, e);
        quicksort(arr, s, p);
        quicksort(arr, p+1, e);
    }
}

int Partition(int arr[], int s, int e){
    int pivot = arr[s];
    int i = s;
    int j = e;
    while(i < j){
        do {
            i++;
        } while(arr[i] <= pivot);
        do {
            j--;
        } while(arr[j] > pivot);
        if(i < j){
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[s], &arr[j]);
    return j;
}

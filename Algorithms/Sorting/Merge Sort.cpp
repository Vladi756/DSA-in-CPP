#include <bits/stdc++.h>

void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);

int main(){
    int arr[] = {0, 10, 1, 9, 2, 8, 3, 7, 4, 6, 5};

    mergeSort(arr, 0, 10);

    for(int i = 0; i <= 10; i++){       // n - 1;
        std::cout << arr[i] << "\t";
    }
}

void mergeSort(int arr[], int l, int r){
    if(l < r){
        int m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void merge(int arr[], int l, int m, int r){
    int i = l;
    int j = m + 1;
    int k = l;
    int temp[11];
    while(i <= m && j <= r){
        if(arr[i] <= arr[j]){
            temp[k] = arr[i];
            i++; k++;
        } else {
            temp[k] = arr[j];
            j++; k++;
        }
    }
    while(i <= m) {
        temp[k] = arr[i];
        i++; k++;
    }
    while(j <= r) {
        temp[k] = arr[j];
        j++; k++;
    }
    for(int s = l; s <= r; s++){
        arr[s] = temp[s];
    }
}

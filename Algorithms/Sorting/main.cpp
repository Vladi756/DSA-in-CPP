#include <iostream>

void insertionSort(int a[], int n);
void selectionSort(int a[], int n);
void mergeSort(int a[]);
void Merge(int left[], int right[], int a[]);
void printArray(int arr[], int n);

// Main function to test/demonstrate the algorithms.

int main()
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original Array:" << std::endl;
    printArray(arr, n);
    std::cout << "Insertion Sort:" << std::endl;
    insertionSort(arr, n);
    printArray(arr, n);
    std::cout << "Selection Sort" << std::endl;
    selectionSort(arr, n);
    printArray(arr, n);
    std::cout << "Merge Sort" << std::endl;
    mergeSort(arr);
    printArray(arr, n);

    return 0;
}

// ----------- INSERTION SORT --------------- //
/*
 Think of i as the increment variable, j as the 'hole'
 which is the index where the checking happens, and k as the
 value at the index of the hole. While the hole is > 0. Meaning
 it's still not the smalles element, AND, while the element BEHIND
 the hole is greater than it (i.e. the array is unsorted still), then
 copy a[hole-1] to a[hole], this means there are now two identical
 elements in the array. Decrement the hole so you analyze the next
 element in the array. After the condition is no longer true, it means
 the element currently being alayzed is in its proper position, and
 therefore you assign the value to wherever the hole ended up. Repeat
 untill n and you got yourself a sorted array. O(n^2), quadratic time
 complexity - not ideal, not even good, let alone 'ideal'.
*/
void insertionSort(int a[], int n){
    int i, j, k = 0;
    for(i = 0; i < n; i++){
    j = i;
    k = a[i];
        while(j > 0 && a[j-1] > k){
            a[j] = a[j-1];
            j--;
        }
        a[j] = k;
    }
}

// --------------- SELECTION SORT ---------------- //
/*
Assume the first element is the smallest, and assign it to a variable
accordingly. Then check the remaining elements, assinging each smaller one
you encounter to be the new minimum. Swap the first element with the new
minumim. Then repeat for every element. Awful aglgorithm, runs in quadratic,
O(n^2) time.
*/
void selectionSort(int a[], int n){
    for(int i = 0; i < n-1; i++){
        int Min = i;
        for(int j = 1; j < n; j++){
            if(a[j] < Min){
                Min = j;
            }
            int temp = a[i];
            a[i] = a[Min];
            a[Min] = temp;
        }
    }
}

// --------------- MERGE FUNCTION ---------------- //
/*
Merge sort divides the input array down into two algorithms, then those two into 4
and so on, untill all the subarrays are all just one element - it does this
recursively. Then, it merges them back again and again untill evferything is merged
back into the original array - which is now sorted. The merge function determines which
subarray's element is smaller, and adds that into the merged array.
*/
void Merge(int left[], int right[], int a[]){
    int i, j, k = 0;
    int n = sizeof(left)/sizeof(int);
    int m = sizeof(right)/sizeof(int);
    while(i < n && j < m){
        if(left[i] <= right[j]){
            a[k] = left[j];
            j++;
        } else {
            a[k] = right[i];
            i++;
        }
        k++;
        while(i < n){
            a[k] = left[i];
            i++;
            k++;
        }
        while(j < m){
            a[k] = right[j];
            j++;
            k++;
        }
    }
}

// -------------------- MERGE SORT -------------- //
/*
Merge sort is a good example of a divide an conquer algorithm, as well as an example of
an important programming paradigm - recursion. In order to 'divide' the array, it calls
itself recursively. Then, the merge function 'conquers' the problem by incrementally sorting
the array. Time complexity O(n logn) which is linearithmic time, and is much better than the
quadratic time complexity achieved by the other two algorithms on here. So yeah - that's that.
*/
void mergeSort(int a[]){
    int n = sizeof(a)/sizeof(int);
    if(n < 2) return;
    int mid = n/2;
    int left[mid];
    int right[n - mid];
    for(int i = 0; i < mid - 1; i++){
        left[i] = a[i];
    }
    for(int j = mid; j < n - 1; j++){
        right[j] = a[j];
    }
    mergeSort(left);
    mergeSort(right);
    Merge(left, right, a);
}

// -------------- PRINT FUNCTION ----------------- //
/*
Function to print the arrays - pretty self explanatory this one.
*/
void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";

    std::cout << std::endl;
}

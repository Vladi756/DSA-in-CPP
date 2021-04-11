#include <bits/stdc++.h>        // Includes everything needed with one line.

void swap(int a, int b);
void bubbleSort(int arr[]);

int main()              // Test Driver for the algorithm
{
    int arr[9] = {3, 8, 1, 2, 10, 5, 15, 9, 4};

    for(int f = 0; f < 9; f++){
        std::cout << arr[f] << std::endl;       // Before swap
    }
    std::cout << "" << std::endl;

    bubbleSort(arr);

    for(int k = 0; k < 9; k++){                 // After Swap
        std::cout << arr[k] << std::endl;
    }
    return 0;
}

 void bubbleSort(int arr[]){            // The actual algorithm
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 8; j++){
            if(arr[j] > arr[j + 1]){
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
 }

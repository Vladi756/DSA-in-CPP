#include <bits/stdc++.h>

void swap(int a, int b);
void bubbleSort(int arr[]);

int main()
{
    int arr[9] = {3, 8, 1, 2, 10, 5, 15, 9, 4};

    for(int f = 0; f < 9; f++){
        std::cout << arr[f] << std::endl;
    }
    std::cout << "" << std::endl;

    bubbleSort(arr);

    for(int k = 0; k < 9; k++){
        std::cout << arr[k] << std::endl;
    }
    return 0;
}

 void bubbleSort(int arr[]){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 8; j++){
            if(arr[j] > arr[j + 1]){
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
 }

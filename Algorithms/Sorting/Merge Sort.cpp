#include <bits/stdc++.h>

void mergeSort(std::vector<int> &a, int l, int r);
void merge(std::vector<int> &a, int l, int m, int r);

int main(){
    std::vector<int> nums = {0, 10, 1, 9, 2, 8, 3, 7, 4, 6, 5};
    mergeSort(nums, 0, 11);

    for(int x : nums){std::cout << nums[x] << "\t";}
}

void mergeSort(std::vector<int> &a, int l, int r){
    if(l < r){
        int m = (l+r)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }
}

void merge(std::vector<int> &a, int l, int m, int r){
    int i = l;
    int j = m + 1;
    int n = a.size();
    std::vector<int> temp(n, 0);
    int k = l;

    while(i <= m && j <= r){
        if(a[i] <= a[j]){
            temp[k] = a[i];
            i++;
        } else {
            temp[k] = a[j];
            j++;
        }
        k++;
    }
    while(j <= r){
        temp[k] = a[j];
        k++; j++;
    }
    while(i <= m){
        temp[k] = a[i];
        i++; k++;
    }
    for(int x = l; x <= r; x++){
        a[x] = temp[x];
    }
}

#include <bits/stdc++.h>

void countSort(std::vector<int> &a, int n, int k);

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    std::vector<int> nums = {0, 10, 1, 9, 2, 8, 3, 7, 4, 6, 5};
    int n = nums.size();
    countSort(nums, n, 10);

    for(int x : nums){std::cout << nums[x] << "\t";}
}

void countSort(std::vector<int> &a, int n, int k){
    std::vector<int> count(k+1, 0);
    std::vector<int> temp(n, 0);

    for(int i = 0; i < n; i++){count[a[i]]++;}

    for(int i = 1; i <= k; i++){count[i] += count[i-1];}

    for(int i = n-1; i >= 0; i--){ temp[--count[a[i]]] = a[i];} // PREFIX minus - remember. 

    for(int i = 0; i < n; i++){a[i] = temp[i];}
}

// Output: 0    1   2   3   4   5   6   7   8   9   10
// All of the logic is in the above for loops

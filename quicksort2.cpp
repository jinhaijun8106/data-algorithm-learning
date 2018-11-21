#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int partition(int *nums, int p, int q); 
void quickSort(int *nums, int p, int q) {
    if (p < q) {
        int d = partition(nums, p, q);
        quickSort(nums, p, d - 1);
        quickSort(nums, d + 1, q);
    }
}
int partition(int *nums, int p, int q) {
    int key = nums[q];
    int left = p;
    for (int i = p; i <= q - 1; i++) {
        if (nums[i] <= key) {
            swap(nums[left], nums[i]);
            left++;
        }
    }
    swap(nums[left], nums[q]);
    return left;
}
int main( ) {
    //int nums[] = { 10, 9 , 8, 7, 6, 5, 4, 3, 2, 1, 0,1};
    int nums[] = { 0, 0, 0, 0, 0, 0};
    
    cout <<"before sorted:"<<endl; 
    for (int i = 0; i < sizeof(nums)/sizeof(nums[0]); i++) {
        cout << nums[i] <<" ";
    }
    cout <<"before sorted:"<<endl; 
    quickSort(nums, 0, sizeof(nums)/sizeof(nums[0]) - 1);
    cout <<"sorted:"<<endl; 
    for (int i = 0; i < sizeof(nums)/sizeof(nums[0]); i++) {
        cout << nums[i] <<" ";
    }
    cout <<"sorted:"<<endl; 
    return 0;
}

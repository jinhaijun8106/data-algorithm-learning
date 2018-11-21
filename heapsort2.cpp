#include<iostream>
using namespace std;
void heapify (int *nums, int size, int idx) {
    int m = idx;
    int l = 2 * idx + 1;
    int r = 2 * idx + 2;
    if (l < size && nums[l] > nums[m]) {
        m = l;
    }
    if ( r < size && nums[r] > nums[m]) {
        m = r;
    }

    if (m != idx) {
        swap(nums[m], nums[idx]);
        heapify(nums, size, m);
    }
}

void buildHeap(int *nums, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
       heapify(nums, size, i); 
    }
}

void heapSort(int *nums, int size) {
    buildHeap(nums, size);
    while (size > 1) {
        swap(nums[0], nums[size-1]);
        size--;
        heapify(nums, size, 0);
    }
}

bool binarySearch(int *nums, int size, int target) {
    int l = 0, r = size - 1;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (nums[m] < target) {
            l = m + 1;
        } else {
            r = m;
        }
    }

    return (l < size && nums[l] == target) ? true : false;
}


bool binarySearch1(int *nums, int size, int target) {
    int l = 0, r = size - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (nums[m] == target) {
            return true;
        } else if (nums[m] < target){
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    return false;
}

int main() {
    int nums[] = {3,4,5,1,2,3,6,3,2,1,30,43,22};
    int n = sizeof(nums) / sizeof(nums[0]);
    heapSort(nums, sizeof(nums) / sizeof(nums[0]));
    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        cout << nums[i] << " ";    
    }
    int v = 0;
    bool f = binarySearch(nums, n, v);
    cout << "f:" << v << ":" << f << endl;
    
    v = 10;
    f = binarySearch(nums, n, v);
    cout << "f:" << v << ":" << f << endl;

    v = 20;
    f = binarySearch(nums, n, v);
    cout << "f:" << v << ":" << f << endl;

    v = 30;
    f = binarySearch(nums, n, v);
    cout << "f:" << v << ":" << f << endl;

    v = 40;
    f = binarySearch(nums, n, v);
    cout << "f:" << v << ":" << f << endl;

    cout << endl;

}

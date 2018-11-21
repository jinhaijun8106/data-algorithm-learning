#include <iostream>
#include <vector>
#include <climits>
//#include <math>

using namespace std;
double findMedianSortedArray(vector<int> &num1, vector<int> &num2) {
    if (num1.size() > num2.size()) {
        return findMedianSortedArray(num2, num1);
    }
    int n1 = num1.size(), n2 = num2.size(), n = n1 + n2;
    if ( n2 == 0) {
        return 0;
    } else if (n1 == 0) {
        return (num2[n/2] + num2[(n-1)/2])/2.0;
    }

    int l1 = 0, r1 = n1;
    while (l1 <= r1) {
        int m1 = (l1 + r1) / 2;
        int m2 = n / 2 - m1;
        double L1 = (m1 == 0) ? INT_MIN : num1[m1-1];
        double L2 = (m2 == 0) ? INT_MIN: num2[m2-1];
        double R1 = (m1 == n1) ? INT_MAX: num1[m1];
        double R2 = (m2 == n2) ? INT_MAX: num2[m2];
        if (L1 > R2) {
            r1 = m1 - 1;
        } else if (L2 > R1) {
            l1 = m1 + 1;
        } else {
            if (n%2) {
                return min(R1, R2);
            } else {
                return (max(L1, L2) + min(R1, R2) ) / 2;
            }
        }
    }
    return -1;
}

int main() {
    
    int num1[] = {};
    int num2[] = {2,3};
    vector<int> nums1(num1, num1 + sizeof(num1)/sizeof(num1[0]));
    vector<int> nums2(num2, num2 + sizeof(num2)/sizeof(num2[0]));
    double mid = findMedianSortedArray(nums1, nums2);
    cout << "m:" << mid << endl;
}

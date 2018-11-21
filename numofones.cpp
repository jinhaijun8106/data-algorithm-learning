#include <iostream>
using namespace std;
    int numofOnes(int n) {
        int res = 0;
        int a = n, b;
        for (long k = 1; k <= n; k = k * 10) {
            b = a % 10;
            a = a / 10;
            if (b == 0) {
                res += a * k;
            } else if (b == 1) {
                res += a * k + (n % k + 1);
            } else {
                res += a * k + k;
            }
        } 
        return res;
    }


int main()
{
    int num1 = numofOnes(1);
    int num2 = numofOnes(10); 
    int num3 = numofOnes(99); 
    int num4 = numofOnes(999); 
    cout << num1<<endl;
    cout << num2<<endl;
    cout << num3<<endl;
    cout << num4<<endl;
}

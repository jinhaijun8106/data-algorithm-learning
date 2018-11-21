#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        long value = 0, temp;
        int index = 0;
        int signed_flag = 1;
        while(str[index] == ' ') {
                index++;
        }
        if (str[index] == '-' || str[index] == '+') {
            signed_flag = str[index] == '-' ? (-1) : 1;
            index ++;
        } else if ( str[index] <'0' || str[index] > '9') {
            return 0;
        }
        
        while (str[index] >= '0' && str[index] <= '9') {
            value = value * 10 + (str[index] - '0');
            temp = (signed_flag == 1 ? (value) : (-value));
            if (temp > INT_MAX || temp < INT_MIN) {
                return temp > INT_MAX ? INT_MAX : INT_MIN;
            }
            index ++;
        }
        return signed_flag == 1 ? (value) : (-value);
    }   
};

class Solution_B {
public:
    int myAtoi(string str) {
        unsigned int iTotalLen = str.length();
        unsigned int iValidStartIndex;
        long value = 0;
        int signed_flag = 1;
        char temp;
        
        for (iValidStartIndex = 0; iValidStartIndex < iTotalLen; iValidStartIndex++) {
            temp = str[iValidStartIndex];
            if (temp == ' ') {
                continue;
            } else if (temp == '-') {
                signed_flag = -1;
                break;
            } else if (temp == '+') {
                break;
            } else if (temp - '0'>=0 && 
                       temp - '9'<=0) {
                value = temp - '0';
                break;
            } else {
                return 0;
            }
        }
        
        iValidStartIndex ++;
        for (iValidStartIndex; iValidStartIndex < iTotalLen; iValidStartIndex++) {
            temp = str[iValidStartIndex];
            if (temp - '0' < 0 || temp - '9' > 0) {
                break;
            }
            value = value * 10 + temp - '0';
            if (signed_flag * value > INT_MAX || signed_flag * value < INT_MIN) {
                return signed_flag > 0 ? INT_MAX :INT_MIN;
            } 
        }
        
        return (int)(signed_flag*value);
        
    }
};

int main()
{
   string s("-333");
   Solution solution_a;
   int value = solution_a.myAtoi(s);
    
    cout << s << value<<endl;


}

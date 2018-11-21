#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

void myreverse(char *str, int size)
{
    int l = 0, r = size - 1;
    char temp;
    while (l < r) {
        temp = str[l];
        str[l] = str[r];
        str[r] = temp;
        l++; r--;
    }
}
unsigned int myitoa(unsigned int num, int radix, char *pOutput, int size) {
    int d;
    char ch;
    int converted = 0;
    if (!(radix >= 2 && radix <= 16) ||
          !pOutput ||
          size < 2) {
        return 0;
    }
    
    do {
        d = num % radix;
        num = num / radix;
        ch = d >= 10 ? (d - 10 + 'a') : (d + '0');
        pOutput[converted++] = ch;
    } while (num && converted < size);

    /* failure */
    if (num || converted >= size - 1) {
        return 0;
    }
    
    pOutput[converted] = '\0';
    myreverse(pOutput, converted);

    return converted;
}
int my_lower_bound (vector<int> nums, int target);
int my_upper_bound (vector<int> nums, int target);
string getNextWord(string &str, int start) ;

int main() {
    multiset <int> s;
    int array[] = { 3, 4, 5, 6, 7, 8, 0, 11, 4,4, 3};
    vector<int> nums;  
    for (int i = 0; i < sizeof(array)/sizeof(array[0]); i++) {
        nums.push_back(array[i]);
    }
    s.insert(3);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    int test = 0;
    char str1[100];
    int res = myitoa(test, 2, str1, 10);
    cout << "num:" << test << "r:" << res << "str:" << str1 << endl;
    

    set<int>::iterator it;
    for (it = s.begin(); it != s.end(); it++) {
        cout << "i:" << *it << endl;
    }
    cout <<endl;

    it = s.lower_bound(3);
    cout << "l:" << *it << endl;
    it = s.upper_bound(3);
    cout << "u:" << *it << endl;

    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++){
        cout << "ni:" << i << ": " << nums[i] << endl;
    }
    int target = -20;
    int idx = my_lower_bound(nums, target);
    cout << "t:" << target << endl;
    cout << "low idx:" << idx << endl;

    idx = my_upper_bound(nums, target);
    cout << "t:" << target << endl;
    cout << "up idx:" << idx << endl;

    string str("hello word how are you you are good");
    int offset = 0;
    while (1) {
        string word;
        word = getNextWord(str, offset);
        if (word.empty()){
            break;
        }
        offset += word.size() + 1;
        cout <<"read offset:" << offset << " " << word.c_str()<<endl;
    }
}

int my_lower_bound (vector<int> nums, int target)
{
#if 0
    int count = nums.size() - 1;
    int first = 0;
    while (count > 0) {
        int steps = count / 2;
        if (nums[first + steps] < target) {
            first += steps + 1;
            count -= steps + 1;
        } else {
            count = steps;
        }
    }
    return first;
#else
    int l = 0, r = nums.size() - 1;
    while ( l < r ) {
        int m = l + (r - l) / 2;
        if (nums[m] < target) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l;
#endif
}

int my_upper_bound (vector<int> nums, int target)
{
#if 0
    int count = nums.size() - 1;
    int first = 0;
    while (count > 0) {
        int steps = count / 2;
        if (nums[first + steps] <= target) {
            first += steps + 1;
            count -= steps + 1;
        } else {
            count = steps;
        }
    }
    return first;
#else
    int l = 0, r = nums.size() - 1;
    while ( l < r ) {
        int m = l + (r - l) / 2;
        if (nums[m] <= target) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l;
#endif
}

string getNextWord(string &str, int start) {
    string res;
    if (start < 0 || start >= str.size()) {
        return res;
    }
    int size = str.size();
    int i;
    for (i = start; i < str.size(); i++){
        if (str[i] == ' ') {
            break;
        } else {
            res.push_back(str[i]);
        }
    }

    return res;
}

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int my_lower_bound (vector<int> nums, int target);
int my_upper_bound (vector<int> nums, int target);
string getNextWord(string &str, int start) ;
int longestSubSeq(vector<int> nums) {
    if (nums.empty()){
        return 0;
    }

    vector<int> seq(1, nums[0]);
    for (int i = 1; i < nums.size(); i++) {
       vector<int>::iterator it = lower_bound(seq.begin(), seq.end(), nums[i]);
       if (it != seq.end()) {
            *it = nums[i];
       } else { 
            seq.push_back(nums[i]);
       }
    }

    return seq.size();
}
int longestSubSeq00(vector<int> nums) {
    if (nums.empty()){
        return 0;
    }

    vector<int> seq(1, nums[0]);
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < seq[0]) {
            seq[0] = nums[i];
        } else if (nums[i] > seq.back()) {
            seq.push_back(nums[i]);
        } else {
            vector<int>::iterator it = lower_bound(seq.begin(), seq.end(), nums[i]);
#if 0
            int l = 0, r = seq.size() - 1;
            while (l < r) {
                int mid = l + (r - l) / 2;
                (seq[mid] < seq[l]) ? (l = mid + 1) : (r = mid);
            }
            seq[l] = nums[i];
#endif
            *it = nums[i];
        }
    }

    return seq.size();
}
int longestSubSeq1(vector<int> nums) {
    if (nums.empty() ) {
        return 0;
    }

    int res = 1;
    int n = nums.size();
    vector<int> dp (n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        res = max(res, dp[i]);
    }
    
    return res;
}

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

    int longestSub = longestSubSeq(nums);
    cout << "l1:" << longestSub << endl;
    

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

    longestSub = longestSubSeq(nums);
    cout << "l2:" << longestSub << endl;

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
        nums[m] < target ? (l = m + 1) : (r = m);
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

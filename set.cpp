#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int my_lower_bound (vector<int> nums, int target);
int my_upper_bound (vector<int> nums, int target);
string getNextWord(string &str, int start) ;
int countOnes(unsigned int val);
vector<int> addOne(vector<int> &nums);

int longestWords(string sentense);
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

    unsigned int testv = 0x101;
    int count = countOnes(testv);
    cout << "t:"<< testv << "count:" <<  count << endl;
    
    string sentense("hello word you are the biggest number");
    int longest = longestWords(sentense);
    cout << "longest:" << longest<<endl;
    sentense="    i     hellowordyouarethebiggestnumber";
    longest = longestWords(sentense);
    cout << "longest:" << longest<<endl;
    int array_num[] = {};
    vector<int> numss(array_num, array_num + sizeof(array_num)/ sizeof(array[0]));
   vector<int> ress = addOne(numss);

    cout <<"res:"<<endl;
    for (int i = 0; i < ress.size(); i++) {
        cout << ress[i];
    } 
    cout <<"res:"<<endl;
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
    int l = 0, r = nums.size();
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
    int l = 0, r = nums.size() ;
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

int countOnes(unsigned int val) {
    int res = 0;
    while (val) {
        val = val & (val - 1);
        res++;
    }
    return res;
}

int longestWords(string sentense) {
    int res = 0;
    vector<string> words;
    int start = 0, end;
    int len = sentense.size();
    /* start from the first non ' ' */
    while (start < len && sentense[start] == ' ') {
        start ++;
    }

    sentense.push_back(' ');
    end = sentense.find_first_of(" ", start);
    while (end != string::npos) {
        string word = sentense.substr(start, end - start);
        words.push_back(word);
        cout << "word:" << word << " max:" << res <<  endl;
        res = max(res, (int)word.size());
        start = end + 1;
        end = sentense.find_first_of(" ", start);
    }
    
//    sentense.pop_back();
    cout << "aaaabj:" << sentense << endl << sentense.size();
    sentense.erase(sentense.end()-1 , sentense.end());
    cout << "aaaaaa:" << sentense << endl << sentense.size();
    return res;
}

vector<int> addOne(vector<int> &nums) {
    vector<int> res (nums);
    int carry = 1;
    int n = nums.size();
    for (int i = n - 1; i >= 0; i--) {
        int d = res[i] + carry;
        if (d != 10) {
            res[i] = d;
            return res;
        } else {
            res[i] = 0;
            carry = 1;
        }
    }
    if (carry) {
        res.insert(res.begin(), 1);
    }
    return res;
}

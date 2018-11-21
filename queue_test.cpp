// lower_bound/upper_bound example
#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort
#include <vector>       // std::vector
#include <queue>

using namespace std;
int my_lower_bound (vector<int> nums, int target);
int my_upper_bound (vector<int> nums, int target);
typedef struct _test_data{
    int a;
    int b;
    int c;
    struct _test_data *next;
} test_data;
static bool mycompare(const test_data &m, const test_data &n)
{
    return m.a < n.a || (m.a == n.a && m.b < n.b);
}
class mycompareclass {
public:
  bool operator()(const test_data &m, const test_data &n) const {
    return m.a < n.a || (m.a == n.a && m.b < n.b);
}
};
int main () {
  int myints[] = {10,20,30,30,20,10,10,20};
  int offset;
  int target = 35;
  queue<int> q1;
  test_data t2;
  priority_queue<test_data, vector<test_data>, mycompareclass> q2;
  vector<test_data> v1 = {{1,1,1,NULL}, {2,2,2, NULL}, {0,1,2,NULL}};

  sort(v1.begin(), v1.end(), mycompare);
  for (auto &v:v1) {
       cout << "v:" << v.a <<" "<< v.b <<" "<< v.c << endl;
  }

  std::vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20

  std::sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30

  std::vector<int>::iterator low,up;
  low=std::lower_bound (v.begin(), v.end(), target); //          ^
  up= std::upper_bound (v.begin(), v.end(), target); //                   ^

  std::cout << "lower_bound at position " << (low- v.begin()) << '\n';
  std::cout << "upper_bound at position " << (up - v.begin()) << '\n';

  offset=my_lower_bound (v, target); //          ^
  std::cout << "mylower_bound at position " << offset << '\n';

  offset = my_upper_bound (v, target); //                   ^
  std::cout << "myupper_bound at position " << offset << '\n';

#if 1
  q2.push({1, 3,1, NULL});
  q2.push({1, 1,1, NULL});
  q2.push({1, -1,1, NULL});
  q2.push({1, 2,3, NULL});
  q2.push({1, 0,3, NULL});
  q2.push({2, 4,3, NULL});
  q2.push({0, 4,3, NULL});
#endif
   while (!q2.empty()) {
        auto v = q2.top();
        q2.pop();
       cout << "q:" << v.a <<" "<< v.b <<" "<< v.c << endl;
    }

  return 0;
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


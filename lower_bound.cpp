// lower_bound/upper_bound example
#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort
#include <vector>       // std::vector

using namespace std;
int my_lower_bound (vector<int> nums, int target);
int my_upper_bound (vector<int> nums, int target);
int main () {
  int myints[] = {10,20,30,30,20,10,10,20};
  int offset;
  int target = 35;
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


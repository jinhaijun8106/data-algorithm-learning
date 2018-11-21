#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;

class Solution1 {
public:
    int knapsack(vector < pair <int, int> > & packages, int maxW) {
    int size = packages.size();
    /* dp[i][j]: the max value for the 0 to i packages with max j weight */
    vector <int> dp(maxW+1, 0);
    for (int i = 1 ; i <= size; i++) {
        for (int j = maxW; j >= 1; j--) {
            if ( j - packages[i-1].first < 0) {
                dp [j] = dp[j];
            } else {
                dp[j] = max(dp[j], dp[j-packages[i-1].first] + packages[i-1].second);
            }
        }
    }
    for(int n = 0; n <= maxW; n++) {
        cout << dp[n] << "\t";
    }
    return dp[maxW];
}
};

class Solution {
public:
    int knapsack(vector < pair <int, int> > & packages, int maxW) {
    int size = packages.size();
    /* dp[i][j]: the max value for the 0 to i packages with max j weight */
    vector <vector <int> > dp(size+1,vector <int> (maxW+1, 0)); 
    for (int i = 1 ; i <= size; i++) {
        for (int j = 1; j <= maxW; j++) {
            if ( j - packages[i-1].first < 0) {
                dp [i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-packages[i-1].first] + packages[i-1].second);
            }
        }
    }
    for (int m = 0; m <= size; m++) {
        for(int n = 0; n <= maxW; n++) {
            cout << dp[m][n] << "\t";
        }
        cout << "\n";
    }
    return dp[size][maxW];
    
}
};
int main ()
{
    /* pair: <weight, value> */
    pair <int, int> package;
    vector <pair <int, int> > packages;
    int value;
    Solution knapsack;
    Solution1 knapsack1;

    package.first = 1;
    package.second = 3;
    packages.push_back(package);

    package.first = 2;
    package.second = 6;
    packages.push_back(package);

    package.first = 3;
    package.second = 9;
    packages.push_back(package);

    package.first = 4;
    package.second = 12;
    packages.push_back(package);

    package.first = 5;
    package.second = 15;
    packages.push_back(package);

    package.first = 6;
    package.second = 18;
    packages.push_back(package);

    package.first = 7;
    package.second = 21;
    packages.push_back(package);
    
    package.first = 8;
    package.second = 24;
    packages.push_back(package);

//    value = knapsack.knapsack(packages, 280);

//    cout <<"max value" <<  value << endl;

    value = knapsack1.knapsack(packages, 280);

    cout <<"max value" <<  value << endl;
}


/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */

#include "bits/stdc++.h"

using namespace std;


// @lc code=start
class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp(n + 1, -1);
        return tribonacciTopDown(dp, n);
    }

    int tribonacciTopDown(vector<int>&dp,int n) {
        if(n<=1){
            return n;
        }
        if(n==2){
            return 1;
        }

        if(dp[n]==-1){
            dp[n] = tribonacciTopDown(dp, n - 3) + tribonacciTopDown(dp, n - 2) + tribonacciTopDown(dp, n - 1);
        }

        return dp[n];
    }
};
// @lc code=end

int main(){
    Solution s;
    cout<< s.tribonacci(4) << endl;
}
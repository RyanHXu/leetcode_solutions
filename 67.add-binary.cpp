/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

#include "bits/stdc++.h"

using namespace std;


// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        int carray = 0;
        int m = a.size() - 1;
        int n = b.size() - 1;


        while (m>=0 && n>=0)
        {
            int sum = a[m] + b[n] + carray;
            carray = sum / 2;
            sum %= 2;
            
        }
    }
};
// @lc code=end


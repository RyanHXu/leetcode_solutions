/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

#include "bits/stdc++.h"

using namespace std;


// @lc code=start
/**
hold[i] = max(hold[i-1], rest[i-1]-prices[i])
sold[i] = hold[i-1] + prices[i]
rest[i] = max(rest[i-1],sold[i-1])

init: rest[0] = sold[0] =0, hold[0] = INT32_MIN
ans: max(rest[i],sold[i])
 */

// https://www.youtube.com/watch?v=oL6mRyTn56M

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int rest=0, sold=0,hold=INT32_MIN;
        for (const auto& price : prices) {
            hold = max(hold, rest - price);
            sold = hold + price;
            rest = max(hold, rest - price);
        }
        return max(rest, sold);
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=717 lang=cpp
 *
 * [717] 1-bit and 2-bit Characters
 */
#include "bits/stdc++.h"

using namespace std;

// @lc code=start
class Solution
{
public:
    bool isOneBitCharacter(vector<int> &bits)
    {
        int i = 0;
        int n = bits.size();
        while (i < n)
        {
            if (i == n - 1)
                return true;
            if (bits[i] == 1)
                i += 2;
            else
                i += 1;
        }
        return false;
    }
};
// @lc code=end

/*
 * @lc app=leetcode id=1009 lang=cpp
 *
 * [1009] Complement of Base 10 Integer
 */

// @lc code=start
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0){
            return 1;
        }
        int todo = n, bit = 1;
        while (todo)
        {
            n ^= bit;
            bit <<= 1;
            todo >>= 1;
        }
        return n;
    }
};
// @lc code=end


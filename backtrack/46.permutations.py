#
# @lc app=leetcode id=46 lang=python3
#
# [46] Permutations
#

# @lc code=start
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []

        def backtrack(comb: list[int], n, first):
            if first == n:
                res.append(nums[:])
            
            for i in range(first, n):
                comb[i], comb[first] = comb[first], comb[i]
                backtrack(comb,n,first+1)
                comb[i], comb[first] = comb[first], comb[i]

        backtrack(nums,len(nums),0)
        return res                


# @lc code=end

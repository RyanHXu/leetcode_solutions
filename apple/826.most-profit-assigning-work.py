#
# @lc app=leetcode id=826 lang=python3
#
# [826] Most Profit Assigning Work
#

# @lc code=start
from pprint import pprint
from typing import List
class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        jobs = list(zip(difficulty, profit))
        jobs.sort()

        res = i = best =0
        n = len(jobs)
        
        for skill in sorted(worker):
            while i<n and skill >= jobs[i][0]:
                best = max(best, jobs[i][1]);
                i+=1
            res += best
        return res
        
# @lc code=end







    
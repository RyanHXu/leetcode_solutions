#
# @lc app=leetcode id=2101 lang=python3
#
# [2101] Detonate the Maximum Bombs
#

# @lc code=start
from pprint import pprint
from typing import List


class Solution:
    def maximumDetonation(self, bombs: List[List[int]]) -> int:
        cnt, n = 0, len(bombs)
        ori = set(range(n))
        dic = {}
        for i in range(n):
            dic[i] = set()

        for i in range(n):
            [x1, y1, r1] = bombs[i]
            for j in range(i+1, n):
                [x2, y2, r2] = bombs[j]

                sqare_distance = pow(x1-x2, 2)+pow(y1-y2, 2)
                if sqare_distance <= pow(r1, 2):
                    dic[i].add(j)
                if sqare_distance <= pow(r2, 2):
                    dic[j].add(i)

        while ori:
            i = ori.pop()
            cur = diff = dic[i]
            cur.add(i)
            pre = cur

            while diff:
                for next in diff:
                    cur = cur | dic[next]
                    # cur = set.union(cur,dic[next])

                diff = cur-pre
                pre = cur

            ori -= pre
            cnt = max(cnt, len(cur))

        return cnt


# @lc code=end
ori = set(range(5))
ori2 = set(range(5, 10))

print(ori | ori2)

# x1, y1, r1 = [10, 10, 5]
# print(x1)
# print(y1)
# print(r1)

s = Solution()
print(s.maximumDetonation(
    [[1, 2, 3], [2, 3, 1], [3, 4, 2], [4, 5, 3], [5, 6, 4]]))

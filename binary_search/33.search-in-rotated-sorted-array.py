#
# @lc app=leetcode id=33 lang=python3
#
# [33] Search in Rotated Sorted Array
#

# NOTE: two pass
# @lc code=start

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if not nums:
            return -1
        
        l,r=0,len(nums)-1
        
        while l<=r:
            m = l + (r-l)//2
            
            if nums[m] == target:
                return m
            
            # first part
            if nums[l]<=nums[m]:
                # target might inside first part
                if nums[l]<= target <=nums[m]:
                    r = m-1
                # target might inside second part
                else:
                    l = m+1
            # second part
            else:
                if nums[m] <= target <= nums[r]:
                    l = m+1
                else:
                    r = m-1
        return -1
    
                    


# @lc code=end


#  two pass
class Solution2:
    def search(self, nums: List[int], target: int) -> int:

        def find_rotate_index(l, r):
            # check if nums rotated
            if nums[l] < nums[r]:
                return 0
            while l <= r:
                pivot = l + (r-l)//2

                # piovt: the largest one
                if nums[pivot] > nums[pivot+1]:
                    return pivot + 1
                else:
                    # largest on in the second part
                    if nums[pivot] < nums[l]:
                        r = pivot - 1
                    # largest on in the first part
                    else:
                        l = pivot + 1

        def bt(l, r):
            while l <= r:
                pivot = l+(r-l)//2
                if nums[pivot] == target:
                    return pivot
                else:
                    if nums[pivot] < target:
                        l = pivot + 1
                    else:
                        r = pivot - 1
            return -1

        n = len(nums)
        if n == 1:
            return 0 if nums[0] == target else -1

        rotate_index = find_rotate_index(0, n-1)

        if nums[rotate_index] == target:
            return rotate_index

        if rotate_index == 0:
            return bt(0, n-1)
        if target < nums[0]:
            return bt(rotate_index, n-1)
        return bt(0, rotate_index)

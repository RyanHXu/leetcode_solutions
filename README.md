



[TOC]





## Prefix

### subarray

#### [Two Sum Less Than K](https://leetcode.com/problems/two-sum-less-than-k/description/)

#### [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/description/)

#### [Continuous Subarray Sum](https://leetcode.com/problems/continuous-subarray-sum/description/)

#### [Subarray Product Less Than K](https://leetcode.com/problems/subarray-product-less-than-k/description/)







## Binary Search

```c++
int BinarySearch(vector<int>& nums, int target){
    int l = 0, r = nums.size() - 1;
    // NOTE: if we using l<r, then we won't be able to search last elem in nums
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (nums[m] == target)
        return m;
      else if (nums[m] < target)
        l = m + 1;
      else
        r = m - 1;
    }
    // l return the position which be inserted 
    // return l;
    return -1;
}
```



- left
- roated sorted array







## Tree

### serialize and Deserialize

#### [Serialize and Deserialize BST](https://leetcode.com/problems/serialize-and-deserialize-bst/description/)

#### [Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/)



### path sum

#### [Path Sum](https://leetcode.com/problems/path-sum/description/)

#### [Path Sum II](https://leetcode.com/problems/path-sum-ii/description/)

#### [Path Sum III](https://leetcode.com/problems/path-sum-iii/description/)



### balance









## two pointers



### merge intervals

[Merge Intervals](https://leetcode.com/problems/merge-intervals/description/)

[Insert Interval](https://leetcode.com/problems/insert-interval/description/)

[Interval List Intersections](https://leetcode.com/problems/interval-list-intersections/description/)



### meeting rooms

[Meeting Rooms](https://leetcode.com/problems/meeting-rooms/description/)

[Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/description/)

[Car Pooling](https://leetcode.com/problems/car-pooling/description/)



### different from meeting room II

> sort balloon endX instead of startX

[Minimum Number of Arrows to Burst Balloons](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/)



### others

[Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/description/)

[Maximum Number of Events That Can Be Attended](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/description/)







## sliding window



### fixed windows size

[Maximum Average Subarray I](https://leetcode.com/problems/maximum-average-subarray-i/description/)



### unfixed windows size

[Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/description/)



with hash map

[Longest Substring with At Most K Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/description/)



[Fruit Into Baskets](https://leetcode.com/problems/fruit-into-baskets/description/)



### hard

[Maximum Average Subarray II](https://leetcode.com/problems/maximum-average-subarray-ii/description/)




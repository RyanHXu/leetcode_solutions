/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
 */

#include "bits/stdc++.h"

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// @lc code=start

// NOTE:
// unordered_map<long, int> instead of unordered_map<int, int>
// https://leetcode.com/problems/path-sum-iii/solution/
// https://leetcode.com/problems/path-sum-iii/discuss/1525380/Easy-O(N)-solution-or-hashmap-or-C%2B%2B-Code-Commented

class Solution {
 public:
  int ans = 0;
  int target;

  unordered_map<long, int> m;
  int pathSum(TreeNode *root, int targetSum) {
    target = targetSum;
    preorder(root, 0);
    return ans;
  }

  void preorder(TreeNode *root, long currSum) {
    if (root) {
      currSum += root->val;
      // In situation 1, the tree path with the target sum starts from the root. That means the current prefix sum is equal to the target sum curr_sum == k, so one should increase the counter by 1: count += 1
      if (currSum == target) ++ans;
      // In situation 2, the tree path with the target sum starts somewhere downwards. That means we should add to the counter the number of times we have seen the prefix sum curr_sum - target so far: count += h[curr_sum - target]
      if (m[currSum - target]) ans += m[currSum - target];
      ++m[currSum];
      preorder(root->left, currSum);
      preorder(root->right, currSum);
      --m[currSum];
    }
  }
};
// @lc code=end

// https://leetcode.com/problems/path-sum-iii/discuss/683906
class Solution {
 public:
  int ans = 0;
  int pathSum(TreeNode *root, int targetSum) {
    if (root) {
      dfs(root, targetSum);
      pathSum(root->left, targetSum);
      pathSum(root->right, targetSum);
    }
    return ans;
  }

  // NOTE:
  // the max value sum could be 10^9*10^3 => 10^12, so change its type to
  // long(int64)
  void dfs(TreeNode *root, long sum) {
    if (!root) return;
    if (root->val == sum) ++ans;
    dfs(root->left, sum - root->val);
    dfs(root->right, sum - root->val);
  }
};

// 9223372036854775807
// 2147483647
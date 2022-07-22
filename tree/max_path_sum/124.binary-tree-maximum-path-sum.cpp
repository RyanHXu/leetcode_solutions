/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 */
#include "bits/stdc++.h"

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

// NOTE:
// https://zxi.mytechroad.com/blog/tree/leetcode-124-binary-tree-maximum-path-sum/
// @lc code=start

class Solution {
 public:
  int maxPathSum(TreeNode* root) {
    if (!root) return 0;

    int ans = INT_MIN;
    maxPathSum(root, ans);
    return ans;
  }

  int maxPathSum(TreeNode* root, int& ans) {
    if (!root) return 0;
    int l = max(0, maxPathSum(root->left, ans));
    int r = max(0, maxPathSum(root->right, ans));
    int sum = l + r + root->val;
    ans = max(ans, sum);
    return max(l, r) + root->val;
  }
};
// @lc code=end

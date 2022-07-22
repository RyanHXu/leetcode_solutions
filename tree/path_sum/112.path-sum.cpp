/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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

// recursive
class Solution {
 public:
  bool hasPathSum(TreeNode *root, int targetSum) {
    // check if tree is null
    if (!root) return false;

    targetSum -= root->val;

    // reach leaf node
    if (!root->left && !root->right) return targetSum == 0;

    return hasPathSum(root->left, targetSum) ||
           hasPathSum(root->right, targetSum);
  }
};
// @lc code=end

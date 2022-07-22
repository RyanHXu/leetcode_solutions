/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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

// @lc code=start

class Solution {
 public:
  bool isValidBST(TreeNode* root) { return isValidBST(root, nullptr, nullptr); }

  bool isValidBST(TreeNode* root, TreeNode* low, TreeNode* high) {
    if (!root) return true;

    if ((low && root->val <= low->val) || (high && root->val >= high->val))
      return false;

    return isValidBST(root->right, root, high) &&
           isValidBST(root->left, low, root);
  }
};
// @lc code=end

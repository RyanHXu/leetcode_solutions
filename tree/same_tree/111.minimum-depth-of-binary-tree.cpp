/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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

class Solution {
 public:
  int minDepth(TreeNode *root) {
    if (!root) return 0;

    if (!root->left && !root->right) return 1;

    int depth = INT32_MAX;

    if (root->left) depth = min(depth, minDepth(root->left));

    if (root->right) depth = min(depth, minDepth(root->right));

    return depth + 1;
  }
};
// @lc code=end
/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 */

#include "bits/stdc++.h"

using namespace std;
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
  bool isSymmetric(TreeNode *root) {
    return root && isSymmetric(root->left, root->right);
  }

  bool isSymmetric(TreeNode *left, TreeNode *right) {
    // return true if both are null
    if (!left && !right) return true;

    // return false if either left is null or right is null
    if (!left || !right) return false;

    // return false if node's value aren't equal
    if (left->val != right->val) return false;

    return isSymmetric(left->left, right->right) &&
           isSymmetric(left->right, right->left);
  }
};

// @lc code=end

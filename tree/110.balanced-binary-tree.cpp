/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 */

#include "bits/stdc++.h"

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// @lc code=start
// button-up
class Solution {
public:
  int isBalancedTreeHelper(TreeNode *root, int &height) {
    if (root == nullptr) {
      height = -1;
      return -1;
    }

    int left, right;
    if (isBalancedTreeHelper(root->left, left) &&
        isBalancedTreeHelper(root->right, right) && abs(left - right) <= 1) {
      height = max(left, right) + 1;
      return true;
    }
    return false;
  }
  bool isBalanced(TreeNode *root) {
    int height;
    return isBalancedTreeHelper(root, height);
  }
};
// @lc code=end

// top-down recursion
class Solution {
public:
  int height(TreeNode *root) {
    if (root == nullptr) {
      return -1;
    }
    return 1 + max(height(root->left), height(root->right));
  }
  bool isBalanced(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }

    return abs(height(root->left) - height(root->right)) <= 1 &&
           isBalanced(root->left) && isBalanced(root->right);
  }
};
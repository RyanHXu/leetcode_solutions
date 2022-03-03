/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
 */

#include "bits/stdc++.h"

using namespace std;
//   Definition for a binary tree node.
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
  bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    return isIdentical(root, subRoot) ||
           (root->left && isSubtree(root->left, subRoot)) ||
           (root->right && isSubtree(root->right, subRoot));
  }

  bool isIdentical(TreeNode *root, TreeNode *sub) {
    /**
     * case 1: root is nullptr
     * case 2: sub is nullptr
     * case 3: root and sub are nullptr
     */
    if (!root || !sub) {
      return root == sub;
    }

    return root->val == sub->val && isIdentical(root->left, sub->left) &&
           isIdentical(root->right, sub->right);
  }
};
// @lc code=end

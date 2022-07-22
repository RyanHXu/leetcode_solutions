/*
 * @lc app=leetcode id=814 lang=cpp
 *
 * [814] Binary Tree Pruning
 */

#include "bits/stdc++.h"

using namespace std;

// https://zxi.mytechroad.com/blog/tree/leetcode-814-binary-tree-pruning/

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

// delete all the subtree which doesn't contain 1
class Solution {
 public:
  TreeNode* pruneTree(TreeNode* root) {
    if (!root) return root;
    
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if (root->val == 1 || root->left || root->right) return root;

    // when reach a leaf and its value isn't 1,
    // then delete it
    delete root;
    return nullptr;
  }
};
// @lc code=end

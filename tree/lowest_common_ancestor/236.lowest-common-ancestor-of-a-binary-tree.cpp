/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

#include "bits/stdc++.h"

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// https://www.youtube.com/watch?v=py3R23aAPCA&t=909s


// @lc code=start

class Solution {
 public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == nullptr) {
      return nullptr;
    }
    if (root->val == p->val || root->val == q->val) {
      return root;
    }

    TreeNode *l = lowestCommonAncestor(root->left, p, q);
    TreeNode *r = lowestCommonAncestor(root->right, p, q);

    if (!l) {
      return r;
    }

    if (!r) {
      return l;
    }

    return root;
  }
};
// @lc code=end

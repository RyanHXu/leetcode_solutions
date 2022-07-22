/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
  vector<int> inorderTraversal(TreeNode *root) {
    if (!root) return {};

    stack<TreeNode *> s({root});
    vector<int> res;
    TreeNode *curr = root->left;

    while (!s.empty() || curr) {
      while (curr) {
        s.push(curr);
        curr = curr->left;
      }

      curr = s.top();
      res.push_back(curr->val);
      s.pop();
      curr = curr->right;
    }

    return res;
  }
};
// @lc code=end

// recursive
class Solution2 {
 public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    inorderTraversal(root, res);
    return res;
  }

  void inorderTraversal(TreeNode *root, vector<int> &ivec) {
    if (root != nullptr) {
      inorderTraversal(root->left, ivec);
      ivec.push_back(root->val);
      inorderTraversal(root->right, ivec);
    }
  }
};
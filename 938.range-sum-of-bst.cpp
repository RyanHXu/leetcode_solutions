/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
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

// TODO: review top voted solution
// avoid meanless traversal
class Solution {
 public:
  int rangeSumBST(TreeNode *root, int low, int high) {
    int sum = 0;
    stack<TreeNode *> s({root});
    TreeNode *curr;
    while (!s.empty()) {
      curr = s.top();
      s.pop();
      if (curr->val >= low && curr->val <= high) sum += curr->val;
      if (curr->val > low)
        if (curr->left) s.push(curr->left);

      if (curr->val < high)
        if (curr->right) s.push(curr->right);
    }
    return sum;
  }
};
// @lc code=end

// tree traversal
class Solution {
 public:
  int rangeSumBST(TreeNode *root, int low, int high) {
    int sum = 0;
    dfs(root, low, high, sum);
    return sum;
  }

  void dfs(TreeNode *root, int low, int high, int &sum) {
    if (root) {
      dfs(root->left, low, high, sum);
      if (root->val <= high && root->val >= low) {
        sum += root->val;
      }
      dfs(root->right, low, high, sum);
    }
  }
};
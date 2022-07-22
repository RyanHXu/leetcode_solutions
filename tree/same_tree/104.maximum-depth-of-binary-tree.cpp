/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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

// level order traversal
class Solution {
 public:
  int maxDepth(TreeNode *root) {
    if (!root) return 0;

    queue<TreeNode *> q({root});
    TreeNode *curr;
    int depth = 0;

    while (!q.empty()) {
      int level_size = q.size();
      ++depth;
      for (int i = 0; i < level_size; ++i) {
        curr = q.front();
        q.pop();

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
      }
    }
    return depth;
  }
};
// @lc code=end

// recursive
class Solution2 {
 public:
  int maxDepth(TreeNode *root) {
    if (!root) return 0;

    return 1 + max(maxDepth(root->left), maxDepth(root->right));
  }
};
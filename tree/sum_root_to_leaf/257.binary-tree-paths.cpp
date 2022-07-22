/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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

// time complexity: O(N)
// space complexity: O(N)
class Solution {
 public:
  vector<string> ans;
  string s;
  vector<string> binaryTreePaths(TreeNode *root) {
    preorder(root, 0);
    return ans;
  }
  void preorder(TreeNode *root, int l) {
    if (root) {
      s += (l > 0 ? "->" : "") + to_string(root->val);

      // when we reach a leaf node
      if (!root->left && !root->right) {
        ans.push_back(s);
      }

      preorder(root->left, s.size());
      preorder(root->right, s.size());
      while (s.size() != l) s.pop_back();
    }
  }
};
// @lc code=end

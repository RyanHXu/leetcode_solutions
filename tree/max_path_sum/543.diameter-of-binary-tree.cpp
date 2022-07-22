/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 */

#include "bits/stdc++.h"

using namespace std;

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

class Solution {
 public:
  int diameterOfBinaryTree(TreeNode* root) {
    int ans = 0;
    // TODO:
    // stack
    return ans;
  }
};
// @lc code=end

// recursive
class SolutionRecursive {
 public:
  int diameterOfBinaryTree(TreeNode* root) {
    int ans = 0;
    LP(root, ans);
    return ans;
  }

  int LP(TreeNode* root, int& ans) {
    if (!root) return -1;
    int l = LP(root->left, ans) + 1;
    int r = LP(root->right, ans) + 1;
    ans = max(ans, l + r);
    return max(l, r);
  }
};
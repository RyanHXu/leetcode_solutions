/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
     vector<vector<int>> paths;
    vector<int> path;
  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {

    construct_path(root, targetSum);
    return paths;
  }

  void construct_path(TreeNode *root, int targetSum) {
    if (root) {
      path.push_back(root->val);
      if (!root->left && !root->right && root->val == targetSum) {
        paths.push_back(path);
      } else {
        construct_path(root->left, targetSum - root->val);
        construct_path(root->right,targetSum - root->val);
      }

      path.pop_back();
    }
  }
};
// @lc code=end


/*
 * @lc app=leetcode id=968 lang=cpp
 *
 * [968] Binary Tree Cameras
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

// Solution: Greedy + Recursion
// Time complexity: O(N)
// Space complexity: O(H)

// @lc code=start

enum class State { NONE = 0, COVERED = 1, CAMERA = 2 };

class Solution {
 public:
  int ans = 0;
  State dfs(TreeNode* root) {
    if (!root) return State::COVERED;

    State l = dfs(root->left);
    State r = dfs(root->right);
    if (l == State::NONE || r == State::NONE) {
      ++ans;
      return State::CAMERA;
    }
    if (l == State::CAMERA || r == State::CAMERA) {
      return State::COVERED;
    }
    return State::NONE;
  }
  int minCameraCover(TreeNode* root) {
    // TODO:
    // https://zxi.mytechroad.com/blog/tree/leetcode-968-binary-tree-cameras/
    if (dfs(root) == State::NONE) ++ans;
    return ans;
  }
};
// @lc code=end

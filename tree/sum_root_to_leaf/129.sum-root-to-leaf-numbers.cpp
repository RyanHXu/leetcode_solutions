/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
// NOTE:
// time complexity: O(N)
// space complexity: O(H), where H is height
class Solution {
 public:
  int res = 0;
  int sumNumbers(TreeNode *root) {
    dfs(root, 0);
    return res;
  }

  void dfs(TreeNode *root, int currNum) {
    if (root) {
      currNum = currNum * 10 + root->val;

      // when reach a leaf, update root-to-leaf sum
      if (!root->left && !root->right) {
        res += currNum;
      }
      dfs(root->left, currNum);
      dfs(root->right, currNum);
    }
  }
};
// @lc code=end

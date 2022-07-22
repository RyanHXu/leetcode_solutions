/*
 * @lc app=leetcode id=2096 lang=cpp
 *
 * [2096] Step-By-Step Directions From a Binary Tree Node to Another
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

// https://www.youtube.com/watch?v=VvdlzPAQE0s

// https://github.com/wisdompeak/LeetCode/tree/master/Tree/2096.Step-By-Step-Directions-From-a-Binary-Tree-Node-to-Another

// @lc code=start

// TODO:
class Solution {
 public:
  string getDirections(TreeNode *root, int startValue, int destValue) {
    string d1, d2;
    dfs(root, d1, startValue);
    dfs(root, d2, destValue);

    // find LCA node, k used for locating LCA level
    int k = 0;
    while (k < d1.size() && k < d2.size() && d1[k] == d2[k]) ++k;

    for (int i = k; i < d1.size(); ++i) d1[i] = 'U';

    return d1.substr(k) + d2.substr(k);
  }

  bool dfs(TreeNode *node, string &d, int target) {
    if (!node) return false;
    if (node->val == target) return true;
    if (node->left) {
      d.push_back('L');
      if (dfs(node->left, d, target)) return true;
      d.pop_back();
    }
    if (node->right) {
      d.push_back('R');
      if (dfs(node->right, d, target)) return true;
      d.pop_back();
    }
    return false;
  }
};
// @lc code=end

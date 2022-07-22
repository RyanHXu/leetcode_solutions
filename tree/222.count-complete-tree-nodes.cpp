/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
 */
#include "bits/stdc++.h"

using namespace std;
//   Definition for a binary tree node.
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

// profit from a complete tree
// TODO: analyze time complexity
class Solution {
public:
  int depth(TreeNode *root) {
    if(!root){
        return 0;
    }
    return 1 + depth(root->left);
  }
  int countNodes(TreeNode *root) {
    if (root == nullptr)
      return 0;
    int l = depth(root->left);
    int r = depth(root->right);
    if (l == r) {
      return (1 << l) + countNodes(root->right);
    } else {
      return (1 << (l - 1)) + countNodes(root->left);
    }
  }
};


// @lc code=end





// naive approach
// time complexity: O(N)
// space complexity: O(logN) 
class Solution2 {
 public:
  int countNodes(TreeNode *root) {
    if (!root) return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};
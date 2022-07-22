/*
 * @lc app=leetcode id=1469 lang=cpp
 *
 * [1469] Find All The Lonely Nodes
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

// TODO:
// https://leetcode.com/problems/find-all-the-lonely-nodes/discuss/836995/C%2B%2B-or-Recursive-or-Self-Explanatory

// @lc code=start


class Solution {

 public:
  vector<int> res;
  vector<int> getLonelyNodes(TreeNode *root) {
    helper(root);
    return res;
  }

  void helper(TreeNode *root, bool isLoner=false) {
      if(!root)
          return;

        if(isLoner)
            res.push_back(root->val);
            
        isLoner = root->left == nullptr || root->right == nullptr;
        helper(root->left, isLoner);
        helper(root->right, isLoner);
  }
};
// @lc code=end

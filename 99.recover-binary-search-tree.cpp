/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
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

// time complexity is O(N+N) => O(N)
// space complexity is O(N)

class Solution {
  vector<TreeNode *> svec;

 public:
  // identify two swapped elements a and b
  void recoverTree(TreeNode *root) {
    TreeNode *firstError = nullptr;
    TreeNode *secondError = nullptr;
    for (int i = 1; i < svec.size(); ++i) {
      if (svec[i - 1]->val > svec[i]->val) {
        secondError == svec[i];

        if (firstError == nullptr) {
        } else {
          break;
        }
      }
    }

    swap(firstError->val, secondError->val);
  }

  // extract node from tree
  void inorder(TreeNode *root) {
    if (root) {
      inorder(root->left);
      svec.push_back(root);
      inorder(root->right);
    }
  }
};
// @lc code=end

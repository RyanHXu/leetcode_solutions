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

// 1 2 3 4
// 1 3 2 4


// 1 4 2 3
// 1 2 3 4

// time complexity is O(N+N) => O(N)
// space complexity is O(N)

class Solution {
  vector<TreeNode *> svec;

 public:
  // identify two swapped elements a and b
  void recoverTree(TreeNode *root) {


    inorder(root);
    TreeNode *firstError = nullptr;
    TreeNode *secondError = nullptr;
    bool firstErrorOccur = false;

    for (int i = 0; i < svec.size()-1; ++i) {
      if (svec[i]->val > svec[i+1]->val) {
        secondError = svec[i+1];

        if (!firstErrorOccur) {
            firstError = svec[i];
            firstErrorOccur = true;
        } else {
          break;
        }
      }
    }
    // int temp = firstError->val;
    // firstError->val = secondError->val;
    // secondError->val = temp;

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

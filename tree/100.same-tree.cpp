/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
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

class Solution {
 public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    // three possible
    // 1) p ==nullptr && q == nullptr
    // return true
    if (p == nullptr && q == nullptr) {
      return true;
    }

    // 2) p == nullptr && q != nullptr
    // 3) p != nullptr && q == nullptr
    // return false
    if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr)) {
      return false;
    }

    return p->val == q->val && isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
  }
};

// @lc code=end



// simple code
class Solution2 {
 public:
  bool isSameTree(TreeNode *p, TreeNode *q) {

    if (p == nullptr || q == nullptr) {
      return p == q;
    }
    return p->val == q->val && (isSameTree(p->left, q->left)) &&
           (isSameTree(p->right, q->right));
  }
};
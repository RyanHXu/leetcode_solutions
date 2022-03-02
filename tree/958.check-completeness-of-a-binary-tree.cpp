/*
 * @lc app=leetcode id=958 lang=cpp
 *
 * [958] Check Completeness of a Binary Tree
 */

#include "bits/stdc++.h"

using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// @lc code=start

class Solution {
public:
  int countNodes(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
  bool isComplete(TreeNode *root, int idx, int count) {
    if (root == nullptr) {
      return true;
    }
    if (idx >= count) {
      return false;
    }
    return isComplete(root->left, idx * 2 + 1, count) &&
           isComplete(root->right, idx * 2 + 2, count);
  }
  bool isCompleteTree(TreeNode *root) {
    int count = countNodes(root);
    // root must start from 0
    return isComplete(root, 0, count);
  }
};

// @lc code=end

// Definition for a binary tree node.
// https://leetcode.com/problems/check-completeness-of-a-binary-tree/discuss/910868/BFS-%3A-Level-Order-Traversal.-C%2B%2B
// if our first null is last value in binary tree, then our tree is complete binary tree. else not complete binary tree.
class Solution {
public:
  bool isCompleteTree(TreeNode *root) {
    bool flag = false;
    queue<TreeNode *> q({root});
    TreeNode *t;
    while (!q.empty()) {
      t = q.front();
      q.pop();
      if (t == nullptr) {
        flag = true;
      } else {
        if (flag)
          return false;
        q.push(t->left);
        q.push(t->right);
      }
    }
    return true;
  }
};
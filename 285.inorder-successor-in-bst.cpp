/*
 * @lc app=leetcode id=285 lang=cpp
 *
 * [285] Inorder Successor in BST
 */

#include "bits/stdc++.h"
// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
using namespace std;

// @lc code=start

// Using BST properties
class Solution {
public:
  TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
    // potential sucessor node
    TreeNode *successorNode = nullptr;
    while (root != nullptr) {
      if (p->val >= root->val) {
        root = root->right;
      } else {
        successorNode = root;
        root = root->left;
      }
    }

    return successorNode;
  }
};
// @lc code=end

// Without using BST properties
// general solution for all binary tree
class Solution {
  TreeNode *successorNode;
  TreeNode *prev;

public:
  TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
    if (p->right) {
      TreeNode *leftmost = p->right;

      while (leftmost->left) {
        leftmost = leftmost->left;
      }
      successorNode = leftmost;
    } else {
      inorderCase2(root, p);
    }
    return successorNode;
  }

  void inorderCase2(TreeNode *node, TreeNode *p) {
    if (node == nullptr) {
      return;
    }

    inorderCase2(node->left, p);
    if (prev == p && successorNode == nullptr) {
      successorNode = node;
      return;
    }

    prev = node;

    inorderCase2(node->right, p);
  }
};
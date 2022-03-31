/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
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


// O(N)
class Solution {
  vector<int> res;

public:
  bool findTarget(TreeNode *root, int k) {

    res = {};
    extractData(root);
    int n = res.size();
    int l = 0, r = n - 1;
    while (l < r) {
      int sum = res[l] + res[r];
      if(sum==k)
          return true;
      
      if (sum < k)
        ++l;
      else
        --r;
    }
    return false;
  }

  void extractData(TreeNode *root) {
    if (root != nullptr) {
      extractData(root->left);
      res.push_back(root->val);
      extractData(root->right);
    }
  }
};
// @lc code=end

class SolutionSet {
  unordered_set<int> s;

public:
  bool findTarget(TreeNode *root, int k) {
    s = {};
    return findTargetRec(root, k);
  }

  bool findTargetRec(TreeNode *root, int k) {
    if (root == nullptr) {
      return false;
    }
    if (s.find(k - root->val) != s.end()) {
      return true;
    }

    s.insert(root->val);
    return findTargetRec(root->left, k) || findTargetRec(root->right, k);
  }
};
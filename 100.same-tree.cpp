/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 


// @lc code=start



class Solution {
 public:
  bool isSameTree(TreeNode *p, TreeNode *q) {}
};
// @lc code=end

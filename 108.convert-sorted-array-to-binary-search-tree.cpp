/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
  TreeNode *sortedArrayToBST(vector<int> &nums) {
      return sortedArrayToBST(nums, 0, nums.size()-1);
  }
  TreeNode *sortedArrayToBST(vector<int> &nums, int l, int r) {
    if(l>r)
        return nullptr;
    int m = l + (r - l) / 2;
    TreeNode* root = new TreeNode(nums[m]);
    root->left = sortedArrayToBST(nums, l, m-1);
    root->right = sortedArrayToBST(nums, m + 1, r);
    return root;
  }
};

// @lc code=end
int main(){
    vector<int> ivec{-10, -3, 0, 5, 9};
    Solution s;
    s.sortedArrayToBST(ivec);
    cout << "hello";
}
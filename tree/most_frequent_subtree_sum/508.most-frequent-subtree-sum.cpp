/*
 * @lc app=leetcode id=508 lang=cpp
 *
 * [508] Most Frequent Subtree Sum
 */

#include "bits/stdc++.h"

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

// NOTE:
// https://zxi.mytechroad.com/blog/tree/leetcode-508-most-frequent-subtree-sum/

// @lc code=start
class Solution {
 public:
  unordered_map<int, int> freqs;
  int max_freq = -1;
  vector<int> ans;
  vector<int> findFrequentTreeSum(TreeNode* root) {
    treeSum(root);
    return ans;
  }

  int treeSum(TreeNode* root) {
    if (!root) return 0;
    int sum = root->val + treeSum(root->left) + treeSum(root->right);

    int freq = ++freqs[sum];
    if (freq > max_freq) {
      max_freq = freq;
      ans.clear();
    }

    if (freq == max_freq) ans.push_back(sum);
    return sum;
  }
};
// @lc code=end

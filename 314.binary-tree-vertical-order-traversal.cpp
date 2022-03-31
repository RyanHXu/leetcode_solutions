/*
 * @lc app=leetcode id=314 lang=cpp
 *
 * [314] Binary Tree Vertical Order Traversal
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

// TODO: follow up, DFS way
class SolutionDFS {
 public:
  vector<vector<int>> verticalOrder(TreeNode *root) {

  }
};

// @lc code=start

// BFS + hashtable
class Solution {
 public:
  vector<vector<int>> verticalOrder(TreeNode *root) {
    // level order
    vector<vector<int>> res;
    if (root == nullptr) {
      return res;
    }

    // column, [v1,v2,v3...]
    unordered_map<int, vector<int>> columnTable;
    // TreeNode*, column
    queue<pair<TreeNode *, int>> q;
    int column = 0;
    q.push({root, column});

    int minC = 0, maxC = 0;
    TreeNode *node = nullptr;
    while (!q.empty()) {
      node = q.front().first;
      column = q.front().second;
      q.pop();

      if (node != nullptr) {
        columnTable[column].push_back(node->val);

        minC = min(minC, column);
        maxC = max(maxC, column);

        q.push({node->left, column - 1});
        q.push({node->right, column + 1});
      }
    }

    for (int i = minC; i < maxC + 1; ++i) {
      res.push_back(columnTable[i]);
    }
    return res;
  }
};
// @lc code=end

int main() {
  Solution s;
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);
  for (const auto &it : s.verticalOrder(root)) {
    for (const auto &val : it) {
      cout << val << ' ';
    }
    cout << endl;
  }
  cout << endl;
}
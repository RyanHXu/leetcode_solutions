/*
 * @lc app=leetcode id=965 lang=cpp
 *
 * [965] Univalued Binary Tree
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


// recursive
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        return isUnivalTreeHelper(root, root->val);
    }

    bool isUnivalTreeHelper(TreeNode* root, int univalue){
        if(!root){
            return true;
        }

        return root->val == univalue && isUnivalTreeHelper(root->left, univalue) && isUnivalTreeHelper(root->right, univalue);
    }
};
// @lc code=end


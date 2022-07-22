/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */
#include "bits/stdc++.h"

using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/discuss/608304/C%2B%2B-solution-using-queue-and-preorder-traversal



// TODO:
// https://zxi.mytechroad.com/blog/tree/leetcode-297-serialize-and-deserialize-binary-tree/

// @lc code=start

class Codec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
      if(!root){
          return "null,";
      }
      return to_string(root->val)+","+serialize(root->left)+serialize(root->right);
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
      queue<string> q;
      string s;
      for (int i = 0; i < data.size(); ++i) {
        if(data[i]==','){
            q.push(s);
            s = "";
            continue;
        }
        s += data[i];
      }
      if(s.size() !=0)
          q.push(s);
      return deserializeHelper(q);
  }

  TreeNode *deserializeHelper(queue<string> &q){
      string s = q.front();
      q.pop();
      if(s=="null"){
          return nullptr;
      }
      TreeNode *root = new TreeNode(stoi(s));
      root->left = deserializeHelper(q);
      root->right = deserializeHelper(q);
      return root;
  }
};



// @lc code=end

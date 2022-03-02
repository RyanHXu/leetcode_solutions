#include "bits/stdc++.h"

using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class FullTree {
public:
  bool isFullTree(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }
    if (root->left == nullptr && root->right == nullptr) {
      return true;
    }

    if (root->left && root->right) {
      return isFullTree(root->left) && isFullTree(root->right);
    }
    return false;
  }
};


// A Perfect Binary Tree of height h (where height is number of nodes on path from root to leaf) has 2h – 1 nodes.
// Below is an idea to check whether a given Binary Tree is perfect or not.  

// Find depth of any node (in below tree we find depth of leftmost node). Let this depth be d.
// Now recursively traverse the tree and check for following two conditions. 
// Every internal node should have both children non-empty
// All leaves are at depth ‘d’
class PerfectTree {
public:
  bool isPerfectTree(TreeNode *root) {
    int d = depth(root);
    return isPerfect(root, d);
  }

  bool isPerfect(TreeNode *root, int d, int level = 0) {
    if (root == nullptr) {
      return true;
    }
    if (root->left == nullptr && root->right == nullptr) {
      return (d == level + 1);
    }
    if (root->left == nullptr || root->right == nullptr) {
      return false;
    }
    return isPerfect(root->left, d, level + 1) &&
           isPerfect(root->right, d, level + 1);
  }

  // return potential longgest death
  int depth(TreeNode *root) {
    int d = 0;
    while (root) {
      ++d;
      root = root->left;
    }
    return d;
  }
};


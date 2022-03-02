#include "bits/stdc++.h"

// https://www.programiz.com/dsa/complete-binary-tree

using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class CompleteTree {
public:
  int countNodes(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
  bool isComplete(TreeNode *root, int idx, int n) {
    if (root == nullptr) {
      return true;
    }
    if (idx >= n) {
      return false;
    }

    return isComplete(root->left, idx * 2 + 1, n) &&
           isComplete(root->right, idx * 2 + 2, n);
  }


  bool isComplete(TreeNode *root) {
    int count = countNodes(root);
    return isComplete(root, 0,count);
  }
};

class CompleteTree2 {
public:
  bool isComplete(TreeNode *root) {
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

// A Perfect Binary Tree of height h (where height is number of nodes on path
// from root to leaf) has 2h – 1 nodes.

// Find depth of any node (in below tree we find depth of leftmost node). Let
// this depth be d. Now recursively traverse the tree and check for following
// two conditions.
//    Every internal node should have both children non-empty
//    All leaves are at depth ‘d’
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

class BalancedBinaryTree{
  public:
  bool isBalanced(TreeNode* root){
    if(root==nullptr){
      return true;
    }
    int l = 1 + isBalanced(root->left);
    int r = 1 + isBalanced(root->right);
    if(abs(l-r)<=1){
      return true;
    }else{
      return false;
    }
  }
}

class TreeTraversal {

public:
  void preOrder(TreeNode *root) {
    if (root == nullptr) {
      return;
    }
    cout << root->val << ' ';
    preOrder(root->left);
    preOrder(root->right);
  }

  void inOrder(TreeNode *root) {
    if (root == nullptr) {
      return;
    }
    preOrder(root->left);
    cout << root->val << ' ';
    preOrder(root->right);
  }
  void postOrder(TreeNode *root) {
    if (root == nullptr) {
      return;
    }
    preOrder(root->left);
    preOrder(root->right);
    cout << root->val << ' ';
  }
};

// create node with queue
TreeNode *initTree(vector<int> ivec) {
  if (ivec.empty()) {
    return nullptr;
  }
  int n = ivec.size();
  // q used for store partents
  queue<TreeNode *> q({new TreeNode(ivec.front())});

  TreeNode *root = q.front();
  TreeNode *t;
  int i = 1;
  while (!q.empty()) {
    t = q.front();
    q.pop();

    // left child
    if (i < n) {
      if (ivec[i] != INT32_MIN) {
        t->left = new TreeNode(ivec[i]);
        q.push(t->left);
      } else {
        t->left = nullptr;
      }
      ++i;
    }

    // right child
    if (i < n) {
      if (ivec[i] != INT32_MIN) {
        t->right = new TreeNode(ivec[i]);
        q.push(t->right);
      } else {
        t->right = nullptr;
      }
      ++i;
    }
  }
  return root;
}

int main() {
  TreeNode *root = initTree({1, 2, 3, 4, 5,6,7});

  TreeTraversal tt;
  tt.preOrder(root);
  cout << endl;
  tt.inOrder(root);
  cout << endl;
  tt.postOrder(root);
  cout << endl;

  CompleteTree c;
  CompleteTree2 c2;
  if(c.isComplete(root)){
    cout << "is complete tree" << endl;
  }
  if(c2.isComplete(root)){
    cout << "is complete tree" << endl;
  }
}
#include "bits/stdc++.h"

// https://www.programiz.com/dsa/complete-binary-tree

// http://typeocaml.com/2014/11/26/height-depth-and-level-of-a-tree/

// Level: The number of edges between the root and a given node. The root can be
// considered level 0 or level 1. If it is level 0, then the level is the number
// of edges. If it is level 1, then add 1 to the number of edges.

// Depth: The number of edges from a given node to the root.

// Height: The number of edges on the longest path from a given node to a leaf.

using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

struct AVLNode : TreeNode {
  int height;
  AVLNode(int h) : height(h){};
  AVLNode(int x, int h) : height(h) {
    val = x;
    left = nullptr;
    right = nullptr;
  };

  AVLNode(int x, AVLNode *left, AVLNode *right, int h) : height(h) {
    val = x;
    left = left;
    right = right;
  };
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

  bool isCompleteTree(TreeNode *root) {
    int count = countNodes(root);
    return isComplete(root, 0, count);
  }
};

class CompleteTree2 {
public:
  bool isCompleteTree(TreeNode *root) {
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

class BalancedBinaryTree {
public:
  bool isBalanced(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }
    int l = 1 + isBalanced(root->left);
    int r = 1 + isBalanced(root->right);
    if (abs(l - r) <= 1) {
      return true;
    } else {
      return false;
    }
  }
};

class TreeTraversal {

public:
  int maxHeight(TreeNode *root) {
    if (root == nullptr) {
      return -1;
    }

    return 1 + max(maxHeight(root->left), maxHeight(root->right));
  }
  int maxLevel(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    return 1 + max(maxLevel(root->left), maxLevel(root->right));
  }
  int depth(TreeNode *root, int key) {
    if (root == nullptr) {
      return -1;
    }
    int dist = -1;
    if (root->val == key || (dist = depth(root->left, key)) >= 0 ||
        (dist = depth(root->right, key)) >= 0) {
      return dist + 1;
    }
    return dist;
  }
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
    inOrder(root->left);
    cout << root->val << ' ';
    inOrder(root->right);
  }
  void postOrder(TreeNode *root) {
    if (root == nullptr) {
      return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << ' ';
  }
  void levelOrder(TreeNode *root) {
    if (root == nullptr) {
      return;
    }
    queue<TreeNode *> q({root});
    TreeNode *curr;
    while (!q.empty()) {
      curr = q.front();
      q.pop();
      cout << curr->val << ' ';
      if (curr->left) {
        q.push(curr->left);
      }
      if (curr->right) {
        q.push(curr->right);
      }
    }
    cout << endl;
  }
  void inOrderStack(TreeNode *root) {
    if (root == nullptr) {
      return;
    }
    vector<TreeNode *> s({root});
    TreeNode *curr = root;
    curr = curr->left;

    while (!s.empty() || curr != nullptr) {
      while (curr != nullptr) {
        s.push_back(curr);
        curr = curr->left;
      }
      curr = s.back();
      s.pop_back();
      cout << curr->val << ' ';
      curr = curr->right;
    }
    cout << endl;
  }
  void preOrderStack(TreeNode *root) {
    if (root == nullptr) {
      return;
    }

    vector<TreeNode *> s({root});
    TreeNode *curr;
    while (!s.empty()) {
      curr = s.back();
      cout << curr->val << ' ';
      s.pop_back();

      // cause this is stack, push right first, pop right later

      if (curr->right) {
        s.push_back(curr->right);
      }
      if (curr->left) {
        s.push_back(curr->left);
      }
    }
    cout << endl;
  }

  // https://leetcode.com/problems/binary-tree-postorder-traversal/discuss/45648/three-ways-of-iterative-postorder-traversing-easy-explanation

  // https://www.geeksforgeeks.org/iterative-postorder-traversal/
  // https://www.geeksforgeeks.org/iterative-postorder-traversal-using-stack/
  // a little bit tricky
  void postOrderTwoStack(TreeNode *root) {
    if (root == nullptr) {
      return;
    }
    vector<TreeNode *> s1, s2;
    TreeNode *curr;
    s1.push_back(root);
    while (!s1.empty()) {
      curr = s1.back();
      s1.pop_back();
      s2.push_back(curr);
      if (curr->left) {
        s1.push_back(curr->left);
      }
      if (curr->right) {
        s1.push_back(curr->right);
      }
    }

    while (!s2.empty()) {
      curr = s2.back();
      s2.pop_back();
      cout << curr->val << ' ';
    }
    cout << endl;
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

class BST {
public:
  TreeNode *insertNode(TreeNode *root, int data) {
    if (root == nullptr) {
      return (new TreeNode(data));
    }
    if (data < root->val)
      root->left = insertNode(root->left, data);
    else
      root->right = insertNode(root->right, data);
    return root;
  }

  TreeNode *constructBST(vector<int> ivec) {
    if (ivec.size() == 0) {
      return nullptr;
    }
    TreeNode *root = nullptr;
    for (int i = 0; i < ivec.size(); ++i) {
      root = insertNode(root, ivec[i]);
    }
    return root;
  }

  TreeNode *find(TreeNode *root, int key) {
    if (root == nullptr || root->val == key) {
      return root;
    }
    if (root->val > key) {
      return find(root->left, key);
    }
    return find(root->right, key);
  }

  // find inorder successor && min value node
  TreeNode *deleteNodeHelper(TreeNode *root) {
    auto curr = root;
    while (curr && curr->left != nullptr) {
      curr = curr->left;
    }
    return curr;
  }
  /**
   * key doesn't exist, do nothing
   * key exist,
   *    key is a leaf
   *    key has one child
   *    key has two child
   */
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (root == nullptr)
      return root;
    if (key < root->val) {
      root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
      root->right = deleteNode(root->right, key);
    } else {
      // found the key
      // and has 0 or 1 child
      if (root->left == nullptr) {
        auto temp = root->right;
        return temp;
      } else if (root->right == nullptr) {
        auto temp = root->left;
        return temp;
      }
      // found two children
      auto temp = deleteNodeHelper(root->right);
      root->val = temp->val;
      root->right = deleteNode(root->right, temp->val);
    }
    return root;
  }
};

int main() {
  TreeNode *root = initTree({1, 2, 3, 4, 5, 6, 7, 8, 9});

  TreeTraversal tt;
  cout << "preOrder" << endl;
  tt.preOrder(root);
  cout << endl;
  tt.preOrderStack(root);

  cout << "inOrder" << endl;
  tt.inOrder(root);
  cout << endl;
  tt.inOrderStack(root);
  cout << "postOrder" << endl;
  tt.postOrderTwoStack(root);

  tt.postOrder(root);
  cout << endl;

  cout << "level Order" << endl;
  tt.levelOrder(root);
  cout << "max height" << endl;
  cout << tt.maxHeight(root) << endl;
  cout << "depth" << endl;
  cout << tt.depth(root, 8) << endl;

  cout << "max level" << endl;
  cout << tt.maxLevel(root) << endl;

  CompleteTree c;
  CompleteTree2 c2;
  PerfectTree p;
  FullTree f;
  if (c.isCompleteTree(root)) {
    cout << "is complete tree" << endl;
  }
  if (c2.isCompleteTree(root)) {
    cout << "is complete tree" << endl;
  }
  if (p.isPerfectTree(root)) {
    cout << "is perfect tree" << endl;
  }
  if (f.isFullTree(root)) {
    cout << "is full tree" << endl;
  }

  BST b;
  TreeNode *bst = b.constructBST(
      {8, 3, 10, 1, 6, INT32_MIN, 14, INT32_MIN, INT32_MIN, 4, 7});
  b.deleteNode(bst, 3);
  tt.levelOrder(bst);
}
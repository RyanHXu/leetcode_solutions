#include "bits/stdc++.h"

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


int main(){

}
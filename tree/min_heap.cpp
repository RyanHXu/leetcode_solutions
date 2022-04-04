#include "bits/stdc++.h"
using namespace std;

class MinHeap {
 private:
 public:
  vector<int> heap;

  MinHeap(){};

  // 1 2 3 4 5 6 7
  // return the index of current node's parent, return -1 if the node is root
  int getParent(int index) {
    if (getHeapSize() > 1) {
      return (index - 1) / 2;
    } else {
      return -1;
    }
  }

  // return the index of current node's left child, return -1 if the node is
  // leaf
  int getLeftChild(int index) {
    int lc_index = index * 2 + 1;
    if (lc_index < getHeapSize()) {
      return index * 2 + 1;
    } else {
      return -1;
    }
  }

  // return the index of current node's right child, return -1 if the node is
  // leaf
  int getRightChild(int index) {
    int rc_index = index * 2 + 2;
    if (rc_index < getHeapSize()) {
      return rc_index;
    } else {
      return -1;
    }
  }

  int getHeapSize() { return heap.size(); }
  int top() { return heap[0]; }

  void push(int val) {
    heap.push_back(val);
    percolate_up(getHeapSize() - 1);
  }

  int pop() {
    swap(heap.front(), heap.back());
    int popped_item = heap.back();
    heap.pop_back();

    percolate_down(0);
    return popped_item;
  }

  void percolate_up(int index) {
    int parentIndex = getParent(index);
    while (parentIndex != -1 && heap[index] < heap[parentIndex]) {
      swap(heap[index], heap[parentIndex]);
      index = parentIndex;
      parentIndex = getParent(parentIndex);
    }
  }
  void percolate_down(int index) {
    int leftChild = getLeftChild(index);
    int rightChild = getRightChild(index);

    // root has left child
    if (leftChild != -1) {
      if (rightChild == -1) {
        if (heap[index] > heap[leftChild]) {
          swap(heap[index], heap[leftChild]);
        }
        // root has right child
      } else {
        if (heap[index] > heap[leftChild] || heap[index] > heap[rightChild]) {
          if (heap[leftChild] < heap[rightChild]) {
            swap(heap[leftChild], heap[index]);
            percolate_down(leftChild);
          } else {
            swap(heap[rightChild], heap[index]);
            percolate_down(rightChild);
          }
        }
      }
    }
  }
};

class MaxHeap {};

int main() {
  MinHeap minHeap;

  minHeap.heap;
  for (int i = 10; i > 0; --i) {
    minHeap.push(i);
  }

  // 1 2 3 4 5 6 7 8 9 10 
  for (int i = 0; i < 10; ++i) {
    cout << minHeap.pop() << ' ';
  }
  cout << endl;
}
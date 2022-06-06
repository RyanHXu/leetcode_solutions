/*
 * @lc app=leetcode id=716 lang=cpp
 *
 * [716] Max Stack
 */

#include "bits/stdc++.h"

using namespace std;

/**
 * for 2,1,5,3,9
 * we will remember 2,2,5,5,9
 *
 */

// @lc code=start
class MaxStack {
  stack<int> s, max_s;

 public:
  MaxStack() {}

  void push(int x) {
    int max = max_s.empty() ? x : max_s.top();
    max_s.push(max > x ? max : x);
    s.push(x);
  }

  int pop() {
    int topElement = s.top();
    max_s.pop();
    s.pop();

    return topElement;
  }

  int top() { return s.top(); }

  int peekMax() { return max_s.top(); }

  // O(N)
  int popMax() {
    int maxElemnt = max_s.top();
    stack<int> buffer;
    while (top() != maxElemnt) {
      buffer.push(pop());
    }
    pop();

    while (!buffer.empty()) {
      push(buffer.top());
      buffer.pop();
    }
    return maxElemnt;
  }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
// @lc code=end

int main() {
  MaxStack maxStack;
  maxStack.push(5);
  maxStack.push(1);

  cout << maxStack.popMax() << endl;
  cout << maxStack.peekMax() << endl;
}

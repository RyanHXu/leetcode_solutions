/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

#include "bits/stdc++.h"

using namespace std;

// https://leetcode.com/problems/min-stack/solution/

// @lc code=start
class MinStack {
public:
    stack<int> s, min_s;

    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(min_s.empty() ||  min_s.top() >= val){
            min_s.push(val);
        }
    }
    
    void pop() {
        if(!min_s.empty() && s.top() == min_s.top()){
            min_s.pop();
        }

        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return min_s.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end


int main(){
    MinStack minStack;
    // ✅ Because this porblem guarantee `There will be at least one element in the stack when pop, top, peekMax, or popMax is called`, so we don't need to worry about pop() on empty stack
    // minStack.push(-2);
    // minStack.push(0);
    // minStack.push(-3);
    // minStack.pop();
    // minStack.pop();
    // minStack.pop();
    // minStack.pop();
    // cout << minStack.getMin() << endl;

}

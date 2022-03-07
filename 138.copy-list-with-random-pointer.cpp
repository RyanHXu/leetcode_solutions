/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

#include "bits/stdc++.h"

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
// @lc code=start

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head ==nullptr){
            return head;
        }


       
    }
};
// @lc code=end


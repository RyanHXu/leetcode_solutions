/*
 * @lc app=leetcode id=1209 lang=cpp
 *
 * [1209] Remove All Adjacent Duplicates in String II
 */
#include "bits/stdc++.h"

using namespace std;

// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/solution/

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<int> counts;
        for (int i = 0; i < s.size(); ++i) {
          if(i==0 || s[i]!=s[i-1]){
              counts.push(1);
          }else if(++counts.top() == k){
              counts.pop();
              s.erase(i - k + 1, k);
              i = i - k;
          }
        }
        return s;
    }
};
// @lc code=end


int main(){
  

}


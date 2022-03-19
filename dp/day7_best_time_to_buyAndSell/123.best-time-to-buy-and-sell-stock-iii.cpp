/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    int peak = 0, valley = 0;
    int maxP = 0;
    int i = 0;
    priority_queue<int> pq;
    vector<int> records;
    while (i < n - 1)
    {
      // find valley first
      while (i < n - 1 && prices[i] >= prices[i + 1]) {
        ++i;
      }
      // update valley
      valley = prices[i];
      pq.push(valley);

      // then find peak
      while (i < n - 1 && prices[i] <= prices[i + 1]) {
        records.push_back(prices[i]);
        ++i;
      }
      
      // update peak
      peak = prices[i];

      // update priority_queue
      for (const auto& val : records) {
        pq.push(peak - val);
      }
    }

    int count = 0;
    int res = 0;
    while (pq.size() > 0 && count < 2) {
      res += pq.top();
      pq.pop();
      ++count;
    }

    return res;
  }
};
// @lc code=end

// FIXME: corner case throw error, should be 13, but we got 12
// vector<int> ivec2{1, 2, 4, 2, 5, 7, 2, 4, 9, 0};
// cout << s.maxProfit(ivec2) << endl;
class Solution2 {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    int peak = 0, valley = 0;
    int maxP = 0;
    int i = 0;
    priority_queue<int> pq;
    while (i < n - 1) {
      // find valley first
      while (i < n - 1 && prices[i] >= prices[i + 1]) {
        ++i;
      }
      // update valley
      valley = prices[i];

      // then find peak
      while (i < n - 1 && prices[i] <= prices[i + 1]) {
        ++i;
      }

      // update peak
      peak = prices[i];

      pq.push(peak - valley);
    }

    int count = 0;
    int res = 0;
    while (pq.size() > 0 && count < 2) {
      res += pq.top();
      pq.pop();
      ++count;
    }

    return res;
  }
};

int main() {
  Solution2 s;
//   vector<int> ivec{1, 2, 3, 4, 5};
//   cout << s.maxProfit(ivec) << endl;

  // buy 1, sell at 7, buy 2, sell at 9
  vector<int> ivec2{1, 2, 4, 2, 5, 7, 2, 4, 9, 0};
  cout << s.maxProfit(ivec2) << endl;



  return 0;
}

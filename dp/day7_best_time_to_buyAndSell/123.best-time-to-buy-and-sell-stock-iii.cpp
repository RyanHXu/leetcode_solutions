/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start

// divide and conquer, O(N*N)
// we can use 2 vector to optimal results.
// bidirectional dp O(N), O(N)
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    if (n <= 1)
      return 0;
    int lMin = prices[0];
    int rMax = prices[n - 1];

    vector<int> lProfits(n, 0);
    // pad the right DP array with an additional zero for convenience.
    vector<int> rProfits(n+1, 0);

    // 
    // l start from second index 
    // r start from the second to the last
    for (int l = 1; l < n; ++l) {
      lProfits[l] = max(lProfits[l - 1], prices[l] - lMin);
      lMin = min(lMin, prices[l]);

      int r = n - 1 - l;
      rProfits[r] = max(rProfits[r + 1], rMax - prices[r]);
      rMax = max(rMax, prices[r]);
    }

    int maxP = 0;
    for (int i = 1; i < n; ++i) {
      maxP = max(maxP, lProfits[i] + rProfits[i+1]);
    }

    return maxP;
  }
};
// @lc code=end




// vector<int> ivec2{1, 2, 4, 2, 5, 7, 2, 4, 9, 0};
// one pass
// TODO: review it again
class Solution2 {
public:
  int maxProfit(vector<int> &prices) {
    int firstTransCost = prices[0];

    int firstTransProfit = 0;
    int mostMoneyInPocket = -prices[0];
    int profitFromTwoTrans = 0;

    for (int price : prices) {
      firstTransCost = min(firstTransCost, price);
      firstTransProfit = max(firstTransProfit, price - firstTransCost);

      mostMoneyInPocket = max(mostMoneyInPocket, firstTransProfit - price);
      profitFromTwoTrans = max(profitFromTwoTrans, mostMoneyInPocket + price);
    }

    return profitFromTwoTrans;
  }
};

// FIXME: corner case throw error, should be 13, but we got 12
// vector<int> ivec2{1, 2, 4, 2, 5, 7, 2, 4, 9, 0};
// buy 1, sell at 7, buy 2, sell at 9
// cout << s.maxProfit(ivec2) << endl;
class Solution3 {
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
  Solution s;
  //   vector<int> ivec{1, 2, 3, 4, 5};
  //   cout << s.maxProfit(ivec) << endl;

  // vector<int> ivec2{1, 2, 4, 2, 5, 7, 2, 4, 9, 0};
  // cout << s.maxProfit(ivec2) << endl;

  vector<int> ivec3{0, 3, 1, 4};
  cout << s.maxProfit(ivec3) << endl;

  return 0;
}

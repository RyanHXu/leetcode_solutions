// Q2. Given an unsorted array of numbers of size n that represents weights of
// products, n <= 10^5, and a number k. Find all subarrays such that have max -
// min < k. For example arr = [1,3,7] and k = 2. Answer should be [[1], [3],
// [7], [1,3]], bec

#include "bits/stdc++.h"

using namespace std;

// find all subset of ivec
// erase nullset
// move correct subset from res to ans
// return ans
// brute force
vector<vector<int>> solution(vector<int> ivec, int k) {
    vector<vector<int>> res{{}};
    vector<vector<int>> ans{};
    sort(ivec.begin(),ivec.end());
    for (const auto val : ivec) {
        int n = res.size();
        for (int i = 0; i < n; ++i) {
          auto temp =  res[i];
          temp.push_back(val);
          res.push_back(temp);
        }
    }
    res.erase(res.begin());
    for (auto it : res) {
      if(*max_element(it.begin(),it.end()) - *min_element(it.begin(),it.end())<=k){
          ans.push_back(move(it));
      }
    }

    return res;

}

int main() { 
    
    vector<int> ivec{1, 3, 7};
    solution(ivec, 2);


}

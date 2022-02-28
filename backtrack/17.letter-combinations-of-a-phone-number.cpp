/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */
#include "bits/stdc++.h"

using namespace std;

// NOTE: this kind of problem usually have two solutions - backtrack and interative
// @lc code=start
class Solution {

private:
public:
  vector<string> letterCombinations(string digits) {
    if(digits == "") return {};
	vector<string> mappings{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, ans{""};
	for(auto digit : digits){
		vector<string> extendCombination;
		for(auto& currentCombination : ans)
			for(auto newChar : mappings[digit - '2'])
				extendCombination.push_back(currentCombination + newChar);                            
		ans = move(extendCombination); // same as ans = extendCombination, just avoids copying each value. You Can also use swap(ans,extendCombination)
	}
	return ans;
    
  }
};
// @lc code=end

class Solution2 {

private:
  unordered_map<char, string> m = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                                   {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                                   {'8', "tuv"}, {'9', "wxyz"}};
  int n;
  vector<string> res;
  string phoneDigits;

public:
  vector<string> letterCombinations(string digits) {
    n = digits.size();
    if (n == 0) {
      return {};
    }
    phoneDigits = digits;
    backtrack(0, "");
    return res;
  }

  void backtrack(int index, string s) {
    if (s.size() == n) {
      res.push_back(s);
      return;
    }
    string possibleLetters = m[phoneDigits[index]];
    for (const auto val : possibleLetters) {
      s += val;
      backtrack(index + 1, s);
      s.pop_back();
    }
  }
};

int main(){
    Solution s;

    for (const auto val : s.letterCombinations("23")) {
        cout << val << ',';
    }
    cout << endl;
}
/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
// hashmap + 
class TimeMap {
 public:
     unordered_map<string, map<int, string>> m;
     TimeMap() {}

     void set(string key, string value, int timestamp) {
         m[key].insert({timestamp,value});
     }

     string get(string key, int timestamp) {
         auto it = m[key].upper_bound(timestamp);
         // if it equal to begin, it means m[key] is empty
         // prev(it) return (timestamp_prev <= timestamp)'s value
         return it == m[key].begin() ? "" : prev(it)->second;
     }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end

// Test for map and unordered_map
int main(int argc, char const* argv[]) {
  map<int, string> m;
  m[3] = "hello3";
  m[4] = "hello4";
  m[1] = "hello1";
  m[2] = "hello2";

  for (const auto& val : m) {
    cout << val.second << endl;
  }
  // prev()
  cout << prev(end(m))->second << endl;

  map<int, string> m2;
  if(m2.begin() == m2.end())
      cout << "empty" << endl;
  return 0;
}

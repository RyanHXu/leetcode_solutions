/*
 * @lc app=leetcode id=253 lang=cpp
 *
 * [253] Meeting Rooms II
 */


#include "bits/stdc++.h"

using namespace std;

/**
Similar Problems

Problem 1: Given a list of intervals, find the point where the maximum number of intervals overlap.

Problem 2: Given a list of intervals representing the arrival and departure times of trains to a train station, our goal is to find the minimum number of platforms required for the train station so that no train has to wait.
 * 
 */


// @lc code=start
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int rooms = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (const auto& val : intervals) {
          if(!pq.empty() && pq.top() <= val[0]){
              pq.pop();
          }

          pq.push(val[1]);
          rooms = max(rooms, (int)pq.size());
        }

        return rooms;
    }
};
// @lc code=end





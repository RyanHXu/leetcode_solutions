import java.util.HashMap;
import java.util.Map;

/*
 * @lc app=leetcode id=1 lang=java
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
  public int[] twoSum(int[] nums, int target) {
    Map<Integer, Integer> map = new HashMap<>();
    for (int i = 0; i < nums.length; i++) {
      int complement = target - nums[i];
      // if we didn't find a complement yet, add the current number to the map
      if (!map.containsKey(complement)) {
        map.put(nums[i], i);
      } else {
        return new int[] {map.get(complement), i};
      }
    }
    return null;
  }
}
// @lc code=end



// naive solution
// class Solution {
//   public int[] twoSum(int[] nums, int target) {
//     for (int i = 0; i < nums.length; i++) {
//       for (int j = i + 1; j < nums.length; j++) {
//         if (nums[i] + nums[j] == target) {
//           return new int[] {i, j};
//         }
//       }
//     }

//     return null;
//   }
// }

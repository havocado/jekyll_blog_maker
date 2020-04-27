/*
This code is an accepted solution to:
https://leetcode.com/problems/wiggle-subsequence/
Leetcode #376
Difficulty: Medium
*/
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        int count = 1;
        bool started = (nums[0] != nums[1]);
        if (started) {
            count++;
        }
        bool increased = (nums[0] < nums[1]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] == nums[i]) {
                continue;
            }
            if (!started || increased != (nums[i-1] < nums[i])) {
                increased = (nums[i-1] < nums[i]);
                count++;
            }
        }
        return count;
    }
};

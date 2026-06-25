/*
16. 3Sum Closest
Given an integer array nums of length n and an integer target, find three integers at distinct indices in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 

Constraints:

3 <= nums.length <= 500
-1000 <= nums[i] <= 1000
-104 <= target <= 104

Time Complexity: O(nlogn) + O(n*m)
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest_sum = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size() - 2; i++)
        {
            int j = i + 1, k = nums.size() - 1;
            while(j < k)
            {
                int current_sum = nums[i] + nums[j] + nums[k];
                if( abs(target - current_sum) < abs(target - closest_sum))
                {
                    closest_sum = current_sum;
                }
                if( current_sum < target)
                {
                    j++;
                }
                else if(current_sum > target)
                {
                    k--;
                }
                else{
                    return target;
                }
            }
        }
        return closest_sum;
    }
};

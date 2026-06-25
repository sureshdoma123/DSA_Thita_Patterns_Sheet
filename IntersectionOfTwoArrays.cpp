/*
349. Intersection of Two Arrays
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000

Time Complexity: n1logn(n1) + n2log(n2) + large(n1, n2) * log(n)
*/

class Solution {
public:
    vector<int> getInterSectionValues(vector<int>& small, vector<int>& large)
    {
        vector<int> result;
        sort(small.begin(), small.end());
        sort(large.begin(), large.end());
        for(int i = 0; i < small.size(); i++)
        {
            if( i > 0 && small[i] == small[i-1]) continue;
            int left = 0, right = large.size() - 1;
            while(left <= right)
            {
                int middle = (left + right) / 2;
                if(large[middle] < small[i]){
                    left = middle + 1;
                }
                else if(large[middle] > small[i]){
                    right = middle - 1;
                }
                else{
                    result.emplace_back(small[i]);
                    break;
                }
            }
        }
        return result;
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if( nums1.size() < nums2.size()) return getInterSectionValues(nums1, nums2);
        else return getInterSectionValues(nums2, nums1);
    }
};

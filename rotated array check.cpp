// leetcode link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description
/* Approach: For a rotated array there will be only one break point (arr[x]>arr[x+1]) and for sorted array number of break points will be zero*/
// Time Complexity : O(n)

class Solution {
public:
    bool check(vector<int>& nums) {
        int count =0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>nums[(i+1)%nums.size()])
            {
                count++;
            }
            if(count>1)
            {
                return false;
            }
        }
        return count<=1;
    }
};